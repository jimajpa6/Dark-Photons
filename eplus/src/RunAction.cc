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
  G4RunManager::GetRunManager()->SetPrintProgress(1);

  // Data storage and analysis
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  G4cout << "Using" << analysisMan->GetType() << G4endl;
  analysisMan->SetVerboseLevel(2);

  //Creating directories
   analysisMan->SetNtupleDirectoryName("ntuples");

   analysisMan->CreateH1("2Gamma", 
			 "Photon Hits", 
			 100, 
			 0.,
			 100.0, 
			 "none",
			 "none",
			 "linear");


   analysisMan->CreateNtuple("2Gamma", "Photon hits");
   analysisMan->CreateNtupleIColumn("Number of hits"); // 0
   analysisMan->CreateNtupleDColumn("X Position Photon1"); // 1
   analysisMan->CreateNtupleDColumn("Y Position Photon1"); // 2
   analysisMan->CreateNtupleDColumn("Total Energy Per Photon1"); // 3
   analysisMan->CreateNtupleDColumn("X Position Photon2"); //4
   analysisMan->CreateNtupleDColumn("Y Position Photon2"); //5
   analysisMan->CreateNtupleDColumn("Total Energy Per Photon2"); // 6
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
 
   analysisMan->OpenFile("2Gamma");

}

//!!!
//Finish and close data file
void RunAction::EndOfRunAction(const G4Run* )
{
  
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  analysisMan->Write();
  analysisMan->CloseFile();
}
