#include "B3aActionInitialization.hh"
#include "B3aRunAction.hh"
#include "B3aEventAction.hh"
#include "B3PrimaryGeneratorAction.hh"
#include "B3StackingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3aActionInitialization::B3aActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3aActionInitialization::~B3aActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B3aActionInitialization::BuildForMaster() const
{
  SetUserAction(new B3aRunAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B3aActionInitialization::Build() const
{
  B3aRunAction* runAction = new B3aRunAction();
  SetUserAction(runAction);

  SetUserAction(new B3aEventAction(runAction));
  SetUserAction(new B3PrimaryGeneratorAction);
  SetUserAction(new B3StackingAction);
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
