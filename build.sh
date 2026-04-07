#!/bin/bash
# Script de compilation pour le jeu Snake (Linux/macOS)

echo "============================================"
echo "  Compilation du jeu Snake with Raylib"
echo "============================================"
echo ""

# Vérifier si gcc est disponible
if ! command -v gcc &> /dev/null; then
    echo "ERREUR: gcc n'est pas trouvé!"
    echo "Installez GCC et Raylib avant de continuer."
    exit 1
fi

# Créer le répertoire build
mkdir -p build

echo "Compilation des fichiers source..."
echo ""

# Compiler main.c
echo "[1/2] Compilation de src/main.c..."
gcc -Wall -Wextra -Iinclude -c src/main.c -o build/main.o
if [ $? -ne 0 ]; then
    echo "ERREUR lors de la compilation de main.c"
    exit 1
fi
echo "OK!"
echo ""

# Compiler snake.c
echo "[2/2] Compilation de src/snake.c..."
gcc -Wall -Wextra -Iinclude -c src/snake.c -o build/snake.o
if [ $? -ne 0 ]; then
    echo "ERREUR lors de la compilation de snake.c"
    exit 1
fi
echo "OK!"
echo ""

echo "Linking..."
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    gcc build/main.o build/snake.o -o build/snake -lraylib -lGL -lpthread -ldl -lm
else
    # Linux
    gcc build/main.o build/snake.o -o build/snake -lraylib -lGL -lpthread -ldl -lm
fi

if [ $? -ne 0 ]; then
    echo "ERREUR lors du linking!"
    echo "Vérifiez que Raylib est installé correctement."
    exit 1
fi

echo ""
echo "============================================"
echo "  Compilation réussie!"
echo "============================================"
echo ""
echo "L'exécutable se trouve à: build/snake"
echo ""
echo "Voulez-vous lancer le jeu? (oui/non)"
read response
if [[ "$response" == "oui" || "$response" == "yes" ]]; then
    ./build/snake
else
    echo ""
    echo "Pour lancer le jeu manuellement, exécutez:"
    echo "  ./build/snake"
fi
