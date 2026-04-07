#include "raylib.h"
#include "snake.h"
#include <stdio.h>
#include <math.h>

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
    
    // Dessiner un dégradé de fond subtil
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        float alpha = 1.0f - (i / (float)SCREEN_HEIGHT) * 0.3f;
        Color gradient = {20, 20, 30, (unsigned char)(255 * alpha)};
        DrawLine(0, i, SCREEN_WIDTH, i, gradient);
    }
    
    // Dessiner la grille avec effet lumineux
    int grid_width = SCREEN_WIDTH / GRID_SIZE;
    int grid_height = SCREEN_HEIGHT / GRID_SIZE;
    
    for (int i = 0; i <= grid_width; i++) {
        Color grid_color = (i % 5 == 0) ? (Color){70, 70, 85, 255} : (Color){50, 50, 60, 255};
        DrawLine(i * GRID_SIZE, 0, i * GRID_SIZE, SCREEN_HEIGHT, grid_color);
    }
    for (int i = 0; i <= grid_height; i++) {
        Color grid_color = (i % 5 == 0) ? (Color){70, 70, 85, 255} : (Color){50, 50, 60, 255};
        DrawLine(0, i * GRID_SIZE, SCREEN_WIDTH, i * GRID_SIZE, grid_color);
    }
    
    // Dessiner le serpent avec dégradé de couleur
    for (int i = 0; i < state->snake.length; i++) {
        float progress = (float)i / state->snake.length;
        Rectangle rect = {
            state->snake.body[i].x * GRID_SIZE + 1,
            state->snake.body[i].y * GRID_SIZE + 1,
            GRID_SIZE - 3,
            GRID_SIZE - 3
        };
        
        // Gradient de couleur : tête verte brillante -> corps plus foncé
        if (i == 0) {
            // Tête : vert brillant avec ombre
            DrawRectangleRec(rect, (Color){50, 255, 50, 255});
            DrawRectangleLines((int)rect.x - 1, (int)rect.y - 1, (int)rect.width + 2, (int)rect.height + 2, (Color){100, 255, 100, 180});
            // Petit cercle pour les yeux
            DrawCircle((int)(rect.x + 4), (int)(rect.y + 4), 1.5f, (Color){255, 255, 255, 255});
        } else { avec animation
    if (state->food.active) {
        float pulse = sinf(GetTime() * 4.0f) * 2.0f + 3.0f;  // Animation pulsante
        Rectangle food_rect = {
            state->food.pos.x * GRID_SIZE + 2,
            state->food.pos.y * GRID_SIZE + 2,
            GRID_SIZE - 5,
            GRID_SIZE - 5
        };
        
        // Nourriture avec dégradé : rouge clair -> rouge foncé
        DrawRectangleRec(food_rect, (Color){255, 100, 100, 255});
        DrawRectangleGradientEx(food_rect, (Color){255, 50, 50, 255}, (Color){200, 0, 0, 255}, 
                                (Color){200, 0, 0, 255}, (Color){255, 50, 50, 255});
        
        // Aura pulsante autour de la nourriture
        DrawCircleLines(
            state->food.pos.x * GRID_SIZE + GRID_SIZE / 2,
            state->food.pos.y * GRID_SIZE + GRID_SIZE / 2,
            GRID_SIZE / 3 + pulse,
            (Color){255, 150, 100, (unsigned char)(200 - pulse * 30)}
        );
        
        // Point lumineux au centre
        DrawCircle(
            state->food.pos.x * GRID_SIZE + GRID_SIZE / 2,
            state->food.pos.y * GRID_SIZE + GRID_SIZE / 2,
            2.0f + pulse / 4.0f,
            (Color){255, 200, 10* GRID_SIZE,
            GRID_SIZE - 1,
            GRID_SIZE - 1 avec panneaux
    // Panneau de stats (semi-transparent)
    DrawRectangle(5, 5, 200, 100, (Color){10, 10, 20, 200});
    DrawRectangleLines(5, 5, 200, 100, (Color){50, 150, 255, 255});
    
    // Score
    char score_text[50];
    snprintf(score_text, sizeof(score_text), "Score: %d", state->score);
    DrawText("🏆", 15, 15, 20, (Color){255, 215, 0, 255});
    DrawText(score_text, 40, 15, 20, (Color){255, 255, 100, 255});
    
    // Longueur du serpent
    char length_text[50];
    snprintf(length_text, sizeof(length_text), "Length: %d", state->snake.length);
    DrawText("📏", 15, 40, 20, (Color){100, 200, 255, 255});
    DrawText(length_text, 40, 40, 20, COLOR_TEXT);
     avec animation
    if (state->paused) {
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0, 0, 0, 150});
        
        // Box de pause
        int box_width = 400;
        int box_height = 150;
        int box_x = SCREEN_WIDTH / 2 - box_width / 2;
        int box_y = SCREEN_HEIGHT / 2 - box_height / 2;
        
        DrawRectangle(box_x, box_y, box_width, box_height, (Color){20, 20, 50, 255});
        DrawRectangleLines(box_x, box_y, box_width, box_height, (Color){255, 255, 0, 255});
        
        float pulse = sinf(GetTime() * 3.0f);
        DrawText("⏸ PAUSED ⏸", SCREEN_WIDTH / 2 - 80, box_y + 20, 40, 
                (Color){255, 255, (unsigned char)(100 + pulse * 50), 255});
        
        DrawText("Press P to Resume", SCREEN_WIDTH / 2 - 150, box_y + 80, 20, (Color){200, 200, 200, 255});
    }
    
    // Message de game over avec animation
    if (state->game_over) {
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0, 0, 0, 220});
        
        int box_width = 500;
        int box_height = 200;
        int box_x = SCREEN_WIDTH / 2 - box_width / 2;
        int box_y = SCREEN_HEIGHT / 2 - box_height / 2;
        
        // Animation couleur
        float color_pulse = sinf(GetTime() * 2.5f);
       Panel de contrôles (coin bas)
    DrawRectangle(5, SCREEN_HEIGHT - 35, SCREEN_WIDTH - 10, 30, (Color){10, 10, 20, 200});
    DrawRectangleLines(5, SCREEN_HEIGHT - 35, SCREEN_WIDTH - 10, 30, (Color){100, 100, 150, 255});
    DrawText("⌨️ ARROWS/WASD: Move | P: Pause | R: Restart | Q: Quit", 
             15, SCREEN_HEIGHT - 28, 14, (Color){150, 200, 255, (Color){255, 100, 100, 255});
        
        DrawText("💀 GAME OVER 💀", SCREEN_WIDTH / 2 - 150, box_y + 20, 40, (Color){255, 100, 100, 255});
        
        char game_over_text[100];
        snprintf(game_over_text, sizeof(game_over_text), "Final Score: %d", state->score);
        DrawText(game_over_text, SCREEN_WIDTH / 2 - 100, box_y + 80, 30, (Color){255, 215, 0, 255});
        
        DrawText("R - Restart  |  Q - Quit", SCREEN_WIDTH / 2 - 140, box_y + 140, 20, (Color){150, 200, 255, 255}
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
