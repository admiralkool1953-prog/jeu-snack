#include "raylib.h"
#include "snake.h"
#include <stdio.h>

// Couleurs personnalisées
#define COLOR_SNAKE (Color){0, 200, 0, 255}       // Vert
#define COLOR_FOOD (Color){255, 0, 0, 255}        // Rouge
#define COLOR_GRID (Color){50, 50, 50, 255}       // Gris foncé
#define COLOR_BG (Color){10, 10, 10, 255}         // Noir
#define COLOR_TEXT (Color){255, 255, 255, 255}    // Blanc
#define COLOR_PAUSE (Color){255, 255, 0, 255}     // Jaune

// Fonction pour dessiner le jeu
void draw_game(GameState* state) {
    BeginDrawing();
    ClearBackground(COLOR_BG);
    
    // Dessiner la grille
    int grid_width = SCREEN_WIDTH / GRID_SIZE;
    int grid_height = SCREEN_HEIGHT / GRID_SIZE;
    
    for (int i = 0; i <= grid_width; i++) {
        DrawLine(i * GRID_SIZE, 0, i * GRID_SIZE, SCREEN_HEIGHT, COLOR_GRID);
    }
    for (int i = 0; i <= grid_height; i++) {
        DrawLine(0, i * GRID_SIZE, SCREEN_WIDTH, i * GRID_SIZE, COLOR_GRID);
    }
    
    // Dessiner le serpent
    for (int i = 0; i < state->snake.length; i++) {
        Rectangle rect = {
            state->snake.body[i].x * GRID_SIZE,
            state->snake.body[i].y * GRID_SIZE,
            GRID_SIZE - 1,
            GRID_SIZE - 1
        };
        
        // La tête est plus claire
        if (i == 0) {
            DrawRectangleRec(rect, (Color){0, 255, 0, 255});
        } else {
            DrawRectangleRec(rect, COLOR_SNAKE);
        }
    }
    
    // Dessiner la nourriture
    if (state->food.active) {
        Rectangle food_rect = {
            state->food.pos.x * GRID_SIZE,
            state->food.pos.y * GRID_SIZE,
            GRID_SIZE - 1,
            GRID_SIZE - 1
        };
        DrawRectangleRec(food_rect, COLOR_FOOD);
        
        // Ajouter un petit point au centre pour la visibilité
        DrawCircle(
            state->food.pos.x * GRID_SIZE + GRID_SIZE / 2,
            state->food.pos.y * GRID_SIZE + GRID_SIZE / 2,
            GRID_SIZE / 4,
            (Color){255, 150, 0, 255}
        );
    }
    
    // Dessiner l'interface utilisateur
    // Score
    char score_text[50];
    snprintf(score_text, sizeof(score_text), "Score: %d", state->score);
    DrawText(score_text, 10, 10, 20, COLOR_TEXT);
    
    // Longeur du serpent
    char length_text[50];
    snprintf(length_text, sizeof(length_text), "Length: %d", state->snake.length);
    DrawText(length_text, 10, 35, 20, COLOR_TEXT);
    
    // Vitesse
    char speed_text[50];
    snprintf(speed_text, sizeof(speed_text), "Speed: %.1f", state->speed);
    DrawText(speed_text, 10, 60, 20, COLOR_TEXT);
    
    // Message de pause
    if (state->paused) {
        DrawText("PAUSED - Press P to Resume", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 20, 30, COLOR_PAUSE);
    }
    
    // Message de game over
    if (state->game_over) {
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0, 0, 0, 200});
        
        char game_over_text[100];
        snprintf(game_over_text, sizeof(game_over_text), "Game Over! Final Score: %d", state->score);
        DrawText(game_over_text, SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 40, 30, COLOR_TEXT);
        
        char restart_text[50];
        snprintf(restart_text, sizeof(restart_text), "Press R to Restart or Q to Quit");
        DrawText(restart_text, SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT / 2 + 20, 20, COLOR_TEXT);
    }
    
    // Contrôles (coin bas)
    DrawText("Controls: ARROWS or WASD - Move | P - Pause | R - Restart | Q - Quit", 
             10, SCREEN_HEIGHT - 30, 15, (Color){150, 150, 150, 255});
    
    EndDrawing();
}

// Fonction pour gérer l'entrée utilisateur
void handle_input(GameState* state) {
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
        if (state->snake.direction != DOWN) {
            snake_change_direction(&state->snake, UP);
        }
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        if (state->snake.direction != UP) {
            snake_change_direction(&state->snake, DOWN);
        }
    }
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
        if (state->snake.direction != RIGHT) {
            snake_change_direction(&state->snake, LEFT);
        }
    }
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
        if (state->snake.direction != LEFT) {
            snake_change_direction(&state->snake, RIGHT);
        }
    }
    
    if (IsKeyPressed(KEY_P)) {
        state->paused = !state->paused;
    }
}

// Fonction pour réinitialiser le jeu
void restart_game(GameState* state) {
    game_cleanup(state);
    state = game_init();
}

int main(void) {
    // Initialisation de la fenêtre
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game - Raylib");
    SetTargetFPS(60);
    
    // Initialiser le jeu
    GameState* game = game_init();
    
    // Boucle principale
    while (!WindowShouldClose()) {
        // Gestion de l'entrée
        handle_input(game);
        
        if (game->game_over) {
            if (IsKeyPressed(KEY_R)) {
                game_cleanup(game);
                game = game_init();
            } else if (IsKeyPressed(KEY_Q)) {
                break;
            }
        }
        
        // Mise à jour du jeu
        game_update(game);
        
        // Dessin
        draw_game(game);
    }
    
    // Nettoyage
    game_cleanup(game);
    CloseWindow();
    
    return 0;
}
