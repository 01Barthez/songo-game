#include "../include/game.h"
#include <stdio.h>

void initGame(Game *game) {
    // Initialiser le plateau avec 5 pions par trou
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game->board[i][j] = 5;
        }
    }
    // Initialiser les maisons
    game->house[0] = 0; // Maison du joueur 1
    game->house[1] = 0; // Maison du joueur 2
    // Le joueur 1 commence
    game->currentPlayer = PLAYER_1;
}

void playTurn(Game *game, int row, int col) {
    // Vérifier si le trou est valide
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || game->board[row][col] == 0) {
        printf("Mouvement invalide !\n");
        return;
    }

    int seeds = game->board[row][col];
    game->board[row][col] = 0; // Vider le trou sélectionné
    int currentRow = row, currentCol = col;

    // Distribution des pions
    while (seeds > 0) {
        currentCol++;
        if (currentCol == COLS) {
            currentCol = 0;
            currentRow = (currentRow + 1) % ROWS;
        }
        game->board[currentRow][currentCol]++;
        seeds--;
    }

    // Capture si le dernier pion tombe dans un trou vide du camp adverse
    if (game->board[currentRow][currentCol] == 1 && currentRow != row) {
        int oppositeRow = (currentRow + 1) % ROWS;
        int capturedSeeds = game->board[oppositeRow][currentCol];
        game->board[oppositeRow][currentCol] = 0;
        game->house[game->currentPlayer - 1] += capturedSeeds + 1;
        game->board[currentRow][currentCol] = 0;
    }

    // Changer de joueur
    game->currentPlayer = (game->currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
}

int checkWin(Game *game) {
    // Vérifier si un des camps est vide
    int player1Seeds = 0, player2Seeds = 0;

    for (int j = 0; j < COLS; j++) {
        player1Seeds += game->board[0][j];
        player2Seeds += game->board[1][j];
    }

    if (player1Seeds == 0 || player2Seeds == 0) {
        return (player1Seeds > player2Seeds) ? PLAYER_1 : PLAYER_2;
    }
    return 0; // Pas encore de gagnant
}

void resetGame(Game *game) {
    initGame(game);
}
