/*
 * Dark Photon Event Action
 *!!!History
 *   CJC 6.15.14 created
 *   CJC 6.16.14 analysis added
 *
 * file: EventAction.cc
 *
 * Description: 
 * Event Action method is called after every event. We are using it 
 * to store data from event to event in large runs.
 * Methods to update:
 *
 * BeginOfEventAction
 * {Reset the variables you want to keep track of}
 *
 * EndOfEventAction
 * {fill all of the data storage methods with the analysis manager, 
 * i.e. histograms or ntuples. Also include whatever verbose arguments
 * you want in your final read out.}
 *
 * 
 */

#include "EventAction.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include <iomanip>

#include "Analysis.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "G4SDManager.hh"

#include "CalorHit.hh"

EventAction::EventAction()
  : G4UserEventAction()
{}


EventAction::~EventAction()
{}

//!!!
//Reset your variables
void EventAction::BeginOfEventAction(const G4Event* run)
{
  G4cout << "Being of Event Action" << G4endl;

}

//!!!
//Fill your data analysis
//Add verbosity
void EventAction::EndOfEventAction(const G4Event* event)
{
  G4cout << "End of Event Action" << G4endl;
  
  G4HCofThisEvent* hce = event->GetHCofThisEvent(); //hit collection array allows for several kinds of hits

  //analysis manager
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  G4SDManager* fSDM = G4SDManager::GetSDMpointer();

  //get ID for the calorimeter's hit collection
  G4int collectionID = fSDM->GetCollectionID("CalorimeterHitsCollection");

  CalorimeterHitsCollection* hitColl = static_cast<CalorimeterHitsCollection*>(hce->GetHC(collectionID));

  G4int numHits = hitColl->entries();
  
  analysisMan->FillNtupleIColumn(0, numHits);
  
  for (G4int i=0; (i<numHits) && (i<2); i++)
    {
      CalorHit* newHit = (*hitColl)[i];
      G4ThreeVector position = newHit->GetPos();
      analysisMan->FillNtupleDColumn(1+(i*3), position.x());
      analysisMan->FillNtupleDColumn(2+(i*3), position.y());
      G4double totEnergy = newHit->GetTotalEnergy();
      analysisMan->FillNtupleDColumn(3+(i*3), totEnergy);
}

  analysisMan->AddNtupleRow();
  




}

