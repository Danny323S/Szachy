#ifndef ROOK_H
#define ROOK_H
#include "Chessboard.h"
#include "RestrictedPiece.h"

class Rook : public RestrictedPiece {
private:
    bool checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) override;

public:
    Rook(Color color, Chessboard *chessboard);
};

#endif