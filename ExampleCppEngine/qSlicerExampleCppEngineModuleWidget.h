/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through CANARIE.

==============================================================================*/

#ifndef __qSlicerExampleCppEngineModuleWidget_h
#define __qSlicerExampleCppEngineModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerExampleCppEngineModuleExport.h"

class qSlicerExampleCppEngineModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_EXAMPLECPPENGINE_EXPORT qSlicerExampleCppEngineModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerExampleCppEngineModuleWidget(QWidget *parent=0);
  virtual ~qSlicerExampleCppEngineModuleWidget();

  /// Make this module hidden
  virtual bool isHidden()const { return true; };

public slots:


protected:
  QScopedPointer<qSlicerExampleCppEngineModuleWidgetPrivate> d_ptr;

  virtual void setup();

private:
  Q_DECLARE_PRIVATE(qSlicerExampleCppEngineModuleWidget);
  Q_DISABLE_COPY(qSlicerExampleCppEngineModuleWidget);
};

#endif
