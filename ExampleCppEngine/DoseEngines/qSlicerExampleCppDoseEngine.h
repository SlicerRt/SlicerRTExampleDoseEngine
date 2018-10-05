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

#ifndef __qSlicerExampleCppDoseEngine_h
#define __qSlicerExampleCppDoseEngine_h

#include "qSlicerExampleCppEngineDoseEnginesExport.h"

// SlicerRT includes
#include "qSlicerAbstractDoseEngine.h"

/// \ingroup SlicerRt_QtModules_ExternalBeamPlanning
/// \class qSlicerExampleCppDoseEngine
/// \brief ExampleCpp dose calculation algorithm. Simply fills the beam apertures with prescription dose adding some noise.
///        Used as example.
class Q_SLICER_EXAMPLECPPENGINE_DOSE_ENGINES_EXPORT qSlicerExampleCppDoseEngine : public qSlicerAbstractDoseEngine
{
  Q_OBJECT

public:
  typedef qSlicerAbstractDoseEngine Superclass;
  /// Constructor
  explicit qSlicerExampleCppDoseEngine(QObject* parent=NULL);
  /// Destructor
  virtual ~qSlicerExampleCppDoseEngine();

public:
  /// Calculate dose for a single beam. Called by \sa CalculateDose that performs actions generic
  /// to any dose engine before and after calculation.
  /// \param beamNode Beam for which the dose is calculated. Each beam has a parent plan from which the
  ///   plan-specific parameters are got
  /// \param resultDoseVolumeNode Output volume node for the result dose. It is created by \sa CalculateDose
  Q_INVOKABLE QString calculateDoseUsingEngine(vtkMRMLRTBeamNode* beamNode, vtkMRMLScalarVolumeNode* resultDoseVolumeNode);

  /// Define engine-specific beam parameters
  void defineBeamParameters();

private:
  Q_DISABLE_COPY(qSlicerExampleCppDoseEngine);
};

#endif
