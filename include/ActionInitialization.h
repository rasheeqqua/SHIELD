#ifndef SHIELD_ACTIONINITIALIZATION_H
#define SHIELD_ACTIONINITIALIZATION_H


//----------------------------------//
#include "globals.hh"
#include "G4VUserActionInitialization.hh"
//----------------------------------//


//----------------------------------//
class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization();
    virtual ~ActionInitialization();
    
    virtual void BuildForMaster() const;
    virtual void Build() const;
};
//----------------------------------//

#endif
