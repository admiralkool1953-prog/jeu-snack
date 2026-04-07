# Configuration - Raylib Snake Game

## Paramètres de jeu personnalisables

Tous ces paramètres se trouvent dans `include/snake.h` :

### Dimensions de l'écran
```c
#define SCREEN_WIDTH 800    // Largeur en pixels
#define SCREEN_HEIGHT 600   // Hauteur en pixels
```

**Recommandé** :
- Minimum : 400x300 (trop petit pour un bon gameplay)
- Standard : 800x600 (configuration actuelle)
- Grand : 1024x768 ou 1280x720

### Taille de la grille
```c
#define GRID_SIZE 20  // Taille de chaque cellule en pixels
```

**Recommandé** :
- GRID_SIZE = 10  : Grille fine (80x60), plus de précision
- GRID_SIZE = 20  : Équilibre (40x30) - **Configuration actuelle**
- GRID_SIZE = 40  : Grille large (20x15), plus facile

### Vitesse de déplacement
```c
#define INITIAL_SPEED 8  // Vitesse initiale (1-20)
```

**Recommandé** :
- Facile : 5-6 (mouvements lents et prévisibles)
- Normal : 8-10 (équilibré) - **Configuration actuelle**
- Difficile : 12-15 (mouvements rapides)
- Extrême : 18-20 (très rapide, presque injouable)

---

## Configuration avancée

### Vitesse maximale
Dans `src/snake.c`, fonction `game_update()` :
```c
if (state->speed < 20) {  // Limiter à 20 FPS max
    state->speed += 0.5f;
}
```

Pour augmenter la vitesse max, modifier la condition :
```c
if (state->speed < 30) {  // Jusqu'à 30 FPS
    state->speed += 1.0f; // Augmentation plus rapide
}
```

### Points par nourriture
Dans `src/snake.c`, fonction `game_update()` :
```c
state->score += 10;  // Changer 10 en autre valeur
```

Exemples :
- `state->score += 5;` : Plus de nourriture pour plus de points
- `state->score += 100;` : Scoring exponentiel
- `state->score += state->snake.length;` : Points basés sur longueur

### Accélération
Dans `src/snake.c`, fonction `game_update()` :
```c
state->speed += 0.5f;  // Incrément par nourriture
```

Changer pour :
- `state->speed += 0.1f;` : Accélération très progressive
- `state->speed += 1.0f;` : Accélération rapide
- `state->speed += 0.05f;` : Ultra-progressif

### Capacité initiale du serpent
Dans `src/snake.c`, fonction `snake_create()` :
```c
snake.capacity = 100;  // Tableau de 100 segments
```

Sur le mur ou en tête-à-tête :
- `snake.capacity = 50;` : Moins de mémoire allouée (serpent court)
- `snake.capacity = 200;` : Plus de mémoire (pour très gros serpent)
- `snake.capacity = 1000;` : Pour les jeux très longs

---

## Modifications graphiques

### Couleurs du jeu
Dans `src/main.c` :

```c
// Modifier les couleurs existantes
#define COLOR_SNAKE (Color){0, 200, 0, 255}       // [R, G, B, A]
#define COLOR_FOOD (Color){255, 0, 0, 255}
#define COLOR_GRID (Color){50, 50, 50, 255}
#define COLOR_BG (Color){10, 10, 10, 255}
#define COLOR_TEXT (Color){255, 255, 255, 255}

// Exemple : Changer le serpent en bleu
#define COLOR_SNAKE (Color){0, 100, 255, 255}

// Exemple : Thème dark mode
#define COLOR_BG (Color){20, 20, 20, 255}
#define COLOR_GRID (Color){40, 40, 40, 255}
```

### Tailles de police
Dans `src/main.c`, fonction `draw_game()` :

```c
DrawText(score_text, 10, 10, 20, COLOR_TEXT);  // Taille 20
DrawText(length_text, 10, 35, 20, COLOR_TEXT);

// Modifier :
DrawText(score_text, 10, 10, 30, COLOR_TEXT);  // Plus grand (30)
DrawText(score_text, 10, 10, 15, COLOR_TEXT);  // Plus petit (15)
```

### Épaisseur du serpent
Le serpent est dessiné comme des carrés. Pour modifier l'apparence :

```c
Rectangle rect = {
    state->snake.body[i].x * GRID_SIZE,
    state->snake.body[i].y * GRID_SIZE,
    GRID_SIZE - 1,  // <-- Modifier ce 1
    GRID_SIZE - 1
};

// Exemples :
GRID_SIZE - 0,  // Carrés pleins (pas d'espace)
GRID_SIZE - 2,  // Espaces plus grands
GRID_SIZE / 2,  // Petits carrés au centre
```

---

## Profils prédéfinis

### Profil EASY
```c
// Dans snake.h
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRID_SIZE 30          // Grille plus grande
#define INITIAL_SPEED 4       // Très lent

// Dans snake.c - game_update()
state->score += 5;            // Moins de points
state->speed += 0.1f;         // Accélération très lente
```

### Profil NORMAL (Configuration actuelle)
```c
// Dans snake.h
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRID_SIZE 20
#define INITIAL_SPEED 8

// Dans snake.c - game_update()
state->score += 10;
state->speed += 0.5f;
```

### Profil HARD
```c
// Dans snake.h
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRID_SIZE 15          // Grille fine
#define INITIAL_SPEED 12      // Plus rapide

// Dans snake.c - game_update()
state->score += 20;           // Plus de points
state->speed += 1.0f;         // Accélération rapide
```

### Profil EXTREME
```c
// Dans snake.h
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400
#define GRID_SIZE 10          // Très fin
#define INITIAL_SPEED 20      // Très rapide

// Dans snake.c - game_update()
state->score += 50;
state->speed += 2.0f;         // Accélération extrême
```

---

## Scripts de nettoyage

### Nettoyer les fichiers compilés
```bash
make clean
```

Ou manuellement :
```batch
del build\*.o build\*.exe
```

### Recompiler from scratch
```bash
make clean
make
```

---

## Trucs et astuces de performance

### Réduire l'utilisation mémoire
- Diminuer `SCREEN_WIDTH` et `SCREEN_HEIGHT`
- Augmenter `GRID_SIZE`
- Diminuer `snake.capacity`

### Améliorer les performances
- Vérifier FPS avec un compteur
- Réduire les appels DrawText (très lent)
- Utiliser `SetTargetFPS()` pour fixer 60 FPS (déjà fait dans main.c)

### Déboguer
Ajouter dans `src/main.c` :
```c
// Afficher les FPS (dans draw_game)
char fps_text[20];
snprintf(fps_text, sizeof(fps_text), "FPS: %d", GetFPS());
DrawText(fps_text, SCREEN_WIDTH - 100, 10, 20, COLOR_TEXT);
```

---

## Récompilation après modifications

Après chaque modification :
```bash
make clean
make
./build/snake.exe
```

Ou simplement :
```bash
make
```
(sans nettoyer, recompile seulement les fichiers modifiés)

---

## Support et dépannage

Si le jeu semble bugué après modifications :
1. Recompiler proprement : `make clean && make`
2. Vérifier la syntaxe C
3. S'assurer que les valeurs sont valides (vitesse > 0, etc.)
4. Tester avec configuration par défaut

---

**Happy tweaking! 🎮**
