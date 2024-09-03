import subprocess
import time

# Démarrer le processus du jeu
process = subprocess.Popen('./main', stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, cwd=r'C:\Users\walid\OneDrive\Bureau\la-plateforme\B2\devoirs\C++\CPPSDL')

# Liste des commandes à envoyer au jeu
commands = ['up', 'right', 'down', 'left', 'exit']

# Envoyer les commandes
for command in commands:
    process.stdin.write(command + '\n')
    process.stdin.flush()  # S'assurer que la commande est envoyée
    time.sleep(1)  # Attendre un peu pour que le jeu puisse réagir

# Fermer l'entrée pour signaler la fin des commandes
process.stdin.close()

# Attendre que le processus se termine
output, error = process.communicate(timeout=10)

# Vérifier si le processus s'est bien terminé
if process.returncode is not None:
    print("Le processus s'est terminé correctement.")
else:
    print("Le processus est toujours en cours, tentative de le terminer.")
    process.terminate()

# Enregistrer la sortie du jeu dans un fichier
with open('game_output.txt', 'w') as f:
    f.write(output)

# Afficher la sortie pour vérification
print(output)
