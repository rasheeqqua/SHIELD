#include "ExTGDetectorConstructionWithSD.hh"
#include "ExTGTrackerSD.hh"

#include "G4LogicalVolume.hh"
#include "G4SDManager.hh"

#include "G4tgbVolumeMgr.hh"
#include "G4tgrMessenger.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ExTGDetectorConstructionWithSD::ExTGDetectorConstructionWithSD()
{
  fMessenger = new G4tgrMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ExTGDetectorConstructionWithSD::~ExTGDetectorConstructionWithSD()
{
  delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4VPhysicalVolume* ExTGDetectorConstructionWithSD::Construct()
{
  //------------------------------------------------ 
  // Define one or several text files containing the geometry description
  //------------------------------------------------ 
  G4String filename = "g4geom_SD.txt";
  G4tgbVolumeMgr* volmgr = G4tgbVolumeMgr::GetInstance();
  volmgr->AddTextFile(filename);

  //------------------------------------------------ 
  // Read the text files and construct the GEANT4 geometry
  //------------------------------------------------ 
  G4VPhysicalVolume* physiWorld = volmgr->ReadAndConstructDetector();

  return physiWorld;
}

void ExTGDetectorConstructionWithSD::ConstructSDandField()
{
  //------------------------------------------------ 
  // Sensitive detectors
  //------------------------------------------------ 

  G4String trackerChamberSDname = "ExTextGeom/TrackerChamberSD";
  ExTGTrackerSD* aTrackerSD = new ExTGTrackerSD( trackerChamberSDname );
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
  G4LogicalVolume * logicChamber =
    G4tgbVolumeMgr::GetInstance()->FindG4LogVol("Chamber",0);
  if(logicChamber)
  {
    SetSensitiveDetector("Chamber", aTrackerSD );
  }
  else
  {
    G4Exception("ExTGDetectorConstructionWithSD::Construct()",
                "InvalidGeometry", JustWarning,
                "Volume does not exists in geometry: Chamber");
  }

}
