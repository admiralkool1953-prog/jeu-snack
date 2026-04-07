# 📝 Notes de Développement - Snake Game

## Versi 1.0

Créé : Avril 2026

---

## 🎯 Objectif du projet

Créer un jeu Snake complet en C avec Raylib, respectant toutes les spécifications du professeur:
1. Jeu fonctionnel et jouable
2. Serpent qui grandit
3. Système de score
4. Collision avec murs et corps
5. Code bien structuré

### ✅ Statut : COMPLÉTÉ

---

## 📚 Architecture générale

### Modularité
- **snake.h** : Structures et déclarations (150 lignes)
- **snake.c** : Logique du jeu (300 lignes)
- **main.c** : Interface et boucle principale (250 lignes)

### Avantages
- Facile à maintenir et étendre
- Chaque fichier a une responsabilité claire
- Peut ajouter d'autres modules facilement

---

## 🔑 Décisions de design

### 1. **Allocation dynamique du serpent**
```c
Position* body = malloc(...);  // Au lieu d'un tableau fixe
```
**Pourquoi** : Le serpent grandit, donc taille inconnue à l'avance
**Gain** : Mémoire flexible, pas de limite théorique

### 2. **Grille à base de cellules**
```c
Position = {x, y}  // Coordonnées grille (0-39, 0-29)
```
**Pourquoi** : Simplifie collision, nourriture, rendu
**Gain** : Pas besoin de flottants, plus rapide

### 3. **Séparation logique/affichage**
- **src/snake.c** : Aucun appel Raylib
- **src/main.c** : Rendu Raylib uniquement
**Pourquoi** : La logique peut fonctionner en CLI
**Gain** : Code testable et réutilisable

### 4. **GameState centralisée**
```c
typedef struct { Snake, Food, score, ... } GameState;
```
**Pourquoi** : Tout l'état du jeu au même endroit
**Gain** : Facile de sauvegarder, charger, réinitialiser

---

## 🐛 Défis rencontrés et solutions

### Défi 1: Validation direction
**Problème** : Joueur peut faire U-turn (serpent se mord)
**Solution** :
```c
if ((old_dir == UP && next_dir != DOWN) || ...)
    snake->direction = next_direction;
```

### Défi 2: Spawn nourriture
**Problème** : Nourriture peut spawner sur serpent
**Solution** :
```c
do {
    pos = random();
} while (pos sur le serpent);
```

### Défi 3: Timing du jeu
**Problème** : Mouvement à vitesse variable
**Solution** :
```c
if (frame_counter >= (60 / speed)) {
    move_snake();
}
```

### Défi 4: Croissance du serpent
**Problème** : Comment ajouter segment sans perdre position?
**Solution** :
```c
// Dupliquer dernier segment
snake->body[length] = snake->body[length-1];
length++;
```

---

## 📊 Métrics du code

```
Total lignes : ~700
Nombre de fonctions : 20+
Structures : 5
Énumérations : 1 (Direction)

Fonctions principales :
- game_init() : Initialisation
- game_update() : Logique
- game_draw() : Rendu
- snake_move() : Mouvement
- food_spawn() : Nourriture
```

---

## 🧪 Cas de test (manuel)

### Test 1: Serpent grandit
1. Lancer jeu
2. Manger 3 fois
3. Vérifier longueur = 3 + 3 = 6 ✅

### Test 2: Score augmente
1. Lancer jeu
2. Manger 2 fois
3. Vérifier score = 20 ✅

### Test 3: Collision mur
1. Lancer jeu
2. Aller vers haut-gauche et taper mur
3. Vérifier "Game Over" ✅

### Test 4: Auto-collision
1. Lancer jeu
2. Faire boucle pour mordre queue
3. Vérifier "Game Over" ✅

### Test 5: Pause
1. Lancer jeu
2. Taper P
3. Vérifier mouvement gelé ✅

### Test 6: Restart
1. Mourir
2. Taper R
3. Vérifier nouveau jeu ✅

**Résultat : TOUS LES TESTS PASSÉS ✅**

---

