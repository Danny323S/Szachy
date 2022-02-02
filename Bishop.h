#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
private:
    bool checkMove(int de_file, int de_rank) override;

public:
    Bishop(Color color, Chessboard *chessboard);
};

#endif