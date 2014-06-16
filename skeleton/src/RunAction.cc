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
  //set printing event number for each 100 events
  G4RunManager::GetRunManager()->SetPrintProgress(1000);

  //Analysis

  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  analysisMan ->SetFirstHistoId(0); //first id is 0
  /*
   *Example how to create an N tuple
analysisMan->CreateNtuple("Two Gamma Annihilation:, "Photon hits");
analysisMan->CreateNtupleIColumn("Number of hits");
analysisMan->FinishNtuple();
  */

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
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  /*
  //Data storage
  G4AnalysisManager* analysisMan = G4AnalysisManager::Instace();

  //Open an output root file
  //formatting of file can be changed in Analysis.hh
   G4String fileName = "Two Gamma Annihilation";
  analysisMan->OpenFile(fileName);
  */

}

//!!!
//Finish and close data file
void RunAction::EndOfRunAction(const G4Run* )
{

  G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
  analysisMan->Write();
  analysisMan->CloseFile();

}
