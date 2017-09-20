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
import calSim as cs

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
    self.robots = []
    self.numRobots = 0
    self.runApp()
       
  def setupTree(self):
    params = [
        {'name':'Robot Params', 'type':'group', 'children': [
          {'name': 'S', 'type': 'group', 'children':[
                {'name': 'alpha', 'type': 'float', 'value': 0},
                {'name': 'A', 'type': 'float', 'value': 0},
                {'name': 'D', 'type': 'float', 'value': 540}
                ]},
          {'name': 'L', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 90},
              {'name': 'A', 'type': 'float', 'value': 140},
              {'name': 'D', 'type': 'float', 'value': 0}
              ]},
          {'name': 'U', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 0},
              {'name': 'A', 'type': 'float', 'value': 1150},
              {'name': 'D', 'type': 'float', 'value': 0}
              ]},
          {'name': 'R', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 90},
              {'name': 'A', 'type': 'float', 'value': 210},
              {'name': 'D', 'type': 'float', 'value': 1225}
              ]},  
          {'name': 'B', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 90},
              {'name': 'A', 'type': 'float', 'value': 0},
              {'name': 'D', 'type': 'float', 'value': 0}
              ]},
          {'name': 'T', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': -90},
              {'name': 'A', 'type': 'float', 'value': 0},
              {'name': 'D', 'type': 'float', 'value': 0}
              ]},
          {'name': 'F', 'type': 'group', 'children':[
              {'name': 'alpha', 'type': 'float', 'value': 0},
              {'name': 'A', 'type': 'float', 'value': 0},
              {'name': 'D', 'type': 'float', 'value': 175}
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
        {'name': 'numRobots', 'type': 'int', 'value': 0},
        {'name': 'Add Robot', 'type': 'action'},
        {'name': 'Move To Frame', 'type': 'action'}
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
      if 'Robot Params' in childName:
        self.parameters.setDH()
      if 'Pose' in childName:
        self.parameters.setPose()
        if self.numRobots > 0:
          for r in self.robots:
            r.setPose(*self.parameters.pose)
      if 'Move To Frame' in childName:
        targs = ['T0', 'T1', 'T2']
        for t in targs:
          T = self.NrkSDK.GetWorkingTransformOfObjectFixedXYZ('A', t)
          for r in self.robots:
            p = cs.getPoseForFrame(T, r)
            input('Hit Enter to Move to Target')
            r.setPose(*p)
        input('Go Home')
        for r in self.robots:
          r.setPose(*r.homePose)
            
    print('  parameter: %s'% childName)
    print('  change:    %s'% change)
    print('  data:      %s'% str(data))
    print('  ----------')
    
  def addRobot(self):
    rCol = 'r%d' % self.numRobots
    self.robots.append(rb.robot(rCol, self.NrkSDK, 'SA', *self.parameters.pose, **self.parameters.DH))
    self.numRobots = len(self.robots)
    self.parameters.param('numRobots').setValue(self.numRobots)
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
    for r in pendant.robots:
      r.killRobot()
    Cleanup()
  
  
  
  
  
    
  
        

	    


