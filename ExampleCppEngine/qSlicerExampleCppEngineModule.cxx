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

// ExampleCppEngine Logic includes
#include <vtkSlicerExampleCppEngineLogic.h>

// ExampleCppEngine includes
#include "qSlicerExampleCppEngineModule.h"
#include "qSlicerExampleCppEngineModuleWidget.h"

// ExternalBeamPlanning includes
#include "qSlicerDoseEnginePluginHandler.h"

// DoseEngines includes
#include "qSlicerExampleCppDoseEngine.h"

//-----------------------------------------------------------------------------
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <QtPlugin>
Q_EXPORT_PLUGIN2(qSlicerExampleCppEngineModule, qSlicerExampleCppEngineModule);
#endif

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerExampleCppEngineModulePrivate
{
public:
  qSlicerExampleCppEngineModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerExampleCppEngineModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerExampleCppEngineModulePrivate::qSlicerExampleCppEngineModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerExampleCppEngineModule methods

//-----------------------------------------------------------------------------
qSlicerExampleCppEngineModule::qSlicerExampleCppEngineModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerExampleCppEngineModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerExampleCppEngineModule::~qSlicerExampleCppEngineModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerExampleCppEngineModule::helpText() const
{
  return "This is a hidden module providing the Plastimatch proton dose engine";
}

//-----------------------------------------------------------------------------
QString qSlicerExampleCppEngineModule::acknowledgementText() const
{
  return "This work was funded by CANARIE";
}

//-----------------------------------------------------------------------------
QStringList qSlicerExampleCppEngineModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("Csaba Pinter (Queen's)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QStringList qSlicerExampleCppEngineModule::categories() const
{
  return QStringList() << "Radiotherapy";
}

//-----------------------------------------------------------------------------
QStringList qSlicerExampleCppEngineModule::dependencies() const
{
  return QStringList() << "ExternalBeamPlanning";
}

//-----------------------------------------------------------------------------
void qSlicerExampleCppEngineModule::setup()
{
  this->Superclass::setup();

  // Register dose engines
  qSlicerDoseEnginePluginHandler::instance()->registerDoseEngine(new qSlicerExampleCppDoseEngine());
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerExampleCppEngineModule
::createWidgetRepresentation()
{
  return new qSlicerExampleCppEngineModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerExampleCppEngineModule::createLogic()
{
  return vtkSlicerExampleCppEngineLogic::New();
}
