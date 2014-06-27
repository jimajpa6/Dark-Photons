/*
 * Dark Photon Run Action
 * !!!History 
 *    CJC 6.14.15 created
 *
 * file RunAction.cc
 * Description: 
 * Run Action is called for every run. Consider what data should be collected
 * over long runs
 */



#include "RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "Analysis.hh"
#include "G4SystemOfUnits.hh"


//!!!
//Initialize analysis storing i.e. ntuples or histograms
RunAction::RunAction()
  : G4UserRunAction()
{
  //set printing event number for each event
  G4RunManager::GetRunManager()->SetPrintProgress(10000);

  // Data storage and analysis
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  G4cout << "Using" << analysisMan->GetType() << G4endl;
  analysisMan->SetVerboseLevel(2);

  //Creating directories
   analysisMan->SetNtupleDirectoryName("ntuples");
  /*
   analysisMan->CreateH1("2Gamma", 
			 "Photon Hits", 
			 10, 
			 -.5,
			 3., 
			 "none",
			 "none",
			 "linear");


   analysisMan->CreateNtuple("2Gamma", "Photon hits");
   analysisMan->CreateNtupleIColumn("numHits"); // 0
   analysisMan->CreateNtupleDColumn("photon1xPos"); // 1
   analysisMan->CreateNtupleDColumn("photon1yPos"); // 2
   analysisMan->CreateNtupleDColumn("totEnergyPhoton1"); // 3
   analysisMan->CreateNtupleDColumn("photon1xMomentum"); // 4
   analysisMan->CreateNtupleDColumn("photon1yMomentum"); // 5
   analysisMan->CreateNtupleDColumn("photon1zMomentum"); // 6


   analysisMan->CreateNtupleDColumn("photon2xPos"); //7
   analysisMan->CreateNtupleDColumn("photon2yPos"); //8
   analysisMan->CreateNtupleDColumn("totEnergyPhoton2"); // 9
   analysisMan->CreateNtupleDColumn("photon2xMomentum"); // 10
   analysisMan->CreateNtupleDColumn("photon2yMomentum"); // 11
   analysisMan->CreateNtupleDColumn("photon2zMomentum"); // 12
   analysisMan->FinishNtuple();
    */

   analysisMan->CreateNtuple("qanalysis", "Photon Positron");
   analysisMan->CreateNtupleDColumn("Energy_Photon"); // 0
   analysisMan->CreateNtupleDColumn("photon_x_Momentum"); // 1
   analysisMan->CreateNtupleDColumn("photon_y_Momentum"); // 2
   analysisMan->CreateNtupleDColumn("photon_z_Momentum"); // 3

   analysisMan->CreateNtupleDColumn("Energy_Positron"); // 4
   analysisMan->CreateNtupleDColumn("positron_x_Momentum"); // 5
   analysisMan->CreateNtupleDColumn("positron_y_Momentum"); // 6
   analysisMan->CreateNtupleDColumn("positron_z_Momentum"); // 7
   analysisMan->FinishNtuple();
}


//delete your analysis manager
RunAction::~RunAction()
{
  delete G4AnalysisManager::Instance();
}

//!!!
//Data storage
void RunAction::BeginOfRunAction(const G4Run*)
{

  //Save random number seed
  // G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  
  // Data storage and analysis
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
 
  analysisMan->OpenFile("qanalysis");
  

}

//!!!
//Finish and close data file
void RunAction::EndOfRunAction(const G4Run* )
{
  
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  analysisMan->Write();
  analysisMan->CloseFile();
}
