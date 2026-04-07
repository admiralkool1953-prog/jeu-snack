# 📑 Index du Projet - Snake Game Raylib

## 🎮 Fichiers source (à compiler)

### [src/main.c](src/main.c)
**Rôle** : Fenêtre, rendu et boucle principale
**Contenu** :
- Initialisation fenêtre Raylib
- Boucle de jeu (60 FPS)
- Dessin des éléments (grille, serpent, nourriture, UI)
- Gestion entrées utilisateur
- Menu Game Over
- ~250 lignes

### [src/snake.c](src/snake.c)
**Rôle** : Logique du jeu
**Contenu** :
- Initialisation serpent
- Mouvement et croissance
- Détection collisions
- Spawn nourriture
- Gestion état jeu
- ~300 lignes

### [include/snake.h](include/snake.h)
**Rôle** : Déclarations et structures
**Contenu** :
- Structures : Position, Snake, Food, GameState
- Énumération : Direction (UP, DOWN, LEFT, RIGHT)
- Prototypes de fonctions
- Constantes configurables (SCREEN_WIDTH, GRID_SIZE, etc.)
- ~150 lignes

---

## 🔨 Fichiers de compilation

### [Makefile](Makefile)
**Système** : Unix/Linux/MSYS2
**Commandes** :
- `make` - Compiler
- `make clean` - Nettoyer
- `make run` - Compiler et lancer
- Détecte automatiquement modifications

### [build.bat](build.bat)
**Système** : Windows (Command Prompt)
**Fonctionnalité** :
- Compile avec gcc
- Vérifie les erreurs
- Propose de lancer le jeu
- Interface interactive en français

### [build.sh](build.sh)
**Système** : Linux/macOS (Bash)
**Fonctionnalité** :
- Compile avec gcc
- Gère plusieurs plateformes
- Interactive launch
- Messages en français

---

## 📚 Documentation

### [README.md](README.md) ⭐ **COMMENCER ICI**
**Audience** : Tout le monde
**Contenu** :
- Vue d'ensemble du jeu
- Fonctionnalités principales
- Instructions combat et installation
- Structure du projet
- FAQ
- ~400 lignes

### [QUICKSTART.md](QUICKSTART.md) ⭐ **POUR DÉMARRER VITE**
**Audience** : Impatient
**Contenu** :
- Installation en 3 étapes
- Compilation rapide
- Contrôles
- FAQ express
- ~150 lignes

### [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md) ⭐ **INSTALLATION RAYLIB**
**Audience** : Besoin d'installer Raylib
**Contenu** :
- 3 méthodes d'installation
- MSYS2 (facile)
- MinGW manuel
- vcpkg
- Dépannage
- ~200 lignes

### [SPECIFICATIONS.md](SPECIFICATIONS.md)
**Audience** : Professeur, reverifieurs
**Contenu** :
- Checklist spécifications
- Architecture détaillée
- Structures de données
- Fonctionnalités implémentées
- Validations critères
- ~350 lignes

### [CONFIG.md](CONFIG.md)
**Audience** : Développeur qui veut personnaliser
**Contenu** :
- Paramètres configurables
- Profils (Easy, Normal, Hard, Extreme)
- Modifications graphiques
- Couleurs et typos
- Trucs de performance
- ~300 lignes

### [DEVELOPMENT_NOTES.md](DEVELOPMENT_NOTES.md)
**Audience** : Développeur/Professeur intéressé
**Contenu** :
- Décisions de design
- Défis et solutions
- Métrics du code
- Cas de test documentés
- Améliorations futures
- ~300 lignes

### [index.md](INDEX.md) (CE FICHIER)
**Audience** : Naviguer le projet
**Contenu** :
- Liste complète des fichiers
- Description de chacun
- Qui lire en premier
- Chemin d'apprentissage

---

## 📁 Répertoires

### [src/](src/)
**Contient** : Fichiers source C (.c)
- main.c
- snake.c

### [include/](include/)
**Contient** : Fichiers header (.h)
- snake.h

### [build/](build/)
**Contient** : Fichiers compilés (créés automatiquement)
- *.o (fichiers objet)
- snake.exe (exécutable)
- (Vide après `make clean`)

---

## 🎯 Chemin de lecture recommandé

### Pour jouer rapidement
1. Lire [QUICKSTART.md](QUICKSTART.md) (5 min)
2. Installer Raylib via [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md) (10 min)
3. Compiler avec `make` (2 min)
4. Jouer `./build/snake.exe` (infini! 🎮)

