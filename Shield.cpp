//----------------------------------//
#include "Detector.h"
#include "ActionInitialization.h"

#include "PhysicsList.h"
#include "Analysis.h"
//----------------------------------//


//----------------------------------//
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
//----------------------------------//


//----------------------------------//
#include "G4UImanager.hh"
#include "G4SystemOfUnits.hh"

#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

#include "Randomize.hh"

#include "G4ScoringManager.hh"
#include "G4Types.hh"
#include "G4TScoreNtupleWriter.hh"
//----------------------------------//


int main(int argc,char** argv)
{
    // Instantiate G4UIExecutive if there are no arguments (interactive mode)
    G4UIExecutive* ui = nullptr;
    if (argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    }
    //----------------------------------//


    //choose the Random engine
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    //----------------------------------//


    // Run manager
#ifdef G4MULTITHREADED
    G4MTRunManager * runManager = new G4MTRunManager;
#else
    G4RunManager * runManager = new G4RunManager;
#endif
    //----------------------------------//
    
    //----------------------------------//
    G4ScoringManager * scoringManager = G4ScoringManager::GetScoringManager();
    scoringManager->SetVerboseLevel(1);
    //----------------------------------//


    //----------------------------------//
    runManager->SetUserInitialization(new DetectorConstruction);

    runManager->SetUserInitialization(new PhysicsList);
    //----------------------------------//


    //Visualization
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    //----------------------------------//


    // UserAction classes
    runManager->SetUserInitialization(new ActionInitialization());
    //----------------------------------//


    //Initialize G4 kernel
    runManager->Initialize();
    //----------------------------------//


    //Get the pointer to the User Interface manager
    G4UImanager * pUI = G4UImanager::GetUIpointer();
    
    G4TScoreNtupleWriter<G4AnalysisManager> scoreNtupleWriter;
    scoreNtupleWriter.SetVerboseLevel(1);

    if(ui)
    {
        pUI->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    }
    else
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        pUI->ApplyCommand(command+fileName);
    }
    //----------------------------------//


    //----------------------------------//
    delete visManager;
    delete runManager;
    //----------------------------------//

    return 0;
}
