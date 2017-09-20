# A template for writing pyqt guis. This template will run without changes.  
import sys
import time, os, atexit, datetime
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

def Cleanup():
  NrkSDK.close()
  pass
  
class complexParam(Parameter):
  def __init__(self, **opts):
    Parameter.__init__(self, **opts)
    self.DH = {}
    self.pose = ()
    self.setDH()
    self.setPose()
    
  def setDH(self):
    for c in self.children():
      if c.name() == 'Robot Params':
        for cc in c.children():
          self.DH[cc.name()] = {cc.param('alpha').name(): cc.param('alpha').value(), cc.param('A').name(): cc.param('A').value(), cc.param('D').name(): cc.param('D').value()}
  def setPose(self):
    for c in self.children():
      if c.name() == 'Pose':
        self.pose = (c.param('S').value(), c.param('L').value(), c.param('U').value(), c.param('R').value(), c.param('B').value(), c.param('T').value(), c.param('F').value())
          
class Pendant(object):
  def __init__(self, **opts):
    self.NrkSDK = None
    if 'NrkSDK' in opts.keys():
      self.NrkSDK = opts['NrkSDK']
    self.app = None
    if 'QtApp' in opts.keys():
      self.app = opts['QtApp']
    self.pTree = None
    self.parameters = None
    self.win = None
    self.setupTree()
    self.setupWindow()
    self.runApp()
    self.robots = []
    
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
        {'name': 'Pose', 'type':'group', 'children':[
            {'name': 'S', 'type': 'float', 'value':0},
            {'name': 'L', 'type': 'float', 'value':90},
            {'name': 'U', 'type': 'float', 'value':0},
            {'name': 'R', 'type': 'float', 'value':0},
            {'name': 'B', 'type': 'float', 'value':90},
            {'name': 'T', 'type': 'float', 'value':0},
            {'name': 'F', 'type': 'float', 'value':0}]},
        {'name': 'Add Robot', 'type': 'action'}
      ]
    self.parameters = complexParam(name = 'params', type = 'group', children = params)
    self.pTree = ParameterTree()
    self.pTree.setParameters(self.parameters, showTop = False)

  def change(self, param, changes):
    for param, change, data in changes:
      path = self.parameters.childPath(param)
      if path is not None:
        childName = '.'.join(path)
      else:
        childName = param.name()
      if childName == 'Add Robot':
        self.addRobot()
    print('  parameter: %s'% childName)
    print('  change:    %s'% change)
    print('  data:      %s'% str(data))
    print('  ----------')
    
  def addRobot(self):
    #r = rb.robot()
    pass

  def setupWindow(self):
    self.win = QtGui.QMainWindow()
    glw = QtGui.QWidget()
    layout = QtGui.QGridLayout()
    splitter = QtGui.QSplitter(QtCore.Qt.Horizontal)
    self.win.setCentralWidget(glw)
    glw.setLayout(layout)
    #self.win.setLayout(layout)
    layout.addWidget(splitter)
    splitter.addWidget(self.pTree)
    self.win.resize(800,300)
    self.win.setWindowTitle('Robot Pendant')
    self.win.show()
    self.win.raise_()

  def runApp(self):
    self.parameters.sigTreeStateChanged.connect(self.change)
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
      if not (self.app is None): 
        self.app.exec_()

if __name__ == '__main__':
  try:
    app = QtGui.QApplication.instance()
    if app is None:   #Qt cannot be called twice.  Checks if been created.  If so, doesn't create a new one.  Executes existing one on pendant.runApp()
      app = QtGui.QApplication([])
    else:
      print('QApplication instance already exists: %s' % str(app))
    path = "C:\\Users\\mallman\\Documents\\git\\SDKDlls\\SDKMFC2015\\Release"
    dllFile = "SDKMFC2015.dll"
    NrkSDK = SDK.SDKlib(os.path.join(path, dllFile))
    NrkSDK.connToSA()
    pendant = Pendant(NrkSDK = NrkSDK, QtApp = app)
  finally:
    Cleanup()
  
  
  
  
  
    
  
        

	    


