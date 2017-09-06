# -*- coding: utf-8 -*-
"""
Created on Fri Jun  9 12:11:44 2017

@author: mallman
"""
import numpy as np
import math as m
import random as rr
import operator
import matplotlib.pyplot as plt

degToRad = (np.pi/180)

def getTSaha(**params):
  alpha = params['alpha']*degToRad
  A = params['A']
  D = params['D']
  theta = params['theta']*degToRad
  T = np.array([[m.cos(theta), -m.sin(theta)*m.cos(alpha), m.sin(theta)*m.sin(alpha), A*m.cos(theta)],
                [m.sin(theta), m.cos(theta)*m.cos(alpha), -m.cos(theta)*m.sin(alpha), A*m.sin(theta)],
                [0, m.sin(alpha), m.cos(alpha), D],
                [0, 0, 0, 1]])
  return np.matrix(T)

def getTSaha2(thetaVal, **params):
  alpha = params['alpha']*degToRad
  A = params['A']
  D = params['D']
  theta = thetaVal*degToRad
  T = np.array([[m.cos(theta), -m.sin(theta)*m.cos(alpha), m.sin(theta)*m.sin(alpha), A*m.cos(theta)],
                [m.sin(theta), m.cos(theta)*m.cos(alpha), -m.cos(theta)*m.sin(alpha), A*m.sin(theta)],
                [0, m.sin(alpha), m.cos(alpha), D],
                [0, 0, 0, 1]])
  return np.matrix(T)

def getTCraig(**params):
  alpha = params['alpha']*degToRad
  A = params['A']
  D = params['D']
  theta = params['theta']*degToRad
  T = np.array([[m.cos(theta), -m.sin(theta), 0, A],
                [m.sin(theta)*m.cos(alpha), m.cos(theta)*m.cos(alpha), -m.sin(alpha), -m.sin(alpha)*D],
                [m.sin(theta)*m.sin(alpha), m.cos(theta)*m.sin(alpha), m.cos(alpha), m.cos(alpha)*D],
                [0, 0, 0, 1]])
  return np.matrix(T)

def getTCraig2(thetaVal, **params):
  alpha = params['alpha']*degToRad
  A = params['A']
  D = params['D']
  theta = thetaVal*degToRad
  T = np.array([[m.cos(theta), -m.sin(theta), 0, A],
                [m.sin(theta)*m.cos(alpha), m.cos(theta)*m.cos(alpha), -m.sin(alpha), -m.sin(alpha)*D],
                [m.sin(theta)*m.sin(alpha), m.cos(theta)*m.sin(alpha), m.cos(alpha), m.cos(alpha)*D],
                [0, 0, 0, 1]])
  return np.matrix(T)

def getTbF(**DH):
  return getTCraig(**DH['S'])*getTCraig(**DH['L'])*getTCraig(**DH['U'])*getTCraig(**DH['R'])*getTCraig(**DH['B'])*getTCraig(**DH['T'])*getTCraig(**DH['F'])

def getBFmm(**DH):
  return getTSaha(**DH['Base'])*getTSaha(**DH['S'])*getTSaha(**DH['L'])*getTSaha(**DH['U'])*getTSaha(**DH['R'])*getTSaha(**DH['B'])*getTSaha(**DH['T'])

def getBFsa(**DH):
  return getTCraig(**DH['S'])*getTCraig(**DH['L'])*getTCraig(**DH['U'])*getTCraig(**DH['R'])*getTCraig(**DH['B'])*getTCraig(**DH['T'])*getTCraig(**DH['F'])
  
def getTbFRand(jointChar, valChar, **DH):
  valToMod = DH[jointChar][valChar]
  DH[jointChar][valChar] = getRand(valToMod)
  return getTbF(**DH)
  
def getRand(val):
  rVal = 0.1*val*(rr.random() - 0.5) + val
  #rVal = 0.9*val
  return rVal

def getOffsets(**DH):
  T = getTbF(**DH)
  return (T[0,3], T[1,3], T[2,3])

def getPathErr(modJoint, modParam, modVal, **DH):
  valToMod = DH[modJoint][modParam]
  DH[modJoint][modParam] = (1 + modVal)*valToMod
  r1 = getOffsets(**DH)
  DH[modJoint][modParam] = (1 - modVal)*valToMod
  r2 = getOffsets(**DH)
  r = r1 + r2
  DH[modJoint][modParam] = valToMod
  return getErr(*r)
  
def getErr(*r):
  r1 = r[:3]
  r2 = r[3:]
  diffs = tuple(map(operator.sub,r2,r1))
  absDiffs = tuple(abs(x) for x in diffs)
  dMag = np.sqrt(sum(tuple(x**2 for x in diffs)))
  return dMag, absDiffs

def rndToZero(arr):
  outArr = np.zeros(arr.shape)
  for i,a in enumerate(arr):
    for j,el in enumerate(a):
      if (np.abs(el) < 1e-12):
        outArr[i,j] = 0
      else:
        outArr[i,j] = el
  return np.reshape(outArr, np.shape(arr))

  

if __name__ == "__main__":
  S = {'alpha': 0, 'A': 0, 'D': 540,'theta': 0} #(alpha, A, D, theta)
  L = {'alpha':90, 'A': 140, 'D': 0, 'theta': 90}
  U = {'alpha':0, 'A': 1150, 'D': 0, 'theta': 0}
  R = {'alpha':90, 'A': 210, 'D': 1225, 'theta': 0}
  B = {'alpha':90, 'A': 0, 'D': 0, 'theta': 90}
  T = {'alpha':-90,'A': 0, 'D': 0, 'theta': -90}
  F = {'alpha':0, 'A': 0, 'D': 175, 'theta': -90}
  
  dhDict = {}
  dhDict['S'] = S
  dhDict['L'] = L
  dhDict['U'] = U
  dhDict['R'] = R
  dhDict['B'] = B
  dhDict['T'] = T
  dhDict['F'] = F
  
  sweepJoint = 'S'
  modJoints = ['L']
  modParam = 'A'
  modVal = 0.1
  theta0 = dhDict[sweepJoint]['theta']
  for jnt in modJoints:
    dMags = []
    valToMod = dhDict[jnt][modParam]
    theta = np.linspace(-45, 45, 100)
    for i, t in enumerate(theta):
      dhDict[sweepJoint]['theta'] = t + theta0
      dMag, diffs = getPathErr(jnt, modParam, modVal, **dhDict)
      dMags.append(dMag)
  plt.plot(theta, dMags)
  plt.show()
      
      
  '''
    plt.plot(x1Vals, y1Vals, label = 'larger')
    plt.plot(x2Vals, y2Vals, label = 'smaller')
    plt.xlabel('x (mm)')
    plt.ylabel('y (mm)')
    plt.title('Sweeping %s, Modulating %s[%s] by %0.0f%%' %(sweepJoint, jnt, modParam, modVal*100))
    plt.show(block = False)
    plt.legend()
    saveName = 'sweep_%s_Modulate_%s_%s_by_%0.0fPercent.png' % (sweepJoint, jnt, modParam, modVal*100)
    plt.savefig(saveName)
    plt.clf()
    '''
    

    
    
  
  
  '''
  path = "C:\\Users\\mallman\\Documents\\git\\DHParams\\tForm.txt"
  np.savetxt(path, np.reshape(TbF,(1,-1)))
  '''
  
  
  
  