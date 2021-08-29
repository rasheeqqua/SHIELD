#ifndef SHIELD_SOURCE_H
#define SHIELD_SOURCE_H
//----------------------------------//
#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
//----------------------------------//
//----------------------------------//
class G4GeneralParticleSource;
class G4Event;
//----------------------------------//
//----------------------------------//
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*);
private:
    G4GeneralParticleSource* fParticleGun;
};
//----------------------------------//
#endif
