
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    // Parametres de configuration
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    // Constructeur prive
    Configuration() {
        cheminFichier = "C:/Application/config.txt";
        utilisateur = "Hamza";
        motDePasse = "123456";
    }

public:
    // Supprimer le constructeur de copie
    Configuration(const Configuration&) = delete;

    // Supprimer l'operateur d'affectation
    Configuration& operator=(const Configuration&) = delete;

    // Methode statique pour obtenir l'unique instance
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    // Afficher les parametres
    void afficherParametres() {
        cout << "=== Configuration ===" << endl;
        cout << "Chemin du fichier : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

int main() {

    // Obtenir l'unique instance
    Configuration& config1 = Configuration::getInstance();

    config1.afficherParametres();

    // Obtenir une deuxieme reference
    Configuration& config2 = Configuration::getInstance();

    // Verifier que les deux references designent le meme objet
    if (&config1 == &config2) {
        cout << "\nLes deux references utilisent la meme instance."
             << endl;
    }

    return 0;
}
