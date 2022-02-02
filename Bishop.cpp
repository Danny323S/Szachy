#include "Bishop.h"

Bishop::Bishop(Color color, Chessboard *chessboard) : Piece(color, chessboard) {
    this->type = Type::TBishop;
}

bool Bishop::checkMove(int de_file, int de_rank) {                                                   
    std::cout << "de_file: " << de_file << ", " << "de_rank: " << de_rank << std::endl;
    return false;
}
