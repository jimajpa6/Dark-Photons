//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
// 
//
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"

#include "B2Calorimeter.hh"
#include "G4HCofThisEvent.hh"

B2Calorimeter::B2Calorimeter(const G4String& name)
  :G4VSensitiveDetector(name)
{
  collectionName.insert("CalorimeterCollection");
  fHitsCollectionID = -1;
}

B2Calorimeter::~B2Calorimeter() {}

void B2Calorimeter::Initialize(G4HCofThisEvent* hitsCollectionOfThisEvent)
{
  //Create a new collection
fHitsCollection = 
  new B2CalorimeterHitsCollection(SensitiveDetectorName, collectionName[0]);

 if (fHitsCollectionID<0)
   fHitsCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);

 //Add collection to event
 hitsCollectionOfThisEvent->AddHitsCollection(fHitsCollectionID, fHitsCollection);

 //Initialize Hits
 G4int i(0);

 for (i=0; i<100; i++){
   B2CalorimeterHit* aHit = new B2CalorimeterHit(i);
   fHitsCollection->insert(aHit);
 }
}

G4bool B2Calorimeter::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
  //Energy Deposited
  G4double depositedEnergy = aStep->GetTotalEnergyDeposit();
  if ( 0 == depositedEnergy ){
    return true; }

  //Volume and copy number
  G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
  G4TouchableHistory* theTouchable = (G4TouchableHistory*)(preStepPoint->GetTouchable());

  G4VPhysicalVolume* thePhysical = theTouchable->GetVolume();
  G4int copyNo = thePhysical->GetCopyNo();

  //Hit
  B2CalorimeterHit* aHit = (*fHitsCollection)[copyNo];
  if (!(aHit->GetLogicalVolume())) {

    //Set Volume Information
    aHit->SetLogicalVolume(thePhysical->GetLogicalVolume());

    G4AffineTransform aTrans = theTouchable->GetHistory()->GetTopTransform();
    aTrans.Invert();

    aHit->SetRotation(aTrans.NetRotation());
    aHit->SetPosition(aTrans.NetTranslation());
  }

  // Accumulate energy deposition
  aHit->AddDepositedEnergy(depositedEnergy);


  return true;
}

void B2Calorimeter::EndOfEvent(G4HCofThisEvent*) {}
