#include "RestrictedPiece.h"

RestrictedPiece::RestrictedPiece(Color color, Chessboard *chessboard) : Piece(color, chessboard) {
    this->moved = false; 
}

void RestrictedPiece::hasMoved() {
    this->moved = true;
} 

bool RestrictedPiece::wasItMoved() {
    return moved;
}
