# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 13:19:27 2017

@author: mallman
"""
import DH
import frame
import SDK
import numpy as np

def getFirstNonZeroIdx(*p):
  return next((i for i,x in enumerate(p) if x), None)

class robot(object):
  def __init__(self, rCol, Nrk, *homePose, **DH):
    self.DHparams = DH
    self.col = rCol
    self.linkFrames = {}
    self.nrk = Nrk
    self.currPose = None
    self.homePose = homePose
    self.genRobot()
    
  def genRobot(self):
    jList = ['S', 'L', 'U', 'R', 'B', 'T']
    Tw = np.diag(np.ones(4, dtype = np.double))
    params = {}
    params['col'] = self.col
    for j in range(len(self.DHparams)):
      Tcurr = DH.getTCraig2(self.homePose[j], **self.DHparams[jList[j]])
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
      jList = ['S', 'L', 'U', 'R', 'B', 'T']
      self.currPose = pose
      start = getFirstNonZeroIdx(*pose)
      print('start: ', start)
      Tw = np.diag(np.ones(4, dtype = np.double))
      if start != 0:
        Tw = self.linkFrames[jList[start - 1]].getTWorld()
      for i in range(start, len(self.DHparams)):
        Tw = np.matmul(Tw, DH.getTCraig2(pose[i], **self.DHparams[jList[i]]))
        self.nrk.TransformObjectsByDeltaAboutWorkingFrame([self.linkFrames[jList[i]]], Tw)
        self.linkFrames[jList[i]].setTWorld(Tw)
    pass
        
if __name__ == "__main__":
  S = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D)
  L = {'alpha':90, 'A': 140, 'D': 0}
  U = {'alpha':0, 'A': 1150, 'D': 0}
  R = {'alpha':90, 'A': 210, 'D': 1225}
  B = {'alpha':90, 'A': 0, 'D': 0}
  T = {'alpha':-90,'A': 0, 'D': 0}
  homePose = (0,90,0,0,0,-90)
  dhParams = {'S': S, 'L': L} #, 'U': U, 'R': R, 'B': B, 'T': T}
  NrkSDK = SDK.SDKlib("SDKMFC2015.dll")
  NrkSDK.connToSA()
  r = robot('rCol', NrkSDK, *homePose, **dhParams)
  
  for k, f in r.linkFrames.items():
    print(f.getTWorld())
  
  newPose = (90,90,0,0,0,-90)
  for i in range(5):
    input('hit enter to go to new pose \n')
    r.setPose(*newPose)
    for k, f in r.linkFrames.items():
      print(f.getTWorld())
    input('hit enter to go to home pose \n')
    r.setPose(*homePose)
  NrkSDK.close()
  
  