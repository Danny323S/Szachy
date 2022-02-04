#ifndef GAMENEW_H
#define GAMENWE_H
#include <string.h>
#include "Chessboard.h"
#include "DisplayManager.h"
#include "Player.h"

class GameNew {
private:
    bool white_round;
    bool is_running;

    Chessboard board;
    DisplayManager display_manager;

    Player w_player;
    Player b_player;

public:
    GameNew();
    bool run(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank);
    void turn(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank);    
    Chessboard* getChessboard();

    bool selectPiece(int piece_to_select_file, int piece_to_select_rank);
    bool chooseDestinationSquare();
    bool turn();
    bool promotion();
    bool endOfGame();
};

#endif