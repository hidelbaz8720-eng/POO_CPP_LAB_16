
#include <iostream>
#include <string>
using namespace std;

// 1. Classe abstraite Forme
class Forme {
public:
    virtual void afficher() = 0;

    virtual ~Forme() {}
};

// 2. Classe Cercle
class Cercle : public Forme {
public:
    void afficher() override {
        cout << "Je suis un Cercle." << endl;
    }
};

// 3. Classe Carre
class Carre : public Forme {
public:
    void afficher() override {
        cout << "Je suis un Carre." << endl;
    }
};

// 4. Classe Triangle
class Triangle : public Forme {
public:
    void afficher() override {
        cout << "Je suis un Triangle." << endl;
    }
};

// 5. Classe FabriqueForme
class FabriqueForme {
public:
    static Forme* creerForme(string type) {

        if (type == "cercle") {
            return new Cercle();
        }
        else if (type == "carre") {
            return new Carre();
        }
        else if (type == "triangle") {
            return new Triangle();
        }
        else {
            return nullptr;
        }
    }
};

// 6. Programme principal
int main() {

    Forme* forme1 = FabriqueForme::creerForme("cercle");
    Forme* forme2 = FabriqueForme::creerForme("carre");
    Forme* forme3 = FabriqueForme::creerForme("triangle");

    if (forme1 != nullptr)
        forme1->afficher();

    if (forme2 != nullptr)
        forme2->afficher();

    if (forme3 != nullptr)
        forme3->afficher();

    // Liberer la memoire
    delete forme1;
    delete forme2;
    delete forme3;

    return 0;
}
