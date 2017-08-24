# -*- coding: utf-8 -*-
"""
Created on Tue May 23 15:11:16 2017

@author: mallman
"""

from ctypes import*
# give location of dll
path = "C:\\Users\\mallman\\Documents\\git\\SDKDlls\\MFCLibrary\\MFCLibrary\\Debug\\MFCLibrary.dll"
mydll = cdll.LoadLibrary(path)

m = cdll.LoadLibrary(path)
m.newAdd.restype = c_double
m.newAdd.argtypes = [c_double, c_double]

m.connectToSA.restype = c_long
res = m.connectToSA()

print(res)



