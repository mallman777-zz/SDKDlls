# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 13:19:27 2017

@author: mallman
"""
import DH
import frame
import SDK
import numpy as np
import math as m
import os

def getFirstNonZeroIdx(p1, p2):
  if p1 ==  p2:
    return 0
  else:
    a = tuple(np.subtract(p1, p2))
    return next((i for i,x in enumerate(a) if x), None)

degToRad = (np.pi/180)

class robot(object):
  def __init__(self, rCol, Nrk, kind, *homePose, **params):
    self.base = None
    if 'base' in params.keys():
      self.base = params['base']
    self.Tbase = np.diag(np.ones(4, dtype = np.double))
    self.setTbase()
    self.tool = None
    if 'tool' in params.keys():
      self.tool = params['tool']
    if 'ID' in params.keys():
      self.ID = params['ID']
    self.DHparams = None
    if 'DH' in params.keys():
      self.DHparams = params['DH']
    self.col = rCol
    self.linkFrames = {}
    self.nrk = Nrk
    self.currPose = None
    self.homePose = homePose
    self.kind = kind
    self.genRobot()
    self.jointLimits = []
    
  def setTbase(self):
    if not (self.base is None):
      X = self.base['X']
      Y = self.base['Y']
      Z = self.base['Z']
      rX = self.base['Rx']*degToRad
      rY = self.base['Ry']*degToRad
      rZ = self.base['Rz']*degToRad
      self.Tbase = np.array([[m.cos(rZ)*m.cos(rY), m.cos(rZ)*m.sin(rY)*m.sin(rX) - m.sin(rZ)*m.cos(rX), m.cos(rZ)*m.sin(rY)*m.cos(rX) + m.sin(rZ)*m.sin(rX), X],
                        [m.sin(rZ)*m.cos(rY), m.sin(rZ)*m.sin(rY)*m.sin(rX) + m.cos(rZ)*m.cos(rX), m.sin(rZ)*m.sin(rY)*m.cos(rX) - m.cos(rZ)*m.sin(rX), Y],
                        [-m.sin(rY), m.cos(rY)*m.sin(rX), m.cos(rY)*m.cos(rX), Z],
                        [0, 0, 0, 1]])
    
  def genRobot(self):
    jList = ['S', 'L', 'U', 'R', 'B', 'T', 'F']
    #Tw = np.diag(np.ones(4, dtype = np.double))
    Tw = self.Tbase
    params = {'col': self.col, 'name': 'base', 'TWold': Tw}
    self.nrk.ConstructFrame(self.col, 'base', Tw)
    #self.nrk.SetWorkingFrame(self.col, 'base')
    self.linkFrames['base'] = frame.frame(**params)
    for j in range(len(self.DHparams)):
      if self.kind == 'SA':
        Tcurr = DH.getTCraig2(self.homePose[j], **self.DHparams[jList[j]])
      else:
        Tcurr = DH.getTSaha2(self.homePose[j], **self.DHparams[jList[j]])
      Tw = np.matmul(Tw,Tcurr)
      params['name'] = jList[j]
      params['TWorld'] = Tw
      self.linkFrames[jList[j]] = frame.frame(**params)
      self.nrk.ConstructFrame(self.col, jList[j], Tw)  # If use Tw here instead of Tcurr, dont have to do SetWorkingFrame Operations
      #self.nrk.SetWorkingFrame(self.col, jList[j])
    #self.nrk.SetWorkingFrame("A", "World")
    self.currPose = self.homePose
    
  def setPose(self, *pose):
    jList = ['S', 'L', 'U', 'R', 'B', 'T', 'F']
    start = getFirstNonZeroIdx(pose, self.currPose)
    #print('start: ', jList[start])
    Tw = self.Tbase
    if start != 0:
      Tw = self.linkFrames[jList[start - 1]].getTWorld()
    fList = [self.linkFrames[jList[i]] for i in range(start, len(self.DHparams))]
    self.nrk.DeleteObjects(fList)
    for i in range(start, len(self.DHparams)):
      if self.kind == 'SA':
        Tw = np.matmul(Tw, DH.getTCraig2(pose[i], **self.DHparams[jList[i]]))
      else:
        Tw = np.matmul(Tw, DH.getTSaha2(pose[i], **self.DHparams[jList[i]]))
      #self.nrk.DeleteObjects([self.linkFrames[jList[i]]])
      self.nrk.ConstructFrame(self.col, jList[i], Tw)
      self.linkFrames[jList[i]].setTWorld(Tw)
    self.currPose = pose
  
  def moveBase(self, **base):
    self.base = base
    self.setTbase()
    self.nrk.DeleteObjects([self.linkFrames['base']])
    self.nrk.ConstructFrame(self.col, self.linkFrames['base'].Name, self.Tbase)
    self.setPose(*self.currPose)
    self.linkFrames['base'].setTWorld(self.Tbase)
  
  def killRobot(self):
    self.nrk.DeleteCollection(self.col)
        
if __name__ == "__main__":
  
  chi = 1.01
  Ssa = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Lsa = {'alpha':90, 'A': 140, 'D': 0}
  Usa = {'alpha':0, 'A': 1150, 'D': 0}
  Rsa = {'alpha':90, 'A': 210, 'D': 1225}
  Bsa = {'alpha':90, 'A': 0, 'D': 0}
  Tsa = {'alpha':-90,'A': 0, 'D': 0}
  Fsa = {'alpha':0, 'A': 0, 'D': 175}
  
  Smm = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Lmm = {'alpha':90, 'A': 140, 'D': 0}
  Umm = {'alpha':0, 'A': 1150, 'D': 0}
  Rmm = {'alpha':90, 'A': 210, 'D': 0}
  Bmm = {'alpha':-90, 'A': 0, 'D': 1225}
  Tmm = {'alpha':90,'A': 0, 'D': 0}
  Fmm = {'alpha':0, 'A': 0, 'D': 175}
  
  homePoseSA = (0,90,0,0,90,0,0)
  homePoseMM = (0,0,90,0,0,-90,0)
  dhParamsSA = {'S': Ssa, 'L': Lsa, 'U': Usa, 'R': Rsa, 'B': Bsa, 'T': Tsa, 'F': Fsa}
  dhParamsMM = {'S': Smm, 'L': Lmm, 'U': Umm, 'R': Rmm, 'B': Bmm, 'T': Tmm, 'F': Fmm}
  path = "C:\\Users\\mallman\\Documents\\git\\SDKDlls\\SDKMFC2015\\Release"
  dllFile = "SDKMFC2015.dll"
  NrkSDK = SDK.SDKlib(os.path.join(path, dllFile))
  NrkSDK.connToSA()
  rSA = robot('rColSA', NrkSDK, 'SA', *homePoseSA, **dhParamsSA)
  rMM = robot('rColMM', NrkSDK, 'MM', *homePoseMM, **dhParamsMM)
  '''
  for k, f in r.linkFrames.items():
    print(f.getTWorld())
  ''' 
  '''
  newPsa = (0,90,-45,0,90,0,0)
  newPmm = (0,0,90,-45,0,-90,0)
  for i in range(5):
    input('hit enter to go to new pose \n')
    rSA.setPose(*newPsa)
    rMM.setPose(*newPmm)
    input('hit enter to go to home pose \n')
    rSA.setPose(*homePoseSA)
    rMM.setPose(*homePoseMM)
    '''
  input('enter to close')
  NrkSDK.DeleteCollection('rColSA')
  NrkSDK.DeleteCollection('rColMM')
  NrkSDK.close()
  
  