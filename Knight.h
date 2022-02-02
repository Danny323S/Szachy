#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
private:
    bool checkMove(int de_file, int de_rank)override;

public:
    Knight(Color color, Chessboard *chessboard);
};

#endif