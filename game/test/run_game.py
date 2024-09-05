import pexpect

def run_game():
    # Lancer le programme ./main
    process = pexpect.spawn('./main')

    # Attendre l'invite de sélection
    process.expect("Choisissez une option:")

    # Envoyer l'entrée '2'
    process.sendline('2')
    process.sendline('2')

    # Capturer la sortie pour vérification ou journalisation
    process.interact()

if __name__ == "__main__":
    run_game()
