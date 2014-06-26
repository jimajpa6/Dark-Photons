//==========================================================================
// This file has been automatically generated for Pythia 8 by
// MadGraph5_aMC@NLO v. 2.1.1, 2014-03-31
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
// File based on main25.cc in Pythia 8.149
//==========================================================================

#include "Pythia.h"
#include "Sigma_sm_ll_all.h"

using namespace Pythia8; 

int main() 
{

  // Number of events to generate and to list. Max number of errors.
  // Warning: generation of complete events is much slower than if you use
  // PartonLevel:all = off to only get cross sections, so adjust nEvent.
  int nEvent = 3000; 
  int nList = 1; 
  int nAbort = 5; 

  // Pythia generator.
  Pythia pythia; 

  // Read param_card file
  pythia.readString("SLHA:file = ../Processes_sm/param_card_sm.dat"); 

  // Provide process pointers to Pythia
  pythia.setSigmaPtr(new Sigma_sm_ll_all()); 

  // Phase space cut on pThat.
  pythia.readString("PhaseSpace:pTHatMin = 20."); 

  // Optionally only compare cross sections.
  pythia.readString("PartonLevel:all = off"); 

  // Initialization for LHC.
  pythia.init(2212, 2212, 14000.); 

  // List changes.
  pythia.settings.listChanged(); 
  pythia.particleData.listChanged(); 

  // Begin event loop.
  int iAbort = 0; 
  for (int iEvent = 0; iEvent < nEvent; ++ iEvent)
  {
    if (iEvent%(max(1, nEvent/20)) == 0)
      cout <<  " Now begin event " << iEvent <<  "\n"; 

    // Generate events. Quit if many failures.
    if ( !pythia.next())
    {
      if (++ iAbort < nAbort)
        continue; 
      cout <<  " Event generation aborted prematurely, owing to error!\n"; 
      break; 
    }

    // List first few events.
    if (iEvent < nList)
    {
      pythia.info.list(); 
      pythia.process.list(); 
      pythia.event.list(); 
    }

    // End of event loop.
  }

  // Final statistics.
  pythia.statistics(); 

  // Done.
  return 0; 
}

