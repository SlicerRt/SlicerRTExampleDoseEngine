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

// Qt includes
#include <QDebug>

// SlicerQt includes
#include "qSlicerExampleCppEngineModuleWidget.h"
#include "ui_qSlicerExampleCppEngineModuleWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerExampleCppEngineModuleWidgetPrivate: public Ui_qSlicerExampleCppEngineModuleWidget
{
public:
  qSlicerExampleCppEngineModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerExampleCppEngineModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerExampleCppEngineModuleWidgetPrivate::qSlicerExampleCppEngineModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerExampleCppEngineModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerExampleCppEngineModuleWidget::qSlicerExampleCppEngineModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerExampleCppEngineModuleWidgetPrivate )
{
}

//-----------------------------------------------------------------------------
qSlicerExampleCppEngineModuleWidget::~qSlicerExampleCppEngineModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerExampleCppEngineModuleWidget::setup()
{
  Q_D(qSlicerExampleCppEngineModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
}
