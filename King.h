#ifndef KING_H
#define KING_H
#include "RestrictedPiece.h"

class King : public RestrictedPiece {
private:
    bool checkMove(int de_file, int de_rank) override;

public:
    King(Color color, Chessboard *chessboard);
};
#endif