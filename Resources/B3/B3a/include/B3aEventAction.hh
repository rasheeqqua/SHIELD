#ifndef B3aEventAction_h
#define B3aEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class B3aRunAction;

/// Event action class
///
/// In EndOfEventAction() there is collected information event per event 
/// from Hits Collections, and accumulated statistic for 
/// B3RunAction::EndOfRunAction().

class B3aEventAction : public G4UserEventAction
{
  public:
    B3aEventAction(B3aRunAction* runAction);
    virtual ~B3aEventAction();

    virtual void  BeginOfEventAction(const G4Event*);
    virtual void    EndOfEventAction(const G4Event*);
    
  private:
    B3aRunAction*  fRunAction;
    G4int fCollID_cryst;
    G4int fCollID_patient;   
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
