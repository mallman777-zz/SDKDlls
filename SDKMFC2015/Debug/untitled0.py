# -*- coding: utf-8 -*-
"""
Created on Fri Sep 15 10:23:13 2017

@author: mallman
"""

import SDK
import robot as r

if __name__ == "__main__":
  Ssa = {'alpha': 0, 'A': 0, 'D': 540} #(alpha, A, D, theta)
  Lsa = {'alpha':90, 'A': 140, 'D': 0}
  Usa = {'alpha':0, 'A': 1150, 'D': 0}
  Rsa = {'alpha':90, 'A': 210, 'D': 1225}
  Bsa = {'alpha':90, 'A': 0, 'D': 0}
  Tsa = {'alpha':-90,'A': 0, 'D': 0}
  Fsa = {'alpha':0, 'A': 0, 'D': 175}
  
  homePoseSA = (0,90,0,0,90,0,0)
  dhParamsSA = {'S': Ssa, 'L': Lsa, 'U': Usa, 'R': Rsa, 'B': Bsa, 'T': Tsa, 'F': Fsa}
  
  NrkSDK = SDK.SDKlib("SDKMFC2015.dll")
  NrkSDK.connToSA()
  rSA = r.robot('rColSA', NrkSDK, 'SA', *homePoseSA, **dhParamsSA)
  
  pList = NrkSDK.MakePointNameRefListRuntimeSelect(100, 'select cool points')
  
  print(pList)
  
  NrkSDK.close()