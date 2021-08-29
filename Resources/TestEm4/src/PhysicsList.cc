#include "PhysicsList.h"

#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4SystemOfUnits.hh"


PhysicsList::PhysicsList() : G4VUserPhysicsList()
{
  defaultCutValue = 1.0*mm;
  SetVerboseLevel(1);
}


PhysicsList::~PhysicsList()
{}


void PhysicsList::ConstructParticle()
{
  ConstructBosons();
  ConstructLeptons();
  G4GenericIon::GenericIonDefinition();
}


void PhysicsList::ConstructBosons()
{
  G4Gamma::GammaDefinition();
}


void PhysicsList::ConstructLeptons()
{
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
}


void PhysicsList::ConstructProcess()
{
  AddTransportation();
  ConstructEM();
}


#include "G4PhysicsListHelper.hh"

#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"

#include "G4eMultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"


void PhysicsList::ConstructEM()
{
  G4PhysicsListHelper* ph = G4PhysicsListHelper::GetPhysicsListHelper();
  
  auto particleIterator=GetParticleIterator();
  particleIterator->reset();

  while( (*particleIterator)() )
  {
    G4ParticleDefinition* particle = particleIterator->value();
    G4String particleName = particle->GetParticleName();
     
    if (particleName == "gamma")
    {
      ph->RegisterProcess(new G4PhotoElectricEffect, particle);
      ph->RegisterProcess(new G4ComptonScattering,   particle);
      ph->RegisterProcess(new G4GammaConversion,     particle);
      
    }
    else if (particleName == "e-")
    {
      ph->RegisterProcess(new G4eMultipleScattering, particle);
      ph->RegisterProcess(new G4eIonisation,         particle);
      ph->RegisterProcess(new G4eBremsstrahlung,     particle);      

    }
    else if (particleName == "e+")
    {
      ph->RegisterProcess(new G4eMultipleScattering, particle);
      ph->RegisterProcess(new G4eIonisation,         particle);
      ph->RegisterProcess(new G4eBremsstrahlung,     particle);
      ph->RegisterProcess(new G4eplusAnnihilation,   particle);      
    }
  }
}


void PhysicsList::SetCuts()
{
  if (verboseLevel >0)
  {
    G4cout << "PhysicsList::SetCuts:";
    G4cout << "CutLength : " << defaultCutValue/mm << " (mm)" << G4endl;
  }

  SetCutValue(defaultCutValue, "gamma");
  SetCutValue(defaultCutValue, "e-");
  SetCutValue(defaultCutValue, "e+");
}