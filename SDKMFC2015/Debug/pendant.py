# A template for writing pyqt guis. This template will run without changes.  
import sys
import time, os, atexit, datetime, serial
import numpy as np
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import pyqtgraph.parametertree.parameterTypes as pTypes
from pyqtgraph.parametertree import Parameter, ParameterTree, ParameterItem, registerParameterType
import pyqtgraph.ptime as ptime
import pyqtgraph.exporters
import pyqtgraph.exporters.ImageExporter as IE

import robot as rb
import SDK


class Pendant(object):
  def __init__(self, **opts):
    self.pTree, self.parameters = self.setupTree()
    self.win = None
    self.setupWindow()
    self.runApp()
    
  def setupTree(self):
    params = [
        {'name':'Robot Params', 'type':'group', 'children': [
            {'name': 'S', 'type': 'group', 'children':[
                {'name': 'alpha', 'type': 'float', 'value': 1},
                {'name': 'A', 'type': 'float', 'value': 1},
                {'name': 'D', 'type': 'float', 'value': 1}
                ]},
          {'name': 'L', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 1},
              {'name': 'A', 'type': 'float', 'value': 1},
              {'name': 'D', 'type': 'float', 'value': 1}
              ]},
          {'name': 'U', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 1},
              {'name': 'A', 'type': 'float', 'value': 1},
              {'name': 'D', 'type': 'float', 'value': 1}
              ]},
          {'name': 'R', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 1},
              {'name': 'A', 'type': 'float', 'value': 1},
              {'name': 'D', 'type': 'float', 'value': 1}
              ]},  
          {'name': 'B', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 1},
              {'name': 'A', 'type': 'float', 'value': 1},
              {'name': 'D', 'type': 'float', 'value': 1}
              ]},
          {'name': 'T', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 1},
              {'name': 'A', 'type': 'float', 'value': 1},
              {'name': 'D', 'type': 'float', 'value': 1}
              ]},
          {'name': 'F', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 1},
              {'name': 'A', 'type': 'float', 'value': 1},
              {'name': 'D', 'type': 'float', 'value': 1}
              ]}
          ]},
        {'name': 'Add Robot', 'type': 'action'}
      ]
    p = Parameter.create(name = 'params', type = 'group', children = params)
    t = ParameterTree()
    t.setParameters(p, showTop = False)
    return t,p

  def change(self, param, changes):
    for param, change, data in changes:
      path = self.parameters.childPath(param)
      if path is not None:
        childName = '.'.join(path)
      else:
        childName = param.name()
    print('  parameter: %s'% childName)
    print('  change:    %s'% change)
    print('  data:      %s'% str(data))
    print('  ----------')

  def setupWindow(self):
    self.win = QtGui.QMainWindow()
    glw = QtGui.QWidget()
    layout = QtGui.QGridLayout()
    splitter = QtGui.QSplitter(QtCore.Qt.Horizontal)
    
    self.win.setCentralWidget(glw)
    glw.setLayout(layout)
    self.win.setLayout(layout)
    
    layout.addWidget(splitter)
    splitter.addWidget(self.pTree)
    
    self.win.resize(800,300)
    self.win.setWindowTitle('Robot Pendant')
    self.win.show()
    self.win.raise_()
    return None

  def runApp(self):
    self.parameters.sigTreeStateChanged.connect(self.change)
    atexit.register(self.cleanup)
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
      QtGui.QApplication.instance().exec_()
      
  def cleanup(self):
    pass

if __name__ == '__main__':
  app = QtGui.QApplication([])
  pendant = Pendant()
  
    
  
        

	    


