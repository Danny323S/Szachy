#ifndef QUEEN_H
#define QUEEN_H
#include "Chessboard.h"
#include "Piece.h"

class Queen : public Piece {
private:
    bool checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) override;

public:
    Queen(Color color, Chessboard *chessboard);
};

#endif