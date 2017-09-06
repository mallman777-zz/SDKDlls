# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 13:19:27 2017

@author: mallman
"""
import DH
import frame
import SDK
import numpy as np

def getFirstNonZeroIdx(p1, p2):
  a = tuple(np.subtract(p1, p2))
  return next((i for i,x in enumerate(a) if x), None)

class robot(object):
  def __init__(self, rCol, Nrk, kind, *homePose, **DH):
    self.DHparams = DH
    self.col = rCol
    self.linkFrames = {}
    self.nrk = Nrk
    self.currPose = None
    self.homePose = homePose
    self.kind = kind
    self.genRobot()
    
  def genRobot(self):
    if self.kind == 'SA':
      jList = ['S', 'L', 'U', 'R', 'B', 'T', 'F']
    else:
      jList = ['S', 'L', 'U', 'R', 'B', 'T', 'F']
    Tw = np.diag(np.ones(4, dtype = np.double))
    params = {}
    params['col'] = self.col
    for j in range(len(self.DHparams)):
      if self.kind == 'SA':
        Tcurr = DH.getTCraig2(self.homePose[j], **self.DHparams[jList[j]])
      else:
        Tcurr = DH.getTSaha2(self.homePose[j], **self.DHparams[jList[j]])
      Tw = np.matmul(Tw,Tcurr)
      params['name'] = jList[j]
      params['TWorld'] = Tw
      self.linkFrames[jList[j]] = frame.frame(**params)
      self.nrk.ConstructFrame(self.col, jList[j], Tcurr)
      self.nrk.SetWorkingFrame(self.col, jList[j])
    self.nrk.SetWorkingFrame("A", "World")
    self.currPose = self.homePose
    
  def setPose(self, *pose):
    if self.currPose == pose:
      return
    else:
      if self.kind == 'SA':
        jList = ['S', 'L', 'U', 'R', 'B', 'T', 'F']
      else:
        jList = ['S', 'L', 'U', 'R', 'B', 'T', 'F']
      start = getFirstNonZeroIdx(pose, self.currPose)
      print('start: ', start)
      Tw = np.diag(np.ones(4, dtype = np.double))
      if start != 0:
        Tw = self.linkFrames[jList[start - 1]].getTWorld()
      for i in range(start, len(self.DHparams)):
        if self.kind == 'SA':
          Tw = np.matmul(Tw, DH.getTCraig2(pose[i], **self.DHparams[jList[i]]))
        else:
          Tw = np.matmul(Tw, DH.getTSaha2(pose[i], **self.DHparams[jList[i]]))
        self.nrk.DeleteObjects([self.linkFrames[jList[i]]])
        self.nrk.ConstructFrame(self.col, jList[i], Tw)
        self.linkFrames[jList[i]].setTWorld(Tw)
      self.currPose = pose
    pass
        
if __name__ == "__main__":
  
  chi = 1.01
  Ssa = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Lsa = {'alpha':90, 'A': 140, 'D': 1}
  Usa = {'alpha':0, 'A': 1150, 'D': 0}
  Rsa = {'alpha':90, 'A': 210, 'D': 1225}
  Bsa = {'alpha':90, 'A': 0, 'D': 0}
  Tsa = {'alpha':-90,'A': 0, 'D': 0}
  Fsa = {'alpha':0, 'A': 0, 'D': 175}
  
  Smm = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Lmm = {'alpha':90, 'A': 140, 'D': 1}
  Umm = {'alpha':0, 'A': 1150, 'D': 0}
  Rmm = {'alpha':90, 'A': 210, 'D': 0}
  Bmm = {'alpha':-90, 'A': 0, 'D': 1225}
  Tmm = {'alpha':90,'A': 0, 'D': 0}
  Fmm = {'alpha':0, 'A': 0, 'D': 175}
  
  homePoseSA = (0,90,0,0,90,0,0)
  homePoseMM = (0,0,90,0,0,-90,0)
  dhParamsSA = {'S': Ssa, 'L': Lsa, 'U': Usa, 'R': Rsa, 'B': Bsa, 'T': Tsa, 'F': Fsa}
  dhParamsMM = {'S': Smm, 'L': Lmm, 'U': Umm, 'R': Rmm, 'B': Bmm, 'T': Tmm, 'F': Fmm}
  NrkSDK = SDK.SDKlib("SDKMFC2015.dll")
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
  #NrkSDK.DeleteCollection('rColSA')
  #NrkSDK.DeleteCollection('rColMM')
  '''
  NrkSDK.close()
  
  