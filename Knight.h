#ifndef KNIGHT_H
#define KNIGHT_H
#include <cmath>
#include "Chessboard.h"
#include "Piece.h"

class Knight : public Piece {
private:
    bool checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) override;

public:
    Knight(Color color, Chessboard *chessboard);
};

#endif