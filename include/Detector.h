#ifndef SHIELD_DETECTOR_H
#define SHIELD_DETECTOR_H

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class G4tgrMessenger;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
     DetectorConstruction();
     virtual ~DetectorConstruction();

     virtual G4VPhysicalVolume* Construct();
     virtual void ConstructSDandField();

  private:

     G4tgrMessenger* fMessenger;
};

#endif
