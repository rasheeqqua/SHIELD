#ifndef SHIELD_EVENTACTION_H
#define SHIELD_EVENTACTION_H

//----------------------------------//
#include "G4UserEventAction.hh"
#include "globals.hh"
//----------------------------------//

//----------------------------------//
class RunAction;

class EventAction : public G4UserEventAction
{
public:
	EventAction(RunAction* runAction);
	virtual ~EventAction();
	
	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);
	
private:
	RunAction* fRunAction;
	G4int fID_detect_dose;
	G4int fID_detect_energy;
};
//----------------------------------//

#endif
