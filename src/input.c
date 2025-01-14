#include "../include/input.h"

int handleInput(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        return 0; 
    }
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        // Gestion des clics de souris
        int x = event->button.x;
        int y = event->button.y;
        
        // Calculer la colonne cliquée
        int column = x / 100;         
        return column;
    }
    
    return -1;
}
