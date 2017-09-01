# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 13:02:04 2017

@author: mallman
"""

class frame(object):
  def __init__(self):
    self.Coll = None
    self.Name = None
    self.TWorld = None
    
  def setColl(self, val):
    self.Coll = val
    
  def getColl(self):
    return self.Coll
  
  def setName(self, val):
    self.Name = val
    
  def getName(self):
    return self.Name
  
if __name__ == "__main__":
  f = frame()
  f.setColl('A')
  print(f.getColl())
