# -*- coding: utf-8 -*-
"""
Created on Mon Sep 11 11:19:59 2017

@author: mallman
"""

import robot
import numpy as np
import SDK
import scipy.optimize as so
import DH

def getPoseForFrame(Tf, robot):
  params = (robot.DHparams['S'],robot.DHparams['L'],robot.DHparams['U'],robot.DHparams['R'],robot.DHparams['B'],robot.DHparams['T'], robot.DHparams['F'], {'target': Tf})
  ret = so.minimize(getResidual, robot.currPose, args = params)
  return tuple(ret.x)
  
def getResidual(x, *params):
  Tw = np.diag(np.ones(4, dtype = np.double))
  for i in range(len(x)):
    Tw = np.matmul(Tw, DH.getTCraig3(x[i], **params[i]))
  '''
  Ttarg = np.array([[0.8213938, 0.42261826, -0.38302222, 1800],
                [0.38302222, -0.90630779, -0.1786062, 500],
                [-0.42261826, 0, -0.90630779, 1705],
                [0, 0, 0, 1]])
  '''
  ret = np.sum((Tw - params[-1]['target'])**2)
  return ret

def getDistance(R1, R2):
  return np.sum((R1 - R2)**2)
  
def test(x, *args):
  return (args[0] - x[0])**2 + (args[1] - x[1])**2

if __name__ == "__main__":
  chi = 1.01
  Sr = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Lr = {'alpha':90, 'A': chi*140, 'D': 0}
  Ur = {'alpha':0, 'A': 1150, 'D': 0}
  Rr = {'alpha':90, 'A': 210, 'D': chi*1225}
  Br = {'alpha':90, 'A': 0, 'D': 0}
  Tr = {'alpha':-90,'A': 0, 'D': 0}
  Fr = {'alpha':0, 'A': 0, 'D': 175}
  
  Sn = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Ln = {'alpha':90, 'A': 140, 'D': 0}
  Un = {'alpha':0, 'A': 1150, 'D': 0}
  Rn = {'alpha':90, 'A': 210, 'D': 1225}
  Bn = {'alpha':90, 'A': 0, 'D': 0}
  Tn = {'alpha':-90,'A': 0, 'D': 0}
  Fn = {'alpha':0, 'A': 0, 'D': 175}
   
  dhParamsR = {'S': Sr, 'L': Lr, 'U': Ur, 'R': Rr, 'B': Br, 'T': Tr, 'F': Fr}
  dhParamsN = {'S': Sn, 'L': Ln, 'U': Un, 'R': Rn, 'B': Bn, 'T': Tn, 'F': Fn}
  NrkSDK = SDK.SDKlib("SDKMFC2015.dll")
  NrkSDK.connToSA()
  homePoseSA = (0,90,0,0,90,0,0)
  rN = robot.robot('NominaLRobot', NrkSDK, 'SA', *homePoseSA, **dhParamsN)
  
  targs = ['T0', 'T1', 'T2']
  for t in targs:
    T = NrkSDK.GetWorkingTransformOfObjectFixedXYZ('A', t)
    p = getPoseForFrame(T, rN)
    input('Hit Enter to Move to Target')
    rN.setPose(*p)
    
  input('Hit Enter to Go Home')
  rN.setPose(*homePoseSA)
  input('Hit Enter to Kill Robot')
  NrkSDK.DeleteCollection(rN.col)
  NrkSDK.close()