### Pour comprendre le code
1. Lire [README.md](README.md) (15 min)
2. Lire [include/snake.h](include/snake.h) (10 min)
3. Lire [src/snake.c](src/snake.c) (20 min)
4. Lire [src/main.c](src/main.c) (15 min)
5. Lire [DEVELOPMENT_NOTES.md](DEVELOPMENT_NOTES.md) (10 min)

### Pour modifier et personnaliser
1. Lire [CONFIG.md](CONFIG.md) (15 min)
2. Modifier [include/snake.h](include/snake.h) ou [src/main.c](src/main.c)
3. `make clean && make`
4. Tester

### Pour présenter au professeur
1. Demo le jeu (montrer gameplay)
2. Lire [SPECIFICATIONS.md](SPECIFICATIONS.md) (montrer complétude)
3. Expliquer architecture ([DEVELOPMENT_NOTES.md](DEVELOPMENT_NOTES.md))
4. Montrer code source (main.c, snake.c, snake.h)

---

## 📊 Statistiques du projet

```
Fichiers C/H :
  - main.c : 250 lignes
  - snake.c : 300 lignes
  - snake.h : 150 lignes
  TOTAL CODE : ~700 lignes

Fichiers documentation :
  - README.md : 400 lignes
  - QUICKSTART.md : 150 lignes
  - RAYLIB_INSTALL.md : 200 lignes
  - SPECIFICATIONS.md : 350 lignes
  - CONFIG.md : 300 lignes
  - DEVELOPMENT_NOTES.md : 300 lignes
  TOTAL DOCS : ~1700 lignes

GRAND TOTAL : ~2400 lignes

Nombre de fichiers : 13
Nombre de fonctions C : 20+
Nombre de structures : 5
```

---

## 🔍 Référence rapide

### Pour démarrer
- Jouer : `./build/snake.exe`
- Compiler : `make`
- Nettoyer : `make clean`

### Pour installer Raylib
- Windows : Lire [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md)
- Linux : Lire [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md)
- macOS : Lire [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md)

### Pour modifier
1. Éditer fichier
2. Lire [CONFIG.md](CONFIG.md) pour les paramètres
3. `make`

### Pour apprendre
1. Commencer par [README.md](README.md)
2. Puis [DEVELOPMENT_NOTES.md](DEVELOPMENT_NOTES.md)
3. Puis lire le code

### Pour déboguer
1. Vérifier la compilation : `make clean && make`
2. Vérifier Raylib : utiliser test.c de [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md)
3. Lire messages d'erreur attentivement
4. Consulter [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md) FAQ

---

## ✅ Checklist d'utilisation

- [ ] Raylib installé?
- [ ] Projet téléchargé/cloné?
- [ ] Lu [QUICKSTART.md](QUICKSTART.md)?
- [ ] Compilé avec `make`?
- [ ] Jeu lancé et joué?
- [ ] Score augmentait?
- [ ] Collision détectée?
- [ ] Avant la présentation, lu [SPECIFICATIONS.md](SPECIFICATIONS.md)?

---

## 🎓 Pour le professeur

Fichiers importants à consulter :

1. **Code source** : Vérifier structure et qualité
   - [src/main.c](src/main.c) - Interface
   - [src/snake.c](src/snake.c) - Logique
   - [include/snake.h](include/snake.h) - Structures

2. **Spécifications** :
   - [SPECIFICATIONS.md](SPECIFICATIONS.md) - Respecté 100%?

3. **Documentation** :
   - [README.md](README.md) - Complète?
   - [DEVELOPMENT_NOTES.md](DEVELOPMENT_NOTES.md) - Process clear?

4. **Démo** :
   - `./build/snake.exe` - Fonctionnel?

---

## 🚀 Prochaines étapes

### Pour continuer seul
1. Lire [CONFIG.md](CONFIG.md)
2. Ajouter des niveaux
3. Ajouter du son
4. Vendre sur itch.io 😄

### Pour présenter
1. Demo le jeu
2. Montrer respecte spécifications (voir [SPECIFICATIONS.md](SPECIFICATIONS.md))
3. Montrer code structure
4. Répondre questions

---

## 📞 Support

**Raylib ne compile pas?** → [RAYLIB_INSTALL.md](RAYLIB_INSTALL.md)
**Comment jouer?** → [QUICKSTART.md](QUICKSTART.md) + [README.md](README.md)
**Comment personnaliser?** → [CONFIG.md](CONFIG.md)
**Pourquoi ce design?** → [DEVELOPMENT_NOTES.md](DEVELOPMENT_NOTES.md)
**Est-ce 100% respecte le prof?** → [SPECIFICATIONS.md](SPECIFICATIONS.md)

---

**Happy coding! 🎮✨**

*Dernière mise à jour : Avril 2026*
