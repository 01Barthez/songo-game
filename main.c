#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include "include/game.h"
#include "include/graphics.h"

// Dimensions de la fenêtre
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de SDL : %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Jeu de Songo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("Erreur de création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur de création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Initialisation du jeu
    Game game;
    initGame(&game);

    bool running = true;
    SDL_Event event;

    while (running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;

                // Calculer la case cliquée
                int col = (x - SCREEN_WIDTH / 14) / (SCREEN_WIDTH / 7);
                int row = y / (SCREEN_HEIGHT / 2);

                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    // Jouer le tour
                    playTurn(&game, row, col);

                    // Vérifier si quelqu'un a gagné
                    int winner = checkWin(&game);
                    if (winner) {
                        printf("Joueur %d gagne !\n", winner);
                        running = false;
                    }
                }
            }
        }

        // Afficher le plateau
        renderBoard(renderer, &game);
    }

    // Libération des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
