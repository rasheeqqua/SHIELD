#ifndef B3aRunAction_h
#define B3aRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"

/// Run action class

class B3aRunAction : public G4UserRunAction
{
  public:
    B3aRunAction();
    virtual ~B3aRunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);

    void CountEvent()           { fGoodEvents += 1; };
    void SumDose(G4double dose) { fSumDose += dose; };  

private:
    G4Accumulable<G4int>    fGoodEvents;
    G4Accumulable<G4double> fSumDose;  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

