# 🛠️ Setup Complet - Installation & Compilation

Ce fichier guide vous à travers TOUT : du zéro à avoir le jeu qui tourne.

## ⏱️ Temps estimé : 20-30 minutes (première fois)

---

## 📋 Prérequis

### Pour Windows
- ✅ Windows 7+
- ✅ Accès à Internet (pour télécharger)
- ✅ Accès administrateur (Pour installer)

### Pour Linux
- ✅ Ubuntu/Debian/Fedora
- ✅ Package manager (apt, dnf)

### Pour macOS
- ✅ Xcode Command Line Tools

---

## 🪟 Installation Windows (PAR ÉTAPES)

### Étape 1 : Installer MSYS2 (Facile - 5 min)

1. **Télécharger MSYS2** :
   - Aller sur https://www.msys2.org/
   - Cliquer "Download"
   - Télécharger l'installeur Windows 64-bit

2. **Installer** :
   - Double-cliquer l'installeur
   - Cliquer "Next" jusqu'au bout
   - Laisser le chemin par défaut : `C:\msys64`
   - Cliquer "Finish"

3. **Lancer MSYS2** :
   - Menu Démarrer → MSYS2 64bit
   - Chercher et cliquer "MSYS2 MinGW x64"
   - Une fenêtre noire va s'ouvrir

### Étape 2 : Installer Raylib avec MSYS2 (Facile - 10 min)

Dans la fenêtre MSYS2 noire, taper :

```bash
pacman -S mingw-w64-x86_64-raylib
```

Appuyer sur Entrée. Quand demandé, taper `Y` et appuyer Entrée.

Attendre la fin (peut prendre 5 minutes si Internet lent).

### Étape 3 : Vérifier l'installation

Dans la même fenêtre MSYS2, taper :

```bash
pkg-config --cflags --libs raylib
```

Si vous voyez `-lraylib` et d'autres options, **C'est BON!** ✅

### Étape 4 : Ouvrir le dossier du projet

Dans MSYS2 :

```bash
cd /c/Users/HP/Desktop/ahmed
```

Vérifier que vous êtes au bon endroit :

```bash
ls
```

Vous devez voir : `src/  include/  Makefile  README.md  ...`

### Étape 5 : Compiler

Toujours dans MSYS2 :

```bash
make
```

Attendre. Vous devez voir :

```
[1/2] Compilation de src/main.c...
OK!
[2/2] Compilation de src/snake.c...
OK!
Linking...
Build successful!
```

### Étape 6 : Lancer le jeu!

Toujours dans MSYS2 :

```bash
./build/snake.exe
```

**BRAVO! Le jeu doit se lancer! 🎮**

---

## 🐧 Installation Linux (Ubuntu/Debian)

### Étape 1-2 : Installer GCC et Raylib

```bash
sudo apt update
sudo apt install build-essential raylib-dev
```

Taper votre mot de passe quand demandé.

### Étape 3-6 : Compiler et lancer

```bash
cd ~/Desktop/ahmed  # Ou où c'est situé
make
./build/snake
```

**Le jeu doit se lancer! 🎮**

---

## 🍎 Installation macOS

### Étape 1-2 : Installer Homebrew et Raylib

D'abord, installer Homebrew (si pas déjà installé) :

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Ensuite, installer Raylib :

```bash
brew install raylib
```

### Étape 3-6 : Compiler et lancer

```bash
cd ~/Desktop/ahmed  # Où le projet est
make
./build/snake
```

**Le jeu doit se lancer! 🎮**

---

## ⚡ Alternative rapide (Si MSYS2 c'est trop)

### Option : Télécharger Raylib manuel

1. Aller sur https://github.com/raysan5/raylib/releases
2. Chercher "raylib-4.5.0"
3. Télécharger "raylib-4.5.0_win64_mingw.zip"
4. Extraire dans `C:\raylib`
5. Modifier le Makefile :

