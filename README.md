# Projet Géométrie — POO C++

Application console de démonstration d'une architecture orientée objet pour manipuler des formes géométriques.

## Fonctionnalités

- `Point` : coordonnées 2D et distance euclidienne.
- `FormeGeometrique` : classe abstraite définissant aire, périmètre, nom et dessin.
- `Cercle` : défini par un centre et un rayon.
- `Polygone` : classe de base des figures polygonales, avec calcul du périmètre et aire par la formule du lacet.
- `Triangle`, `Rectangle`, `Carre` : formes polygonales spécialisées.
- Carré et rectangle : prise en charge d'une orientation (angle en radians).
- Polymorphisme avec `std::unique_ptr<FormeGeometrique>`.

## Organisation

```text
Projet_Geometrie/
├── include/                 # Fichiers d'en-tête (.h)
├── src/                     # Implémentations (.cpp)
├── main.cpp                 # Démonstration
├── CMakeLists.txt           # Configuration de compilation
└── README.md
```

## Compilation avec CMake

Prérequis : un compilateur C++17 et CMake 3.16 ou plus récent.

Depuis le dossier `Projet_Geometrie` :

```bash
cmake -S . -B build
cmake --build build
```

Lancement :

- Linux/macOS : `./build/Projet_Geometrie`
- Windows (générateur Visual Studio) : `build\\Debug\\Projet_Geometrie.exe` ou `build\\Release\\Projet_Geometrie.exe`

## Compilation directe avec g++

Depuis le dossier du projet :

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude main.cpp src/*.cpp -o geometrie
```

Puis lancer `./geometrie` (ou `geometrie.exe` sous Windows).

## Repères de conception

- `FormeGeometrique` est abstraite : elle impose une interface commune.
- `Cercle` et `Polygone` héritent séparément de `FormeGeometrique`.
- `Triangle`, `Rectangle` et `Carre` héritent de `Polygone`.
- `Carre` n'hérite pas de `Rectangle` : cela évite de casser l'invariant selon lequel les quatre côtés du carré sont égaux.
- `Polygone` calcule l'aire avec la formule du lacet et le périmètre avec les distances entre sommets successifs, en reliant le dernier au premier.
- `dessiner()` est ici une représentation textuelle. Une interface graphique Qt ou SFML pourra être ajoutée ensuite sans mélanger le moteur géométrique et l'affichage.

## Convention d'angle

Les angles du carré et du rectangle sont exprimés en radians :
- `0` : côté horizontal vers la droite.
- `3.14159 / 4` : rotation de 45 degrés.
