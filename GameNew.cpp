#include "GameNew.h"

GameNew::GameNew() : board(), display_manager(board), w_player(white ,board), b_player(black ,board) {
    is_running = true;
    white_round = true;

    display_manager.render();
}

bool GameNew::run(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank) {
    turn(selected_piece_file, selected_piece_rank, destination_file, destination_rank);
    display_manager.render();
    return true;
}

bool GameNew::selectPiece(int piece_to_select_file, int piece_to_select_rank) {
    Player *actual_player;

    if(white_round) {
        actual_player = &w_player;
        std::cout << "Ruch Bialego\n";
    } else {
        actual_player = &b_player;
        std::cout << "Ruch Czarnego\n";
    }

    if (board.getSquareAt(piece_to_select_file,piece_to_select_rank)->isOccupied()) {
        if (actual_player->selectPiece(piece_to_select_file, piece_to_select_rank)) {
            return true;
        } else {
            std::cout << "Na wybaranym polu nie ma bierki";
            std::cout << "Lub jest niewłaściwego koloru";
        }
    }

    
}