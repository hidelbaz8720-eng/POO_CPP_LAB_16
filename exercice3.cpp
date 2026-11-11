
#include <iostream>
#include <vector>
using namespace std;

// 1. Interface Observateur
class Observateur {
public:
    virtual void mettreAJour(
        float temperature,
        float humidite,
        float pression
    ) = 0;

    virtual ~Observateur() {}
};

// 2. Classe AffichageTemperature
class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float temperature,
                     float humidite,
                     float pression) override {

        cout << "Temperature : " << temperature << " C" << endl;
    }
};

// 3. Classe AffichageHumidite
class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float temperature,
                     float humidite,
                     float pression) override {

        cout << "Humidite : " << humidite << " %" << endl;
    }
};

// 4. Classe AffichagePression
class AffichagePression : public Observateur {
public:
    void mettreAJour(float temperature,
                     float humidite,
                     float pression) override {

        cout << "Pression : " << pression << " hPa" << endl;
    }
};

// 5. Classe StationMeteo (Sujet)
class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;

    vector<Observateur*> observateurs;

public:

    // Ajouter un observateur
    void ajouterObservateur(Observateur* obs) {
        observateurs.push_back(obs);
    }

    // Supprimer un observateur
    void supprimerObservateur(Observateur* obs) {

        for (int i = 0; i < observateurs.size(); i++) {
            if (observateurs[i] == obs) {
                observateurs.erase(observateurs.begin() + i);
                break;
            }
        }
    }

    // Notifier tous les observateurs
    void notifierObservateurs() {

        for (Observateur* obs : observateurs) {
            obs->mettreAJour(
                temperature,
                humidite,
                pression
            );
        }
    }

    // Modifier les donnees meteorologiques
    void definirMesures(float temp, float hum, float pres) {

        temperature = temp;
        humidite = hum;
        pression = pres;

        cout << "\n--- Mise a jour de la station ---" << endl;

        notifierObservateurs();
    }
};

// 6. Programme principal
int main() {

    StationMeteo station;

    AffichageTemperature affichageTemp;
    AffichageHumidite affichageHum;
    AffichagePression affichagePres;

    // Inscrire les observateurs
    station.ajouterObservateur(&affichageTemp);
    station.ajouterObservateur(&affichageHum);
    station.ajouterObservateur(&affichagePres);

    // Premiere mise a jour
    station.definirMesures(25.5, 60, 1013);

    // Deuxieme mise a jour
    station.definirMesures(28.0, 55, 1010);

    // Supprimer un observateur
    station.supprimerObservateur(&affichageHum);

    // Troisieme mise a jour
    station.definirMesures(30.0, 50, 1008);

    return 0;
}
