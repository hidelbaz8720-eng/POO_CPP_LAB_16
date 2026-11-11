
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 1. Interface StrategieTri
class StrategieTri {
public:
    virtual void trier(vector<string>& donnees) = 0;

    virtual ~StrategieTri() {}
};

// 2. Strategie de tri croissant
class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& donnees) override {
        sort(donnees.begin(), donnees.end());
    }
};

// 3. Strategie de tri decroissant
class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& donnees) override {
        sort(donnees.begin(), donnees.end(), greater<string>());
    }
};

// 4. Strategie de tri par longueur
class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& donnees) override {
        sort(donnees.begin(), donnees.end(),
            [](const string& a, const string& b) {
                return a.length() < b.length();
            });
    }
};

// 5. Classe GestionnaireTri
class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    // Constructeur
    GestionnaireTri(StrategieTri* s) {
        strategie = s;
    }

    // Changer de strategie
    void definirStrategie(StrategieTri* s) {
        strategie = s;
    }

    // Executer le tri
    void executerTri(vector<string>& donnees) {
        if (strategie != nullptr) {
            strategie->trier(donnees);
        }
    }
};

// 6. Programme principal
int main() {

    vector<string> mots = {
        "Banane", "Pomme", "Kiwi", "Orange", "Fraise"
    };

    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur longueur;

    GestionnaireTri gestionnaire(&croissant);

    // Tri croissant
    cout << "Tri croissant :" << endl;
    gestionnaire.executerTri(mots);

    for (string mot : mots)
        cout << mot << " ";
    cout << endl;

    // Tri decroissant
    gestionnaire.definirStrategie(&decroissant);

    cout << "\nTri decroissant :" << endl;
    gestionnaire.executerTri(mots);

    for (string mot : mots)
        cout << mot << " ";
    cout << endl;

    // Tri par longueur
    gestionnaire.definirStrategie(&longueur);

    cout << "\nTri par longueur :" << endl;
    gestionnaire.executerTri(mots);

    for (string mot : mots)
        cout << mot << " ";
    cout << endl;

    return 0;
}
