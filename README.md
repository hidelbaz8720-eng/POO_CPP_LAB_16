# TP 16 – Patrons de conception (Design Patterns) en C++

##  Présentation

Ce TP porte sur les patrons de conception (*Design Patterns*) en programmation orientée objet avec C++.

L'objectif est de comprendre et de mettre en pratique quatre patrons de conception permettant d'améliorer l'organisation, la réutilisabilité, la flexibilité et la maintenabilité du code.

**Formation :** Programmation orientée objet : C++  
**Plateforme :** MLIAEdu  
**Progression :** 100 %

---

##  Objectifs pédagogiques

- Comprendre le principe des patrons de conception.
- Appliquer les concepts de l'héritage et du polymorphisme.
- Utiliser les classes abstraites et les méthodes virtuelles.
- Maîtriser la création dynamique des objets.
- Améliorer la modularité et la réutilisabilité du code.

---

##  Contenu du TP

### Exercice 1 : Singleton

**Objectif :** Garantir qu'une classe possède une seule instance dans toute l'application.

**Classe principale :** `Configuration`

Concepts utilisés :
- Constructeur privé.
- Méthode statique `getInstance()`.
- Suppression du constructeur de copie avec `= delete`.
- Instance statique locale.
<img width="1366" height="768" alt="ex1" src="https://github.com/user-attachments/assets/62237abf-aaef-4037-841b-61bd7421fc81" />

**Résultat :** Les différents appels à `getInstance()` retournent la même instance.

### Exercice 2 : Factory Method (Fabrique)

**Objectif :** Créer dynamiquement des objets de différentes classes sans exposer les détails de leur création.

**Classes utilisées :**
- `Forme` (classe abstraite).
- `Cercle`.
- `Carre`.
- `Triangle`.
- `FabriqueForme`.

Concepts utilisés :
- Classes abstraites.
- Méthodes virtuelles pures.
- Héritage et polymorphisme.
- Allocation dynamique avec `new`.
- Gestion de la mémoire avec `delete`.
<img width="1366" height="768" alt="ex2" src="https://github.com/user-attachments/assets/7f044166-c821-497b-8b9d-bb04d23907c6" />

**Résultat :** La fabrique crée la forme demandée selon le paramètre fourni.

### Exercice 3 : Observer (Observateur)

**Objectif :** Mettre à jour automatiquement plusieurs objets lorsqu'un objet principal change d'état.

**Classes utilisées :**
- `Observateur` (interface abstraite).
- `StationMeteo`.
- `AffichageTemperature`.
- `AffichageHumidite`.
- `AffichagePression`.

Concepts utilisés :
- Interfaces abstraites.
- Polymorphisme.
- `vector` pour stocker les observateurs.
- Ajout et suppression des observateurs.
- Notification automatique.
<img width="1366" height="768" alt="ex3" src="https://github.com/user-attachments/assets/d2fa0e41-d9fb-4db9-9ad7-6bb4fceb0a0c" />

**Résultat :** Lorsque les mesures météorologiques changent, tous les affichages inscrits reçoivent les nouvelles données.

### Exercice 4 : Strategy (Stratégie)

**Objectif :** Permettre de changer dynamiquement un algorithme sans modifier la classe principale.

**Classes utilisées :**
- `StrategieTri` (interface abstraite).
- `TriCroissant`.
- `TriDecroissant`.
- `TriParLongueur`.
- `GestionnaireTri`.

Concepts utilisés :
- Polymorphisme.
- Composition.
- Méthodes virtuelles.
- Algorithmes STL avec `sort()`.
- Expressions lambda.
- Changement dynamique de stratégie.
<img width="1366" height="768" alt="ex4" src="https://github.com/user-attachments/assets/ed141cd3-43af-4715-b99d-2ea9828936ba" />

**Résultat :** Le même vecteur de chaînes peut être trié selon trois stratégies différentes.

---

##  Technologies utilisées

- **Langage :** C++
- **Standard :** C++11 ou supérieur
- **Bibliothèques :** iostream, string, vector, algorithm
- **Environnement :** MLIAEdu / IDE C++


Ce TP m'a permis de mieux comprendre l'application pratique de la programmation orientée objet en C++ et l'intérêt des patrons de conception dans le développement de logiciels modulaires, évolutifs et maintenables.

---

## 👨‍💻 Auteur

**Hamza ID EL BAZ**

Étudiant en informatique – ENS Marrakech  
Université Cadi Ayyad

**Formation :** Programmation orientée objet en C++  
**Plateforme d'apprentissage :** MLIAEdu

