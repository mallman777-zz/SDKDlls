# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 13:19:27 2017

@author: mallman
"""
import DH
import frame
import SDK

class robot(object):
  def __init__(self, **DH):
    self.DHparams = DH
    self.linkFrames = None
    self.nrk = SDK.SDKlib("SDKMFC2015.dll")
    self.nrk.connToSA()
    
  def genRobot(self):
    if 'S' in self.DHparams.keys():
      T = DH.getTCraig(**self.DHparams['S'])
      self.nrk.ConstructFrame("A", "S", T)
    else:
      self.nrk.DisplayMsg('bombed')
      
  def close(self):
    self.nrk.close()
    
if __name__ == "__main__":
  S = {'alpha': 0, 'A': 0, 'D': 540,'theta': 0} #(alpha, A, D, theta)
  L = {'alpha':90, 'A': 140, 'D': 0, 'theta': 90}
  dhParams = {'S': S, 'L': L}
  r = robot(**dhParams)
  r.genRobot()
  r.close()
  
  