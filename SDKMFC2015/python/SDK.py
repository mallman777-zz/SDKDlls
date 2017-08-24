# -*- coding: utf-8 -*-
"""
Created on Mon Jul 31 16:14:31 2017

@author: mallman
"""

import ctypes as c
#from numpy.ctypeslib import ndpointer

# Python Library Helper Functions
def ptListToBuff(ptList):
    sL = [ptList[i] + "," for i in range(len(ptList))]
    s = ''.join(sL)
    buf = c.create_string_buffer(str.encode(s[:-1]))
    return buf

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
    self.lib.makePointNameRefListRuntimeSelect.argtypes = [c.c_char_p, c.c_int, c.c_char_p]
    self.lib.makePointNameRefListRuntimeSelect.restype = None
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
    
  def MakePointNameRefListRuntimeSelect(self, sz, msg):
    buf = c.create_string_buffer(sz)
    self.lib.makePointNameRefListRuntimeSelect(buf, c.c_int(sz), str.encode(msg))
    outStr = str(buf.value.decode())
    del(buf)
    return outStr.split(",")
  
  #Analysis Operations
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
    
  def test(self, buf, sz):
    self.lib.test(buf, sz)
    
  def close(self):
    c.windll.kernel32.FreeLibrary(self.handle)
    
if __name__ == "__main__":
  lib = SDKlib("SDKMFC2015.dll")
  ret = lib.connToSA()
  lib.ConstructAPointAtCircleCenter('A', 'testCirc', 'A', 'B', 'cirCenter')
  ''' Must add this code to app that calls dll to free up dll '''
  lib.close()