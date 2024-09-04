*** Settings ***
Library  Process
Library  OperatingSystem

*** Test Cases ***
Clean Project
    Run Process  make  clean


Compile Project Using Make
    Run Process  make  
    Sleep  5s


Run Project and Simulate Key Presses in Parallel
    # Utiliser le script Python pour lancer le jeu et sélectionner l'option SDL
    Run Process  python  game/test/run_game.py  cwd=${CURDIR}  alias=RunGameProcess
    Sleep  2s

    # Lancer le script Python pour simuler les appuis sur les touches en parallèle
    Start Process  python  game/test/move.py  alias=MoveProcess
    Sleep  1s
    
    # Attendre la fin du script move.py
    Wait For Process  MoveProcess
    Log  "Simulation des appuis de touches terminée."
    
    # (Optionnel) Arrêter le jeu après que move.py a terminé
    Terminate Process  RunGameProcess
    
    # Récupérer les logs du processus principal
    ${main_output}=  Get Process Result  RunGameProcess
    Log  ${main_output.stdout}
    
    # Vérifier si des erreurs sont survenues
    ${stderr}=  Get File  game/test/error.log
    Should Be Empty  ${stderr}
    Log  "Pas d'erreurs dans le jeu."


# Run Project and Simulate Key Presses in Parallel
#     # Lancer le jeu (./main)
#     Start Process  ./main  cwd=C:\\Users\\walid\\OneDrive\\Bureau\\la-plateforme\\B2\\devoirs\\C++\\CPPSDL  stdout=game\\test\\moveTest  stderr=game\\test\\error.log  alias=MainProcess
    
#     # Ajouter une attente pour s'assurer que le jeu est bien lancé
#     Sleep  2s
    
#     # Lancer le script Python pour simuler les appuis sur les touches en parallèle
#     ${result}=  Run Process  python  game\\test\\move.py  alias=MoveProcess
#     Log  ${result.stdout}

#     # Attendre la fin du script move.py
#     Wait For Process  MoveProcess
    
#     # (Optionnel) Vous pouvez aussi arrêter le jeu après que move.py a terminé
#     Terminate Process  MainProcess
    
#     # Récupérer les logs du processus principal
#     ${main_output}=  Get Process Result  MainProcess
#     Log  ${main_output.stdout}
    
#     # Vous pouvez également vérifier si le processus principal est toujours en cours d'exécution
#     # ${status}=  Process Should Be Running  MainProcess
#     # Log  ${status} 





