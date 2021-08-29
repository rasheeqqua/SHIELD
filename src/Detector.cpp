//----------------------------------//
#include "Detector.h"

#include "G4LogicalVolume.hh"
#include "G4SDManager.hh"

#include "G4tgbVolumeMgr.hh"
#include "G4tgrMessenger.hh"

#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSDoseDeposit.hh"
#include "G4PSEnergyDeposit.hh"

#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
//----------------------------------//

//----------------------------------//
DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction()
{
	fMessenger = new G4tgrMessenger;
}


DetectorConstruction::~DetectorConstruction()
{
	delete fMessenger;
}
//----------------------------------//

//----------------------------------//
G4VPhysicalVolume* DetectorConstruction::Construct()
{
    //------------------------------------------------ 
  // Define one or several text files containing the geometry description
  //------------------------------------------------ 
  G4String filename = "Geometry.txt";
  G4tgbVolumeMgr* volmgr = G4tgbVolumeMgr::GetInstance();
  volmgr->AddTextFile(filename);

  //------------------------------------------------ 
  // Read the text files and construct the GEANT4 geometry
  //------------------------------------------------ 
  G4VPhysicalVolume* physiWorld = volmgr->ReadAndConstructDetector();

  return physiWorld;
}

void DetectorConstruction::ConstructSDandField()
{
	G4SDManager::GetSDMpointer()->SetVerboseLevel(1);
	
	G4MultiFunctionalDetector* detect_energy = new G4MultiFunctionalDetector("Detect_energy");
	G4SDManager::GetSDMpointer()->AddNewDetector(detect_energy);
	G4VPrimitiveScorer* primitiv_energy = new G4PSEnergyDeposit("edep");
	detect_energy->RegisterPrimitive(primitiv_energy);
	SetSensitiveDetector("Detector",detect_energy);
	
	G4MultiFunctionalDetector* detect = new G4MultiFunctionalDetector("Detect");
	G4SDManager::GetSDMpointer()->AddNewDetector(detect);
	G4VPrimitiveScorer* primitiv = new G4PSDoseDeposit("dose");
	detect->RegisterPrimitive(primitiv);
	SetSensitiveDetector("Detector",detect);
}
