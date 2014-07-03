/*
 *Dark Photon Detector Construction
 *!!!History
 * CJC 6.15.14 created
 *
 */

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "tls.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class G4UserLimits;
class G4GlobalMagFieldMessenger;

class DetectorMessenger;

/*
 * Detector definition includes information regarding
 * materials, calorimeters, regions of space
 * fields, or geometry in general
 */

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  virtual ~DetectorConstruction();

public:
  //constructs the geometries
  virtual G4VPhysicalVolume* Construct();
  //applies the sensitive detectors
  virtual void ConstructSDandField();

  //set methods
  //!!!
  void SetTargetMaterial (G4String );
  void SetCalorMaterial (G4String );
  void SetMaxStep(G4double );
  void SetCheckOverlaps(G4bool );

  const G4VPhysicalVolume* GetTargetPV() const;
  const G4VPhysicalVolume* GetVetoPV() const;


private:
  //methods
  void DefineMaterials(); //defines materials for elements of the detector
  G4VPhysicalVolume* DefineVolumes(); //defines geometry

  //data members
  G4LogicalVolume* fLogicField; //pointer to logical field volumn
  G4LogicalVolume* fLogicCalor; //pointer to calorimeter
  G4LogicalVolume* fLogicTarget; //pointer to logical target
  G4LogicalVolume* fLogicVeto; //pointer to logical target

  G4VPhysicalVolume* fPhysicalTarget;
  G4VPhysicalVolume* fPhysicalField;
  G4VPhysicalVolume* fPhysicalVeto;

  G4Material* fTargetMaterial; // pointer to target material
  G4Material* fCalorMaterial; // pointer to calorimeter material
  G4Material* fWorldMaterial; // pointer to world material

  G4UserLimits* fStepLimit; // pointer to user step limits

  DetectorMessenger* fMessenger; // messenger

  G4bool fCheckOverlaps; // option to turn on or off overlap checking.

  static G4ThreadLocal G4GlobalMagFieldMessenger* fMagFieldMessenger;


};

inline const G4VPhysicalVolume* DetectorConstruction::GetTargetPV() const { 
  return fPhysicalTarget; 
}

inline const G4VPhysicalVolume* DetectorConstruction::GetVetoPV() const { 
  return fPhysicalVeto; 
}

#endif
