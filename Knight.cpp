#include "Knight.h"

Knight::Knight(Color color, Chessboard *chessboard) : Piece(color, chessboard) {
    this->type = Type::TKnight;
}

bool Knight::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {
    //Mo


    return false;
}