#include "snake.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Initialiser le serpent
Snake snake_create(void) {
    Snake snake;
    snake.capacity = 100;
    snake.body = (Position*)malloc(snake.capacity * sizeof(Position));
    snake.length = 3;
    
    // Position initiale au centre
    int start_x = GRID_SIZE / 2;
    int start_y = GRID_SIZE / 2;
    
    for (int i = 0; i < snake.length; i++) {
        snake.body[i].x = start_x - i;
        snake.body[i].y = start_y;
    }
    
    snake.direction = RIGHT;
    snake.next_direction = RIGHT;
    
    return snake;
}

// Générer un nombre aléatoire entre min et max
int rand_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Spawner la nourriture
void food_spawn(Food* food, Snake* snake, int grid_width, int grid_height) {
    bool valid_position;
    
    do {
        valid_position = true;
        food->pos.x = rand_range(0, grid_width - 1);
        food->pos.y = rand_range(0, grid_height - 1);
        
        // Vérifier que la nourriture n'apparaît pas sur le serpent
        for (int i = 0; i < snake->length; i++) {
            if (snake->body[i].x == food->pos.x && snake->body[i].y == food->pos.y) {
                valid_position = false;
                break;
            }
        }
    } while (!valid_position);
    
    food->active = true;
}

// Vérifier si le serpent mange la nourriture
bool food_check_eat(Position head, Food* food) {
    if (food->active && head.x == food->pos.x && head.y == food->pos.y) {
        return true;
    }
    return false;
}

// Déplacer le serpent
void snake_move(Snake* snake) {
    // Valider le changement de direction (ne pas permettre 180 degrés)
    int old_dir = snake->direction;
    if ((old_dir == UP && snake->next_direction != DOWN) ||
        (old_dir == DOWN && snake->next_direction != UP) ||
        (old_dir == LEFT && snake->next_direction != RIGHT) ||
        (old_dir == RIGHT && snake->next_direction != LEFT)) {
        snake->direction = snake->next_direction;
    }
    
    // Créer une nouvelle position pour la tête
    Position new_head = snake->body[0];
    
    switch (snake->direction) {
        case UP:
            new_head.y--;
            break;
        case DOWN:
            new_head.y++;
            break;
        case LEFT:
            new_head.x--;
            break;
        case RIGHT:
            new_head.x++;
            break;
    }
    
    // Déplacer les autres segments
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = new_head;
}

// Faire grandir le serpent
void snake_grow(Snake* snake) {
    if (snake->length >= snake->capacity) {
        snake->capacity *= 2;
        snake->body = (Position*)realloc(snake->body, snake->capacity * sizeof(Position));
    }
    
    // Ajouter un nouveau segment à la fin
    snake->body[snake->length] = snake->body[snake->length - 1];
    snake->length++;
}

// Vérifier les collisions
bool snake_check_collision(Snake* snake) {
    Position head = snake->body[0];
    int grid_width = SCREEN_WIDTH / GRID_SIZE;
    int grid_height = SCREEN_HEIGHT / GRID_SIZE;
    
    // Collision avec les murs
    if (head.x < 0 || head.x >= grid_width || head.y < 0 || head.y >= grid_height) {
        return true;
    }
    
    // Collision avec lui-même
    for (int i = 1; i < snake->length; i++) {
        if (head.x == snake->body[i].x && head.y == snake->body[i].y) {
            return true;
        }
    }
    
    return false;
}

// Changer la direction du serpent
void snake_change_direction(Snake* snake, Direction new_dir) {
    snake->next_direction = new_dir;
}

// Libérer la mémoire du serpent
void snake_free(Snake* snake) {
    if (snake->body != NULL) {
        free(snake->body);
        snake->body = NULL;
    }
}

// Initialiser le jeu
GameState* game_init(void) {
    srand((unsigned int)time(NULL));
    
    GameState* state = (GameState*)malloc(sizeof(GameState));
    
    state->snake = snake_create();
    state->score = 0;
    state->frame_counter = 0;
    state->speed = INITIAL_SPEED;
    state->game_over = false;
    state->paused = false;
    
    int grid_width = SCREEN_WIDTH / GRID_SIZE;
    int grid_height = SCREEN_HEIGHT / GRID_SIZE;
    state->food.active = false;
    food_spawn(&state->food, &state->snake, grid_width, grid_height);
    
    return state;
}

// Mettre à jour l'état du jeu
void game_update(GameState* state) {
    if (state->game_over || state->paused) {
        return;
    }
    
    state->frame_counter++;
    
    // Déplacer le serpent à chaque N frames
    if (state->frame_counter >= (60 / state->speed)) {
        snake_move(&state->snake);
        state->frame_counter = 0;
        
        // Vérifier les collisions
        if (snake_check_collision(&state->snake)) {
            state->game_over = true;
            return;
        }
        
        // Vérifier si le serpent mange la nourriture
        if (food_check_eat(state->snake.body[0], &state->food)) {
            snake_grow(&state->snake);
            state->score += 10;
            
            // Augmenter légèrement la vitesse (max à 20)
            if (state->speed < 20) {
                state->speed += 0.5f;
            }
            
            int grid_width = SCREEN_WIDTH / GRID_SIZE;
            int grid_height = SCREEN_HEIGHT / GRID_SIZE;
            food_spawn(&state->food, &state->snake, grid_width, grid_height);
        }
    }
}

// Nettoyer le jeu
void game_cleanup(GameState* state) {
    if (state != NULL) {
        snake_free(&state->snake);
        free(state);
    }
}
