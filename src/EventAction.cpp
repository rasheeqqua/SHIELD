#include "EventAction.h"
#include "RunAction.h"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4THitsMap.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

EventAction::EventAction(RunAction* runAction) : G4UserEventAction(),
fRunAction(runAction), fID_detect_dose(-1), fID_detect_energy(-1)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{}

void EventAction::EndOfEventAction(const G4Event* evt)
{
G4HCofThisEvent* HCE = evt->GetHCofThisEvent();

if(!HCE)
	return;
	
if(fID_detect_energy < 0)
	{
		G4SDManager* SDMan = G4SDManager::GetSDMpointer();
		fID_detect_energy = SDMan->GetCollectionID("Detect_energy/edep");
		fID_detect_dose = SDMan->GetCollectionID("Detect/dose");
	}
	
G4double energy = 0;

G4THitsMap<G4double>*evtMap = (G4THitsMap<G4double>*)(HCE->GetHC(fID_detect_energy));

std::map<G4int,G4double*>::iterator itr;

for(itr = evtMap->GetMap()->begin(); itr != evtMap->GetMap()->end(); itr++)
	{
		G4int eventNo = (itr->first);
		energy = *(itr->second);
		G4cout << "\n Event " << eventNo << " : " << energy/MeV << " MeV";
	}
	if (energy > 0)
		fRunAction->SumEnergy(energy);

G4double dose = 0;

evtMap = (G4THitsMap<G4double>*)(HCE->GetHC(fID_detect_dose));

for(itr = evtMap->GetMap()->begin(); itr != evtMap->GetMap()->end(); itr++)
	{
		dose = *(itr->second);
	}
	if (dose > 0)
		fRunAction->SumDose(dose);
}
