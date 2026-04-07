@echo off
REM Script de compilation pour le jeu Snake
REM Assure-vous que MinGW et Raylib sont installés

setlocal enabledelayedexpansion

echo ============================================
echo   Compilation du jeu Snake with Raylib
echo ============================================
echo.

REM Vérifier si les compilateurs sont disponibles
where gcc >nul 2>&1
if errorlevel 1 (
    echo ERREUR: gcc n'est pas trouvé!
    echo Assurez-vous que MinGW-w64 est installé et dans le PATH.
    echo.
    echo Consultez RAYLIB_INSTALL.md pour les instructions d'installation.
    pause
    exit /b 1
)

REM Créer le répertoire build s'il n'existe pas
if not exist build mkdir build

echo Compilation des fichiers source...
echo.

REM Compiler main.c
echo [1/2] Compilation de src/main.c...
gcc -Wall -Wextra -Iinclude -c src/main.c -o build/main.o
if errorlevel 1 (
    echo ERREUR lors de la compilation de main.c
    pause
    exit /b 1
)
echo OK!
echo.

REM Compiler snake.c
echo [2/2] Compilation de src/snake.c...
gcc -Wall -Wextra -Iinclude -c src/snake.c -o build/snake.o
if errorlevel 1 (
    echo ERREUR lors de la compilation de snake.c
    pause
    exit /b 1
)
echo OK!
echo.

echo Linking...
gcc build/main.o build/snake.o -o build/snake.exe -lraylib -lopengl32 -lgdi32 -lwinmm
if errorlevel 1 (
    echo ERREUR lors du linking!
    echo Vérifiez que Raylib est installé correctement.
    pause
    exit /b 1
)
echo.

echo ============================================
echo   Compilation réussie!
echo ============================================
echo.
echo L'exécutable se trouve à: build\snake.exe
echo.
echo Voulez-vous lancer le jeu? (oui/non)
set /p response=
if /i "%response%"=="oui" (
    build\snake.exe
) else if /i "%response%"=="yes" (
    build\snake.exe
) else (
    echo.
    echo Pour lancer le jeu manuellement, exécutez:
    echo   build\snake.exe
)

pause
