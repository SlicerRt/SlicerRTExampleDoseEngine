cmake_minimum_required(VERSION 3.5)

project(SlicerRTExampleDoseEngine)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "http://slicer.org/slicerWiki/index.php/Documentation/Nightly/Extensions/SlicerRTExampleDoseEngine")
set(EXTENSION_CATEGORY "Radiotherapy")
set(EXTENSION_CONTRIBUTORS "Csaba Pinter (Queen's University)")
set(EXTENSION_DESCRIPTION "This is an example of a radiation therapy dose calculation engine as a separate extension. The extension contains two dummy dose engines, one in C++, one in Python. Once installed, they are added as a dose engine into the External Beam Planning module. The module can be found in SlicerRT, which is a dependency.")
set(EXTENSION_ICONURL "http://www.example.com/Slicer/Extensions/SlicerRTExampleDoseEngine.png")
set(EXTENSION_SCREENSHOTURLS "http://www.example.com/Slicer/Extensions/SlicerRTExampleDoseEngine/Screenshots/1.png")
set(EXTENSION_DEPENDS "SlicerRT") # Specified as a space separated string, a list or 'NA' if any

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(ExampleCppEngine)
add_subdirectory(ExamplePythonEngine)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_GENERATE_CONFIG})
include(${Slicer_EXTENSION_CPACK})
