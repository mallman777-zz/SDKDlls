# -*- coding: utf-8 -*-
"""
Created on Mon Sep 25 14:23:33 2017

@author: mallman
"""

from pyqtgraph.parametertree import Parameter, ParameterTree, ParameterItem, registerParameterType

class A(object):
  def __init__(self, x, y):
    self.aD = {'x': x, 'y': y}
    self.b = B(**self.aD)
    
class B(object):
  def __init__(self, **b):
    self.bD = b

if __name__ == "__main__":
  a = A(3,4)
  print('a.b.bD: ', a.b.bD)
  a.aD['x'] = 7
  print('a.b.bD: ', a.b.bD)
