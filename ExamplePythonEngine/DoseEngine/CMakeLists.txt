set(DoseEngine_PYTHON_SCRIPTS
  ExamplePythonEngine
  )

set(DoseEngine_PYTHON_RESOURCES
  )

ctkMacroCompilePythonScript(
  TARGET_NAME DoseEngine
  SCRIPTS "${DoseEngine_PYTHON_SCRIPTS}"
  RESOURCES "${DoseEngine_PYTHON_RESOURCES}"
  DESTINATION_DIR ${CMAKE_BINARY_DIR}/${Slicer_QTSCRIPTEDMODULES_LIB_DIR}/DoseEngine
  INSTALL_DIR ${Slicer_INSTALL_QTSCRIPTEDMODULES_LIB_DIR}/DoseEngine
  )
