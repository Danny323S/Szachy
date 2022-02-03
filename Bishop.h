#ifndef BISHOP_H
#define BISHOP_H
#include "Chessboard.h"
#include "Piece.h"

class Bishop : public Piece {
private:
    bool checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) override;

public:
    Bishop(Color color, Chessboard *chessboard);
};

#endif