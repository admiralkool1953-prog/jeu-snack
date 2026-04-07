# Guide d'installation de Raylib sur Windows

## OPTION 1 : Installation via MSYS2 (Recommandée - Plus facile)

### Étape 1 : Installer MSYS2
1. Télécharger MSYS2 : https://www.msys2.org/
2. Installer à l'emplacement par défaut (C:\msys64)
3. Lancer "MSYS2 MINGW64" depuis le menu démarrer

### Étape 2 : Installer Raylib avec pacman
Dans la fenêtre MSYS2 MINGW64, exécuter :
```bash
pacman -S mingw-w64-x86_64-raylib
```

Répondre `Y` quand demandé pour confirmer l'installation.

### Étape 3 : Vérifier l'installation
```bash
pkg-config --cflags --libs raylib
```

Si vous voyez `-lraylib` et d'autres flags, c'est bon!

### Étape 4 : Compiler le projet
```bash
cd /c/Users/HP/Desktop/ahmed
make
```

---

## OPTION 2 : Installation manuelle (Plus de contrôle)

### Étape 1 : Télécharger MinGW-w64
1. Visiter : https://www.mingw-w64.org/
2. Télécharger la version x86_64-posix-seh
3. Extraire dans C:\mingw64
4. Ajouter C:\mingw64\bin au PATH Windows

### Étape 2 : Télécharger Raylib
1. Visiter : https://github.com/raysan5/raylib/releases
2. Télécharger `raylib-4.5.0_win64_mingw.zip`
3. Extraire le contenu dans C:\raylib

### Étape 3 : Configurer le Makefile
Modifier le Makefile pour pointer vers votre installation :
```makefile
RAYLIB_PATH = C:\raylib

CFLAGS = -Wall -Wextra -I$(RAYLIB_PATH)\include -Iinclude
LDFLAGS = -L$(RAYLIB_PATH)\lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Étape 4 : Compiler
```cmd
cd C:\Users\HP\Desktop\ahmed
make
```

---

## OPTION 3 : Utiliser vcpkg (Pour les projets Visual Studio)

### Étape 1 : Cloner vcpkg
```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

### Étape 2 : Installer Raylib
```bash
.\vcpkg install raylib:x64-windows
```

### Étape 3 : Utiliser dans Visual Studio
- Créer un projet C vide
- Ajouter les fichiers sources
- Configurer les chemins d'include et lib de Raylib

---

## Vérification rapide après installation

Créer un fichier `test.c` :
```c
#include "raylib.h"

int main() {
    InitWindow(800, 600, "Test Raylib");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Raylib fonctionne!", 100, 300, 20, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
```

Compiler :
```bash
gcc test.c -o test.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

Si `test.exe` se crée et la fenêtre s'ouvre, vous êtes prêt!

---

## Dépannage

### "raylib.h: No such file or directory"
- Vérifier que Raylib est installé
- Vérifier le chemin d'include dans le Makefile/compilation

### Erreur de linking (error: reference to undefined symbol)
- Ajouter `-lraylib -lopengl32 -lgdi32 -lwinmm` aux flags de linking

### mingw32-make : command not found
- Installer MinGW-w64 correctement
- Ajouter le dossier bin au PATH

---

## Compilation rapide du projet Snake

Une fois Raylib installé, simplement :
```bash
cd C:\Users\HP\Desktop\ahmed
make
./build/snake.exe
```

Voilà! 🎮
