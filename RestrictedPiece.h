#ifndef RESTRICTEDPIECE_H
#define RESTRICTEDPIECE_H
#include "Piece.h"

class RestrictedPiece : public Piece {
private:
    bool moved;

protected:
    RestrictedPiece(Color color, Chessboard *chessboard);
    void hasMoved();

public:
    bool wasItMoved();
};

#endif