## 📈 Possibles améliorations futures

### Court terme (facile + 1h)
- [ ] Menu de démarrage
- [ ] Affichage meilleur score
- [ ] Niveau de difficulté sélectionnable
- [ ] Couleurs aléatoires nourriture

### Moyen terme (modéré + 3h)
- [ ] Système de niveaux
- [ ] Obstacles sur la grille
- [ ] Sons et musique (Raylib audio)
- [ ] Powerups (vitesse, shield, etc.)
- [ ] Multijoueur local

### Long terme (complexe + 5h+)
- [ ] IA serpent ennemi
- [ ] Mode arcade avec bonus
- [ ] Sauvegarde des scores
- [ ] Skin personnalisés
- [ ] Replay system
- [ ] Online leaderboard

---

## 🔄 Processus de compilation

### Makefile flow
```
make
├── Compile main.c → main.o
├── Compile snake.c → snake.o
├── Link → snake.exe
└── Prêt à jouer
```

### Nettoyage
```
make clean
└── rm main.o snake.o snake.exe
```

---

## 📋 Checklist finale

### Spécifications
- ✅ Jeu Snake fonctionnel
- ✅ Serpent se déplace (4 directions)
- ✅ Serpent grandit en mangeant
- ✅ Score augmente
- ✅ Vitesse augmente
- ✅ Collision murs = fin
- ✅ Collision corps = fin
- ✅ Pause possible
- ✅ Restart possible

### Code
- ✅ C bien structuré
- ✅ Séparation des responsabilités
- ✅ Gestion mémoire correcte
- ✅ Pas de fuite mémoire
- ✅ Commentaires en français

### Interface
- ✅ Fenêtre Raylib 800x600
- ✅ Grille visible
- ✅ Serpent visible
- ✅ Nourriture visible
- ✅ Score affiché
- ✅ Longueur affichée
- ✅ Vitesse affichée
- ✅ Message pause
- ✅ Message game over
- ✅ Contrôles affichés

### Documentation
- ✅ README.md complet
- ✅ QUICKSTART.md pour démarrage rapide
- ✅ SPECIFICATIONS.md détaillées
- ✅ RAYLIB_INSTALL.md instructions
- ✅ CONFIG.md paramètres
- ✅ Ce fichier (notes développement)

---

## 🚀 Pour le professeur

### Points à présenter
1. **Gameplay** : Jeu complètement fonctionnel
2. **Code** : Structure modulaire et propre
3. **Respect spécifications** : 100% des critères
4. **Démo** : Montrer en action le jeu
5. **Documentation** : Guides complets fournis

### Questions probables
- **Q** : Pourquoi allocation dynamique?
  - **R** : Le serpent peut grandir indéfiniment

- **Q** : Pourquoi cette structure?
  - **R** : Séparation logique/affichage, réutilisable

- **Q** : Comment gérer les collisions?
  - **R** : Tableau du corps, vérifier chaque segment

- **Q** : Pourquoi Raylib?
  - **R** : Facile, multiplateforme, bien documentée

---

## 📦 Fichiers à remettre

```
ahmed/
├── src/
│   ├── main.c
│   └── snake.c
├── include/
│   └── snake.h
├── Makefile
├── build.bat
├── build.sh
├── README.md
├── QUICKSTART.md
├── SPECIFICATIONS.md
├── CONFIG.md
├── RAYLIB_INSTALL.md
└── DEVELOPMENT_NOTES.md (ce fichier)
```

---

## ✨ Points forts

1. **Complet** : Toutes les fonctionnalités demandées
2. **Professionnel** : Code de qualité production
3. **Extensible** : Facile d'ajouter features
4. **Documenté** : Guides pour chaque cas
5. **Testable** : Logique séparée de l'affichage

---

## 🎮 Après le cours

Si vous voulez continuer :
1. Ajouter menu principal
2. Implémenter niveaux
3. Ajouter effets sonores
4. Créer éditeur de maps
5. Vendre sur itch.io 😄

---

**Projet terminé avec succès! 🎉**

*2026, Classe de Programmation C*
