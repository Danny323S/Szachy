#ifndef ROOK_H
#define ROOK_H
#include "RestrictedPiece.h"

class Rook : public RestrictedPiece {
private:
    bool checkMove(int de_file, int de_rank) override;

public:
    Rook(Color color, Chessboard *chessboard);
};

#endif