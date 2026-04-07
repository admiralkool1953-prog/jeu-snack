#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>

// Constantes du jeu
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRID_SIZE 20
#define INITIAL_SPEED 8

// Énumérations pour les directions
typedef enum {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
} Direction;

// Structure pour une position (x, y)
typedef struct {
    int x;
    int y;
} Position;

// Structure pour le serpent
typedef struct {
    Position* body;      // Tableau des segments du corps
    int length;          // Longueur actuelle du serpent
    int capacity;        // Capacité du tableau
    Direction direction; // Direction actuelle
    Direction next_direction; // Pour traiter les changements rapides de direction
} Snake;

// Structure pour la nourriture
typedef struct {
    Position pos;
    bool active;
} Food;

// Structure pour l'état du jeu
typedef struct {
    Snake snake;
    Food food;
    int score;
    int frame_counter;
    int speed;
    bool game_over;
    bool paused;
} GameState;

// Fonctions du jeu
GameState* game_init(void);
void game_update(GameState* state);
void game_draw(GameState* state);
void game_cleanup(GameState* state);

// Fonctions du serpent
Snake snake_create(void);
void snake_move(Snake* snake);
void snake_grow(Snake* snake);
bool snake_check_collision(Snake* snake);
void snake_change_direction(Snake* snake, Direction new_dir);
void snake_free(Snake* snake);

// Fonctions de la nourriture
void food_spawn(Food* food, Snake* snake, int grid_width, int grid_height);
bool food_check_eat(Position head, Food* food);

// Fonctions utilitaires
int rand_range(int min, int max);
void input_handle(GameState* state);

#endif // SNAKE_H
