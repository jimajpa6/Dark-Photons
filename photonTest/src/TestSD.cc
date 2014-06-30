/*
 *Dark Photon Calorimeter SD
 *
 *!!!History
 *   CJC 6.17.14 created
 *   CJC 6.23.14 updated for multiple crystal calorimeter
 */

#include "TestSD.hh"

#include "G4HCofThisEvent.hh"
#include "G4ParticleDefinition.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4SystemOfUnits.hh"
#include "G4Colour.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

TestSD::TestSD(const G4String& name,
			   const G4String& hitsCollectionName)
  : G4VSensitiveDetector(name), 
    fHitsCollection(NULL),
    fHCID(-1)
{
  collectionName.insert(hitsCollectionName);
}


TestSD::~TestSD()
{
}

void TestSD::Initialize(G4HCofThisEvent* hce)
{
  //Create hits collection

fHitsCollection = 
  new TestHitsCollection(SensitiveDetectorName, collectionName[0]);

//Add collection in hit collection of the event

G4int hceID = 
  G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
 hce -> AddHitsCollection( hceID, fHitsCollection);

 for(G4int i=0; i<900; i++)
   {
     TestHit* hit = new TestHit(i);
     fHitsCollection->insert(hit); 
   }

}

G4bool TestSD::ProcessHits(G4Step* step, 
				  G4TouchableHistory* )
{
  G4double edep = step->GetTotalEnergyDeposit();
  if (edep==0.) return true;

  G4int copyNo = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber(1);
  G4int replicaNo = step->GetPreStepPoint()->GetTouchableHandle()->GetReplicaNumber(); 

  if (copyNo<1) return true;

  TestHit* hit = (*fHitsCollection)[(copyNo-1)*30+replicaNo]; 

  if(!(hit->GetLogV()))
    {
      hit->SetLogV(step->GetPreStepPoint()->GetTouchable()->GetVolume()
		   ->GetLogicalVolume());
    }

  hit->AddEdep(edep);
  hit->SetPos(step->GetPostStepPoint()->GetPosition());

  return true;
}





