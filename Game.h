#ifndef GAME_H
#define GAME_H
#include <string.h>
#include "Chessboard.h"
#include "DisplayManager.h"
#include "Player.h"



class Game {
private:
    bool white_round;
    bool is_running;

    Chessboard board;
    DisplayManager display_manager;

    Player w_player;
    Player b_player;

public:
    Game();
    bool run(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank);
    void turn(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank);    
    Chessboard* getChessboard();
};

#endif