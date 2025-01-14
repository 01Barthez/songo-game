#ifndef GAME_H
#define GAME_H

#define ROWS 2
#define COLS 7

    typedef enum PlayerTurn {
        PLAYER_1 = 1,
        PLAYER_2
    } PlayerTurn;

    typedef struct {
        int board[ROWS][COLS];
        int house[2];
        PlayerTurn currentPlayer; // Joueur actuel
    } Game;

    // Prototypes des fonctions
    void initGame(Game *game);
    void playTurn(Game *game, int row, int col);
    int checkWin(Game *game);
    void resetGame(Game *game);

#endif
