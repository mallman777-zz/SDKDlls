# -*- coding: utf-8 -*-
"""
Created on Mon Jul 31 16:14:31 2017

@author: mallman
"""

import ctypes as c
#from numpy.ctypeslib import ndpointer
import numpy as np

# Python Library Helper Functions
def ptListToBuff(ptList):
    sL = [ptList[i] + "," for i in range(len(ptList))]
    s = ''.join(sL)
    buf = c.create_string_buffer(str.encode(s[:-1]))
    return buf
  
def objListToBuff(objList):
  sL = [objList[i].colObjName + "," for i in range(len(objList))]
  s = ''.join(sL)
  buf = c.create_string_buffer(str.encode(s[:-1]))
  return buf
  
def getT(R, p):
  pp = np.reshape(p, (1,-1))
  a = np.hstack((R, pp.T))
  b = np.hstack((np.zeros(3), 1))
  return np.vstack((a, b))

class SDKlib(object):
  def __init__(self, f):
    self.libFileName = f
    self.lib = c.cdll.LoadLibrary(self.libFileName)
    self.lib.connToSA.argtypes = []
    self.lib.connToSA.restype = c.c_long
    self.lib.copyObject.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_bool]
    self.lib.copyObject.restype = None
    self.lib.renamePoint.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_bool]
    self.lib.renamePoint.restype = None
    self.lib.setOrConstructDefaultCollection.argtypes = [c.c_char_p]
    self.lib.setOrConstructDefaultCollection.restype = None
    self.lib.deleteCollection.argtypes = [c.c_char_p]
    self.lib.deleteCollection.restype = None
    self.lib.getActiveCollectionName.argtypes = [c.c_char_p, c.c_int]
    self.lib.getActiveCollectionName.restype = None
    
    self.lib.constructPointFitToPoints.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p]
    self.lib.constructPointFitToPoints.restype = None
    self.lib.constructAPointInWorkingCoordinates.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_double, c.c_double, c.c_double] 
    self.lib.constructAPointInWorkingCoordinates.restype = None
    self.lib.constructAPointAtLineMidPoint.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p] 
    self.lib.constructAPointAtLineMidPoint.restype = None
    self.lib.constructAPointGroupFromPointNameRefList.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p]
    self.lib.constructAPointGroupFromPointNameRefList.restype = None
    self.lib.constructAPointAtCircleCenter.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p]
    self.lib.constructAPointAtCircleCenter.restype = None
    
    self.lib.constructLine2Points.argtypes = [c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p, c.c_char_p]
    
    self.lib.constructFrame.argtypes = [c.c_char_p, c.c_char_p, np.ctypeslib.ndpointer(dtype=np.float64, ndim=2, flags='C_CONTIGUOUS')]
    self.lib.constructFrame.restype = None
    
    self.lib.makePointNameRefListRuntimeSelect.argtypes = [c.c_char_p, c.c_int, c.c_char_p]
    self.lib.makePointNameRefListRuntimeSelect.restype = None
    
    self.lib.transformObjectsByDeltaAboutWorkingFrame.argtypes = [c.c_char_p, np.ctypeslib.ndpointer(dtype=np.float64, ndim=2, flags='C_CONTIGUOUS')]
    self.lib.transformObjectsByDeltaAboutWorkingFrame.restype = None
    
    self.lib.setWorkingFrame.argtypes = [c.c_char_p, c.c_char_p]
    self.lib.setWorkingFrame.restype = None
    
    self.lib.displayMsg.argtypes = [c.c_char_p]
    self.lib.displayMsg.restypes = None
    
    self.lib.test.argtypes = [c.c_char_p, c.c_int]
    self.lib.test.restype = None
    self.handle = self.lib._handle
    
  def connToSA(self):
    return self.lib.connToSA()
  
  #File Operations
  #MP Task Overview
  #MP Subroutines
  #View Control
  #Construction Operations  
  def CopyObject(self, sCol, sNm, destCol, destNm, overwrite = False):
    self.lib.copyObject(str.encode(sCol), str.encode(sNm), str.encode(destCol), str.encode(destNm), c.c_bool(overwrite))
    
  def RenamePoint(self, origCol, origObj, origNm, newCol, newObj, newNm, overwrite = False):
    self.lib.renamePoint(str.encode(origCol), str.encode(origObj), str.encode(origNm), str.encode(newCol), str.encode(newObj), str.encode(newNm), c.c_bool(overwrite))
    
  def SetOrConstructDefaultCollection(self, colName):
    self.lib.setOrConstructDefaultCollection(str.encode(colName))
    
  def DeleteCollection(self, colName):
    self.lib.deleteCollection(str.encode(colName))
    
  def GetActiveCollectionName(self, sz = 100):
    buf = c.create_string_buffer(sz)
    self.lib.getActiveCollectionName(buf, sz)
    outStr = str(buf.value.decode())
    del(buf)
    return outStr
  
  def ConstructPointFitToPoints(self, ptList, ptCol, ptObj, ptNm):
    sL = [ptList[i] + "," for i in range(len(ptList))]
    s = ''.join(sL)
    print(s[:-1])
    buf = c.create_string_buffer(str.encode(s[:-1]))
    self.lib.constructPointFitToPoints(buf, str.encode(ptCol), str.encode(ptObj), str.encode(ptNm))
    
  def ConstructAPointInWorkingCoordinates(self, ptCol, ptObj, ptNm, x, y, z):
    self.lib.constructAPointInWorkingCoordinates(str.encode(ptCol), str.encode(ptObj), str.encode(ptNm), c.c_double(x), c.c_double(y), c.c_double(z))

  def ConstructAPointAtLineMidPoint(self, lCol, lNm, ptCol, ptObj, ptTarg):
    self.lib.constructAPointAtLineMidPoint(str.encode(lCol),str.encode(lNm),str.encode(ptCol),str.encode(ptObj),str.encode(ptTarg))    
    
  def ConstructAPointGroupFromPointNameRefList(self, ptList, ptCol, ptObj):
    buf = ptListToBuff(ptList)
    self.lib.constructAPointGroupFromPointNameRefList(buf, str.encode(ptCol), str.encode(ptObj))
    
  def ConstructAPointAtCircleCenter(self, cirCol, cirName, ptCol, ptObj, ptTarg):
    self.lib.constructAPointAtCircleCenter(str.encode(cirCol), str.encode(cirName), str.encode(ptCol), str.encode(ptObj), str.encode(ptTarg))
      
  def ConstructLine2Points(self, lCol, lName, fPtCol, fPtObj,fPtTarg, sPtCol, sPtObj, sPtTarg):
    self.lib.constructLine2Points(str.encode(lCol),str.encode(lName),str.encode(fPtCol),str.encode(fPtObj),str.encode(fPtTarg),str.encode(sPtCol),str.encode(sPtObj),str.encode(sPtTarg))
    
  def ConstructFrame(self, fCol, fName, T):
    if (T.shape[0] != 4 or T.shape[1] != 4):
      msg = "Transform wrong dimension"
      print(msg)
      self.DisplayMsg(msg)
    else:
      self.lib.constructFrame(str.encode(fCol), str.encode(fName), T)
    
  def MakePointNameRefListRuntimeSelect(self, sz, msg):
    buf = c.create_string_buffer(sz)
    self.lib.makePointNameRefListRuntimeSelect(buf, c.c_int(sz), str.encode(msg))
    outStr = str(buf.value.decode())
    del(buf)
    return outStr.split(",")
  
  #Analysis Operations
  
  def TransformObjectsByDeltaAboutWorkingFrame(self, objList, T):
    if 'colObjName' in dir(objList[0]):
      buf = objListToBuff(objList)
      self.lib.transformObjectsByDeltaAboutWorkingFrame(buf, T)
    else:
      msg = "Must Pass In List of SA Objects"
      self.DisplayMsg(msg)
      
  #Reporting Operations
  #Excel Direct Connect
  #MS Office Reporting Operations
  #Process Flow Operations
  #Scalar Math Operations
  #Vector Math Operations
  #Instrument Operations
  #Cloud Viewer Operations
  #Variables
  #Utility Operations
  
  def SetWorkingFrame(self, fCol, fName):
    self.lib.setWorkingFrame(str.encode(fCol), str.encode(fName))
   
  def DisplayMsg(self, msg):
    self.lib.displayMsg(str.encode(msg))
    
  def test(self, buf, sz):
    self.lib.test(buf, sz)
    
  def close(self):
    c.windll.kernel32.FreeLibrary(self.handle)
    
if __name__ == "__main__":
  lib = SDKlib("SDKMFC2015.dll")
  ret = lib.connToSA()
  R = np.diag(np.ones(3, dtype = np.double))
  P = np.array([100, 100, 100], dtype = np.double)
  T = getT(R, P)
  lib.ConstructFrame("hello", "you", T)
  ''' Must add this code to app that calls dll to free up dll '''
  lib.close()