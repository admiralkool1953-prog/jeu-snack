# 🐍 Snake Game - Raylib

Un jeu Snake interactif développé en C avec la bibliothèque Raylib.

## 📋 Vue d'ensemble

Le jeu Snake consiste à contrôler un serpent qui se déplace dans une fenêtre. L'objectif est de :
- **Diriger le serpent** pour manger de la nourriture (carrés rouges)
- **Grandir** à chaque aliment consommé
- **Augmenter le score** en mangeant
- **Éviter les collisions** avec les murs et le corps du serpent

## 🎮 Caractéristiques

✅ **Gameplay complet** :
- Serpent qui grandit en mangeant
- Système de score
- Vitesse progressive qui augmente
- Collision détection (murs et auto-collision)

✅ **Interface utilisateur** :
- Grille de jeu visible
- Affichage du score en temps réel
- Affichage de la longueur du serpent
- Affichage de la vitesse
- Message de pause et game over

✅ **Code bien structuré** :
- Séparation tête/corps (`include/` et `src/`)
- Structures de données claires
- Gestion dynamique de la mémoire
- Commentaires en français

## 🎮 Contrôles

| Touche | Action |
|--------|--------|
| **↑ / W** | Déplacer vers le haut |
| **↓ / S** | Déplacer vers le bas |
| **← / A** | Déplacer vers la gauche |
| **→ / D** | Déplacer vers la droite |
| **P** | Pause / Reprendre |
| **R** | Recommencer (après Game Over) |
| **Q** | Quitter (après Game Over) |

## 📦 Installation de Raylib

### Option 1 : Installer via MSYS2/MinGW (Recommandé)

1. **Installer MSYS2** : https://www.msys2.org/
2. Dans MSYS2, exécuter :
```bash
pacman -S mingw-w64-x86_64-raylib mingw-w64-x86_64-gcc
```

3. Cloner ou télécharger Raylib :
```bash
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make -B PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=STATIC
```

### Option 2 : Télécharger les fichiers pré-compilés

1. Visiter : https://github.com/raysan5/raylib/releases/
2. Télécharger `raylib-4.5.0_win64_mingw.zip`
3. Extraire dans un dossier connu

### Option 3 : Utiliser vcpkg

```bash
vcpkg install raylib:x64-windows
```

## 🔨 Compilation

### Avec MinGW (GCC)

```bash
# Compiler
gcc -Wall -Wextra -Iinclude -c src/main.c -o build/main.o
gcc -Wall -Wextra -Iinclude -c src/snake.c -o build/snake.o
gcc build/main.o build/snake.o -o build/snake.exe -lraylib -lopengl32 -lgdi32 -lwinmm

# Ou utiliser le Makefile :
make
```

### Avec Visual Studio

1. Créer un projet C vide
2. Ajouter les fichiers sources
3. Configurer le répertoire d'include de Raylib
4. Compiler

## 🚀 Lancer le jeu

```bash
./build/snake.exe
```

Ou avec make :
```bash
make run
```

## 📁 Structure du projet

```
ahmed/
├── src/
│   ├── main.c          # Boucle principale et rendu
│   └── snake.c         # Logique du jeu
├── include/
│   └── snake.h         # Déclarations et structures
├── build/              # Fichiers compilés
├── Makefile            # Script de compilation
└── README.md           # Ce fichier
```

## 🏗️ Architecture du code

### Structures principales

```c
// Le serpent
typedef struct {
    Position* body;      // Segments du corps
    int length;          // Longueur actuelle
    Direction direction; // Direction de mouvement
} Snake;

// La nourriture
typedef struct {
    Position pos;
    bool active;
} Food;

// État du jeu
typedef struct {
    Snake snake;
    Food food;
    int score;
    bool game_over;
    bool paused;
} GameState;
```

## 🔧 Fonctionnalités implémentées

- ✅ Initialisation et gestion du jeu
- ✅ Système de serpent avec croissance dynamique
- ✅ Spawn aléatoire de nourriture
- ✅ Détection de collisions (murs et auto-collision)
- ✅ Système de score
- ✅ Augmentation progressive de la vitesse
- ✅ Pause/Reprise du jeu
- ✅ Gestion des entrées utilisateur
- ✅ Interfacegraphique avec Raylib

## 📝 Spécifications respectées

✅ **Langage** : C (ISO C99)
✅ **Bibliothèque graphique** : Raylib
✅ **Gameplay** : Le serpent grandit en mangeant et le score augmente
✅ **Fin de jeu** : Collision avec les murs ou le corps du serpent
✅ **Structure** : Code bien organisé et commenté
✅ **Ergonomie** : Interface claire avec contrôles intuitifs

## 🐛 Dépannage

### Le programme ne compile pas

1. Vérifier que Raylib est installé et dans le PATH
2. Vérifier le chemin d'include de Raylib
3. S'assurer que les dépendances (OpenGL, GDI32) sont disponibles

### Le jeu se lance mais aucune fenêtre n'apparaît

- Vérifier que Raylib est correctement installé
- Vérifier les permissions pour créer une fenêtre

### Le jeu est trop lent ou trop rapide

- Modifier `INITIAL_SPEED` dans `include/snake.h` (valeur entre 1 et 20)

## 📊 Variables configurables

Dans `include/snake.h` :

```c
#define SCREEN_WIDTH 800      // Largeur de la fenêtre
#define SCREEN_HEIGHT 600     // Hauteur de la fenêtre
#define GRID_SIZE 20          // Taille des cellules de la grille
#define INITIAL_SPEED 8       // Vitesse initiale (1-20)
```

## 🎯 Améliorations futures possibles

- Système de niveaux
- Menu principal
- Musique et effets sonores
- Leaderboard de scores
- Différents modes de jeu
- Obstacles sur la grille
- Powerups spéciaux

## 📄 Licence

Code libre d'utilisation à des fins éducatives.

## 👨‍💼 Développeur

Créé pour un mini-projet de programmation C avec Raylib.

---

**Bon jeu! 🎮**
