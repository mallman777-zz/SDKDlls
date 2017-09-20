# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 13:02:04 2017

@author: mallman
"""

class frame(object):
  def __init__(self, **params):
    self.Coll = None
    self.Name = None
    self.TWorld = None
    self.colObjName = None
    if 'col' in params.keys():
      self.Coll = params['col']
    if 'name' in params.keys():
      self.Name = params['name']
    if 'TWorld' in params.keys():
      self.TWorld = params['TWorld']
    if ((self.Coll != None) and (self.Name != None)):
      self.colObjName = self.Coll + "::" + self.Name + "::Frame"
    
  def setColl(self, val):
    self.Coll = val
    
  def getColl(self):
    return self.Coll
  
  def setName(self, val):
    self.Name = val
    
  def getName(self):
    return self.Name
  
  def setTWorld(self, T):
    self.TWorld = T
    
  def getTWorld(self):
    return self.TWorld
  
if __name__ == "__main__":
  f = frame()
  f.setColl('A')
  print(f.getColl())
