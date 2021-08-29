#ifndef SHIELD_PHYSICSLIST_H
#define SHIELD_PHYSICSLIST_H

#include "G4VUserPhysicsList.hh"
#include "globals.hh"


class PhysicsList: public G4VUserPhysicsList
{
public:
    PhysicsList();
   ~PhysicsList();

protected:
    virtual void ConstructParticle();
    virtual void ConstructProcess();
 
    virtual void SetCuts();
    
protected:
    void ConstructBosons();
    void ConstructLeptons();

protected:
    void ConstructGeneral();
    void ConstructEM();
    
};


#endif
