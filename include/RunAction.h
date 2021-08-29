#ifndef SHIELD_RUNACTION_H
#define SHIELD_RUNACTION_H

//----------------------------------//
#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"
//----------------------------------//

//----------------------------------//
class RunAction : public G4UserRunAction
{
public:
	RunAction();
	virtual ~RunAction();
	
	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
	
	void SumDose(G4double dose)
	{fSumDose += dose;}
	
	void SumEnergy (G4double energy)
	{fSumEnergy += energy;}
	
private:
	G4Accumulable<G4double>fSumDose;
	G4Accumulable<G4double>fSumEnergy;
};
//----------------------------------//

#endif
