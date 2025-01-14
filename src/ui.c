#include "../include/ui.h"
#include <SDL2/SDL_ttf.h>

// Fonction pour afficher un bouton
void renderButton(SDL_Renderer *renderer, int x, int y, const char *label) {
    // Dimensions du bouton
    int width = 150;
    int height = 50;

    // Couleurs du bouton (marron chocolaté pour le fond et blanc pour le texte)
    SDL_Color buttonColor = {111, 49, 19, 255}; // Marron chocolaté
    SDL_Color textColor = {255, 255, 255, 255}; // Blanc

    // Créer le rectangle du bouton
    SDL_Rect buttonRect = {x, y, width, height};

    // Dessiner le rectangle du bouton
    SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(renderer, &buttonRect);

    // Afficher le texte au centre du bouton
    TTF_Font *font = TTF_OpenFont("/assets/font.ttf", 24);
    if (font == NULL) {
        printf("Font loading error: %s\n", TTF_GetError());
        return;
    }

    // Créer la surface contenant le texte
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, label, textColor);
    if (textSurface == NULL) {
        printf("Text rendering error: %s\n", TTF_GetError());
        return;
    }

    // Créer une texture à partir de la surface
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        printf("Texture creation error: %s\n", SDL_GetError());
        return;
    }

    // Calculer la position du texte pour le centrer
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_Rect textRect = {x + (width - textWidth) / 2, y + (height - textHeight) / 2, textWidth, textHeight};

    // Dessiner le texte sur le bouton
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Libérer les ressources
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
}