```makefile
# Ajouter avant CFLAGS :
RAYLIB_PATH = C:\raylib

CFLAGS = -Wall -Wextra -I$(RAYLIB_PATH)\include -Iinclude
LDFLAGS = -L$(RAYLIB_PATH)\lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

6. `make clean && make`

---

## 🔧 Troubleshooting

### ❌ "gcc: command not found"

**Solution** : GCC n'est pas installé
- Windows : Réinstaller MSYS2 correctement
- Linux : `sudo apt install build-essential`
- macOS : Installer Xcode Command Line Tools

### ❌ "raylib.h: No such file or directory"

**Solution** : Raylib n'est pas trouvé
- Windows : Vérifier MSYS2 installation
- Tous : `pkg-config --cflags raylib` (doit afficher quelque chose)

### ❌ "error: skipping incompatible... raylib"

**Solution** : Architecture ne correspond pas
- Utiliser version 64-bit (x86_64)
- Assurez que GCC et Raylib sont même architecture

### ❌ Compilation réussit mais "file not found"

**Solution** : Raylib library n'est pas trouvée à l'exécution
- Windows : Ajouter `C:\msys64\mingw64\lib` au PATH
- Ou copier les DLL raylib dans le dossier build

### ❌ La fenêtre ne s'ouvre pas

**Solution** : Essayer dans le terminal directement
- Windows : `.\build\snake.exe`
- Vérifier que Raylib compile (test simple)

---

## ✅ Verification complète

### Test 1 : Compiler fonctionne

```bash
make clean
make
```

Vous devez voir : `build/snake.exe` créé

### Test 2 : Jeu lance

```bash
./build/snake.exe
```

Fenêtre doit s'ouvrir avec grille noire

### Test 3 : Jeu fonctionne

- Appuyer sur flèches : serpent bouge
- Attendre : serpent mange nourriture (rouge)
- Vérifier : score augmente
- Continuer : serpent grandit
- Taper P : jeu pause
- Taper P again : reprend
- Aller au mur : "Game Over"
- Taper R : restart

**Si TOUT ça fonctionne, vous êtes prêt! ✅**

---

## 📝 Pour le professeur

### Les points à vérifier

1. **Code source** (en respecte spécifications):
   - `src/main.c` : Fenêtre Raylib existe
   - `src/snake.c` : Logique serpent existe
   - `include/snake.h` : Structures définies

2. **Compile sans erreurs** :
   - `make clean && make` → succès
   - `./build/snake.exe` → fenêtre s'ouvre

3. **Gameplay complet** :
   - Serpent se déplace ✅
   - Serpent grandit ✅
   - Score augmente ✅
   - Collision détectée ✅

4. **Elle est structurée** :
   - Séparation include/src ✅
   - Fonctions bien nommées ✅
   - Commentaires présents ✅

---

## 🎓 FAQ Installation

**Q** : Est-ce que ça fonctionne sur mon ordi?
**R** : Oui si : Windows/Linux/macOS + internet + 30 min temps libre

**Q** : Je dois payer pour Raylib?
**R** : Non, c'est gratuit et open-source

**Q** : Raylib c'est quoi?
**R** : Une bibliothèque C simple pour faire des jeux/graphics

**Q** : Ça va être difficile?
**R** : Non, juste suivre les étapes. Si ça fonctionne pas, lire la 3e partie

**Q** : Ça fonctionne sur Windows 11?
**R** : Oui, tout à fait

**Q** : Je peux utiliser Visual Studio?
**R** : Oui, mais plus compliqué. Suivre les instructions VS

---

## 🎯 Checklist finale

Avant de présenter/soumettre :

- [ ] Raylib installé : `pkg-config --cflags --libs raylib`
- [ ] Projet téléchargé : `ls` montre les fichiers
- [ ] Compile : `make` réussit
- [ ] Jeu lance : `./build/snake.exe` ouvre fenêtre
- [ ] Gameplay fonctionne : serpent bouge, mange, grandit, meurt
- [ ] Contrôles marchent : flèches, P, R, Q
- [ ] Code lisible : pas de warning à la compilation
- [ ] Documentation : README.md + autres fichiers présents

---

## 🚀 Vous êtes prêt!

Vous pouvez maintenant :
1. **Jouer** : Lancer le jeu
2. **Modifier** : Changer couleurs/difficulté dans CONFIG.md
3. **Apprendre** : Lire le code, comprendre la logique
4. **Présenter** : Au professeur

---

## 📚 Ressources utiles

- Site officiel Raylib : https://www.raylib.com/
- Exemples Raylib : https://github.com/raysan5/raylib/tree/master/examples
- Documentation : https://www.raylib.com/cheatsheet/cheatsheet.html
- Notre projet : Tous les fichiers dans ce dossier

---

**Bon jeu! 🎮✨**

*Guide Setup v1.0 - Avril 2026*
