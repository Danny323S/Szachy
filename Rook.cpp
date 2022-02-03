#include "Rook.h"

Rook::Rook(Color color, Chessboard *chessboard) : RestrictedPiece(color, chessboard) {
    this->type = Type::TRook;
}

bool Rook::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {                                                   
    std::cout << "de_file: " << de_file << ", " << "de_rank: " << de_rank << std::endl;
    return false;
}
