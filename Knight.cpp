#include "Knight.h"

Knight::Knight(Color color, Chessboard *chessboard) : Piece(color, chessboard) {
    this->type = Type::TKnight;
}

bool Knight::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {
    if (abs(this->getFile() - de_file) == 1 && abs(this->getRank() - de_rank) == 2) {
        if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
            capture_file = de_file;
            capture_rank = de_rank;
        }
        return true;
    } else if (abs(this->getFile() - de_file) == 2 && abs(this->getRank() - de_rank) == 1) {
        if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
            capture_file = de_file;
            capture_rank = de_rank;
        }
        return true;
    }
    return false;
}