//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: CellParameterisation.hh 76474 2013-11-11 10:36:34Z gcosmo $
//
/// \file CellParameterisation.hh
/// \brief Definition of the CellParameterisation class

#ifndef CellParameterisation_H
#define CellParameterisation_H 1

#include "globals.hh"
#include "G4VPVParameterisation.hh"
class G4VPhysicalVolume;

/// EM Calorimeter cell parameterisation

class CellParameterisation : public G4VPVParameterisation
{
public:
    CellParameterisation();
  CellParameterisation(G4int region);
    virtual ~CellParameterisation();
    
    virtual void ComputeTransformation(
                   const G4int copyNo,G4VPhysicalVolume *physVol) const;
    
private:
    G4double fXCell[396];
    G4double fYCell[396];
    G4int fRegion; 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
