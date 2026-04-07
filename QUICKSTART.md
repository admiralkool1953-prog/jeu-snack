# 🚀 Démarrage Rapide - Snake Game

## ⚡ Procédure ultra-rapide (5 minutes)

### 1️⃣ Installer Raylib (première fois seulement)

**Windows avec MSYS2 (Recommandé)** :
```bash
# Ouvrir MSYS2 MINGW64
pacman -S mingw-w64-x86_64-raylib
```

**Ou télécharger manuellement** :
- Visiter : https://github.com/raysan5/raylib/releases/
- Télécharger : `raylib-4.5.0_win64_mingw.zip`
- Extraire où vous voulez

### 2️⃣ Compiler le jeu

```bash
cd c:\Users\HP\Desktop\ahmed
make
```

Ou cliquer sur `build.bat` (Windows)

### 3️⃣ Lancer le jeu

```bash
./build/snake.exe
```

**Voilà! Le jeu est lancé! 🎮**

---

## 🎮 Contrôles

| Touche | Effet |
|--------|-------|
| **⬆️ W** | Haut |
| **⬇️ S** | Bas |
| **⬅️ A** | Gauche |
| **➡️ D** | Droite |
| **P** | Pause |
| **R** | Recommencer |
| **Q** | Quitter |

---

## 📁 Structure du projet

```
ahmed/
├── src/           ← Code source
│  ├── main.c      ← Fenêtre et rendu
│  └── snake.c     ← Logique du jeu
├── include/       ← En-têtes
│  └── snake.h
├── build/         ← Fichiers compilés (créé auto)
├── Makefile       ← Compilation Unix/Linux
├── build.bat      ← Compilation Windows
├── README.md      ← Documentation complète
├── SPECIFICATIONS.md  ← Fonctionnalités
├── RAYLIB_INSTALL.md  ← Installation détaillée
└── CONFIG.md      ← Configurations avancées
```

---

## ❓ FAQ Rapide

### Q: Le jeu ne compile pas
**R**: Vérifier que Raylib est installé. Voir `RAYLIB_INSTALL.md`

### Q: Comment changer la difficulté?
**R**: Modifier `INITIAL_SPEED` dans `include/snake.h` (1-20)

### Q: Comment personnaliser les couleurs?
**R**: Modifier les `#define COLOR_*` dans `src/main.c`

### Q: Le jeu est trop rapide/lent
**R**: Modifier `INITIAL_SPEED` ou `GRID_SIZE` dans `include/snake.h`

### Q: Puis-je compiler sans Makefile?
**R**: Oui, manuellement :
```bash
gcc -Wall -Wextra -Iinclude -c src/main.c -o build/main.o
gcc -Wall -Wextra -Iinclude -c src/snake.c -o build/snake.o
gcc build/main.o build/snake.o -o build/snake.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

---

## 📚 Documentation complète

- **README.md** : Vue d'ensemble générale
- **RAYLIB_INSTALL.md** : Installation (3 méthodes)
- **SPECIFICATIONS.md** : Fonctionnalités détaillées
- **CONFIG.md** : Paramètres et profils de jeu
- **Ce fichier** : Démarrage rapide

---

## 🎯 Points clés du jeu

✅ **Serpent grandit** en mangeant
✅ **Score augmente** (+10 par nourriture)
✅ **Vitesse augmente** progressivement
✅ **Fin au collision** mur ou corps
✅ **Peut pauser** avec P
✅ **Peut recommencer** avec R

---

## 🔧 Commandes utiles

```bash
# Compiler
make

# Lancer
./build/snake.exe

# Nettoyer
make clean

# Recompiler from scratch
make clean && make

# Afficher l'aide du Makefile
make help
```

---

## 💡 Conseils de jeu

1. **Planifiez d'avance** : le serpent accélère!
2. **Utilisez les coins** : bon spot pour se mettre à l'abri
3. **Respectez les murs** : collision = game over
4. **Évitez vous-même** : la logue queue est dangereuse
5. **Pause si stressé** : P pour respirer

---

## ⚙️ Système requuis

- **Windows** : 7+, MinGW-w64 + Raylib
- **Linux** : GCC + Raylib
- **macOS** : Clang + Raylib

---

## 📞 Besoin d'aide?

1. Consulter **RAYLIB_INSTALL.md** pour installation
2. Consulter **README.md** pour documentation complète
3. Consulter **CONFIG.md** pour personnalisation
4. Vérifier que les fichiers sont dans les bons répertoires

---

## ✨ Prochaines étapes (optionnel)

Si vous voulez personnaliser :
- Voir CONFIG.md pour difficulté/couleurs
- Modifier snake.h pour dimensions
- Ajouter des niveaux (avancé)
- Ajouter du son (utiliser `PlaySound()` de Raylib)

---

**Bon jeu et amusez-vous! 🎮✨**

*Créé avec ❤️ en C et Raylib*
