#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "game.h"

// Prototypes des fonctions
void initGraphics(SDL_Window **window, SDL_Renderer **renderer);
void renderGame(SDL_Renderer *renderer, Game *game);
void renderBoard(SDL_Renderer *renderer, Game *game);
void renderGameOver(SDL_Renderer *renderer, int winner);
void renderCircle(SDL_Renderer *renderer, int x, int y, int radius, int r, int g, int b);
void cleanup_SDL(void);
#endif
