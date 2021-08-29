//----------------------------------//
#include "ActionInitialization.h"
#include "Source.h"
#include "RunAction.h"
#include "EventAction.h"
//----------------------------------//


//----------------------------------//
ActionInitialization::ActionInitialization() : G4VUserActionInitialization()
{}


ActionInitialization::~ActionInitialization()
{}
//----------------------------------//

//----------------------------------//
void ActionInitialization::BuildForMaster() const
{
  SetUserAction(new RunAction());
}

void ActionInitialization::Build() const
{
    RunAction* runAction = new RunAction();
    SetUserAction(runAction);
    
    SetUserAction(new EventAction(runAction));
    SetUserAction(new PrimaryGeneratorAction);
}
//----------------------------------//
