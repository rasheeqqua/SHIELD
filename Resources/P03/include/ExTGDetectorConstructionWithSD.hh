#ifndef ExTGDetectorConstructionWithSD_h
#define ExTGDetectorConstructionWithSD_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class G4tgrMessenger;

/// Detector construction class using text geometry file and using a sensitive detector

class ExTGDetectorConstructionWithSD : public G4VUserDetectorConstruction
{
  public:
  
     ExTGDetectorConstructionWithSD();
    ~ExTGDetectorConstructionWithSD();

     G4VPhysicalVolume* Construct();
     void ConstructSDandField();

  private:

     G4tgrMessenger* fMessenger;
};

#endif
