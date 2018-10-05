import os
import unittest
import vtk, qt, ctk, slicer
from slicer.ScriptedLoadableModule import *
import logging

#
# ExamplePythonEngineModule
#

class ExamplePythonEngineModule(ScriptedLoadableModule):
  """Uses ScriptedLoadableModule base class, available at:
  https://github.com/Slicer/Slicer/blob/master/Base/Python/slicer/ScriptedLoadableModule.py
  """

  def __init__(self, parent):
    ScriptedLoadableModule.__init__(self, parent)
    self.parent.title = "ExamplePythonEngineModule"
    self.parent.categories = ["Radiotherapy"]
    self.parent.dependencies = []
    self.parent.contributors = ["John Doe (AnyWare Corp.)"] # replace with "Firstname Lastname (Organization)"
    self.parent.helpText = """
This is an example of scripted loadable module providing a python dose calculation engine.
"""
    self.parent.helpText += self.getDefaultModuleDocumentationLink()
    self.parent.hidden = True
    self.parent.acknowledgementText = """
This file was originally developed by Csaba Pinter, Queen's University and was funded by CANARIE.
""" # replace with organization, grant and thanks.

    slicer.app.connect("startupCompleted()", self.registerEngine)

  def registerEngine(self):
    # Register engine algorithm
    import qSlicerExternalBeamPlanningModuleWidgetsPythonQt as engines
    examplePythonEngineModuleAlgorithmInstance = engines.qSlicerScriptedDoseEngine(None)
    enginePath = os.path.dirname(__file__) + '/DoseEngine/ExamplePythonEngine.py'
    examplePythonEngineModuleAlgorithmInstance.setPythonSource(enginePath)
    examplePythonEngineModuleAlgorithmInstance.self().register()

#
# ExamplePythonEngineModuleWidget
#

class ExamplePythonEngineModuleWidget(ScriptedLoadableModuleWidget):
  """Uses ScriptedLoadableModuleWidget base class, available at:
  https://github.com/Slicer/Slicer/blob/master/Base/Python/slicer/ScriptedLoadableModule.py
  """

  def setup(self):
    ScriptedLoadableModuleWidget.setup(self)

  def cleanup(self):
    pass

#
# ExamplePythonEngineModuleTest
#

class ExamplePythonEngineModuleTest(ScriptedLoadableModuleTest):
  """
  This is the test case for your scripted module.
  Uses ScriptedLoadableModuleTest base class, available at:
  https://github.com/Slicer/Slicer/blob/master/Base/Python/slicer/ScriptedLoadableModule.py
  """

  def setUp(self):
    """ Do whatever is needed to reset the state - typically a scene clear will be enough.
    """
    slicer.mrmlScene.Clear(0)

  def runTest(self):
    """Run as few or as many tests as needed here.
    """
    self.setUp()
    self.test_ExamplePythonEngineModule1()

  def test_ExamplePythonEngineModule1(self):
    """ Ideally you should have several levels of tests.  At the lowest level
    tests should exercise the functionality of the logic with different inputs
    (both valid and invalid).  At higher levels your tests should emulate the
    way the user would interact with your code and confirm that it still works
    the way you intended.
    One of the most important features of the tests is that it should alert other
    developers when their changes will have an impact on the behavior of your
    module.  For example, if a developer removes a feature that you depend on,
    your test should break so they know that the feature is needed.
    """

    self.delayDisplay("Starting the test")
    logic = ExamplePythonEngineModuleLogic()
    self.assertIsNotNone( logic )
    self.delayDisplay('Test passed!')
