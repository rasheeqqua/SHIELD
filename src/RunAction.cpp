#include "RunAction.h"
#include "Source.h"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction() : G4UserRunAction(),
fSumDose(0.), fSumEnergy(0.)
{
	const G4double milligray = 1.e-3*gray;
	const G4double microgray = 1.e-6*gray;
	const G4double nanogray  = 1.e-9*gray;  
	const G4double picogray  = 1.e-12*gray;
   
	new G4UnitDefinition("milligray", "milliGy" , "Dose", milligray);
	new G4UnitDefinition("microgray", "microGy" , "Dose", microgray);
	new G4UnitDefinition("nanogray" , "nanoGy"  , "Dose", nanogray);
	new G4UnitDefinition("picogray" , "picoGy"  , "Dose", picogray);
	
	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->RegisterAccumulable(fSumEnergy);
	accumulableManager->RegisterAccumulable(fSumDose);
}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run*)
{
	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->Reset();
	
	G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}

void RunAction::EndOfRunAction(const G4Run*)
{
	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->Merge();
	
	if (IsMaster())
		{
			G4cout
			<< G4endl
			<< "--------------------End of Global Run-----------------------";
		}
	else
		{
			G4cout
			<< G4endl
			<< "--------------------End of Local Run------------------------";
		}      
	G4cout
	<< "\n Accumulated energy in detector : " << G4BestUnit(fSumEnergy.GetValue(),"Energy")
        << "\n Total dose in detector : " << G4BestUnit(fSumDose.GetValue(),"Dose") 
        << G4endl 
        << "------------------------------------------------------------" << G4endl 
        << G4endl;
}
