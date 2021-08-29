#ifndef B3DetectorConstruction_h
#define B3DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.
///
/// Crystals are positioned in Ring, with an appropriate rotation matrix. 
/// Several copies of Ring are placed in the full detector.

class B3DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    B3DetectorConstruction();
    virtual ~B3DetectorConstruction();

  public:
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();
               
  private:
    void DefineMaterials();

    G4bool  fCheckOverlaps;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

