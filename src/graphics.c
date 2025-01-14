#include "../include/graphics.h"
#include <SDL2/SDL.h>

void renderBoard(SDL_Renderer *renderer, Game *game) {
    int screenWidth = 800, screenHeight = 600;
    int cellWidth = screenWidth / (COLS + 2); // +2 pour inclure les maisons
    int cellHeight = screenHeight / ROWS;

    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // Marron chocolat
    SDL_RenderClear(renderer);

    // Dessiner le plateau
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            SDL_Rect cell = {col * cellWidth + cellWidth, row * cellHeight, cellWidth, cellHeight};
            SDL_SetRenderDrawColor(renderer, 205, 133, 63, 255); // Marron clair
            SDL_RenderFillRect(renderer, &cell);

            // Dessiner les pions
            int seeds = game->board[row][col];
            for (int i = 0; i < seeds; i++) {
                int x = cell.x + (i % 3) * (cellWidth / 4) + cellWidth / 8;
                int y = cell.y + (i / 3) * (cellHeight / 4) + cellHeight / 8;
                SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255); // Jaune doré
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }

    // Dessiner les maisons
    SDL_Rect house1 = {0, 0, cellWidth, screenHeight};
    SDL_Rect house2 = {screenWidth - cellWidth, 0, cellWidth, screenHeight};
    SDL_SetRenderDrawColor(renderer, 160, 82, 45, 255); // Marron foncé
    SDL_RenderFillRect(renderer, &house1);
    SDL_RenderFillRect(renderer, &house2);

    SDL_RenderPresent(renderer);
}
