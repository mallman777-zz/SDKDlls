# -*- coding: utf-8 -*-
"""
Created on Mon Sep 25 09:09:01 2017

@author: mallman
"""

from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import pyqtgraph.parametertree.parameterTypes as pTypes
from pyqtgraph.parametertree import Parameter, ParameterTree, ParameterItem, registerParameterType
import pyqtgraph.ptime as ptime
import pyqtgraph.exporters
import pyqtgraph.exporters.ImageExporter as IE
import sys


def setupWindow(msg, pTree):
  win = QtGui.QMainWindow()
  glw = QtGui.QWidget()
  layout = QtGui.QGridLayout()
  splitter = QtGui.QSplitter(QtCore.Qt.Horizontal)
  win.setCentralWidget(glw)
  glw.setLayout(layout)
  win.setLayout(layout)
  layout.addWidget(splitter)
  splitter.addWidget(pTree)
  win.resize(800,300)
  win.setWindowTitle(msg)
  win.show()
  win.raise_()
  return win
    
def change(param, changes):
  global p1
  for param, change, data in changes:
    path = p1.childPath(param)
    if path is not None:
      childName = '.'.join(path)
    else:
      childName = param.name()
    if (childName in ['x', 'y']):
      p1.param('sum').setValue(p1.param('x').value() + p1.param('y').value())
  print('  parameter: %s'% childName)
  print('  change:    %s'% change)
  print('  data:      %s'% str(data))
  print('  ----------')
  
def change2(param, changes):
  global p2
  for param, change, data in changes:
    path = p1.childPath(param)
    if path is not None:
      childName = '.'.join(path)
    else:
      childName = param.name()
    if (childName in ['x', 'y']):
      p2.param('sum').setValue(p2.param('x').value() + p2.param('y').value())
  print('  parameter: %s'% childName)
  print('  change:    %s'% change)
  print('  data:      %s'% str(data))
  print('  ----------')

if __name__ == "__main__":
  app = QtGui.QApplication.instance()
  if app is None:   #Qt cannot be called twice.  Checks if been created.  If so, doesn't create a new one.  Executes existing one on pendant.runApp()
    app = QtGui.QApplication([])
  else:
    print('QApplication instance already exists: %s' % str(app))
  
  params1 = [{'name' : 'x', 'type': 'int', 'value' :7},
             {'name' : 'y', 'type': 'int', 'value' :7},
             {'name' : 'sum', 'type': 'int', 'value' :14}
      ]
  
  p1 = Parameter.create(name = 'params', type = 'group', children = params1)
  p2 = Parameter.create(name = 'params', type = 'group', children = params1)
  pTree1 = ParameterTree()
  pTree2 = ParameterTree()
  pTree1.setParameters(p1, showTop = False)
  pTree2.setParameters(p2, showTop = False)
  win1 = setupWindow('Window1', pTree1)
  win2 = setupWindow('Window2', pTree2)
  p1.sigTreeStateChanged.connect(change)
  p2.sigTreeStateChanged.connect(change2)
  
  if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
    if not (app is None): 
      app.exec_()