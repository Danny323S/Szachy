#include "King.h"

King::King(Color color, Chessboard *chessboard) : RestrictedPiece(color, chessboard) {
    this->type = Type::TKing;
}

bool King::checkMove(int de_file, int de_rank) {                                                   
    std::cout << "de_file: " << de_file << ", " << "de_rank: " << de_rank << std::endl;
    return false;
}

