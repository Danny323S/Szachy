#ifndef PAWN_H
#define PAWN_H
#include <typeinfo>
#include "RestrictedPiece.h"
#include "Chessboard.h"

class Pawn : public RestrictedPiece {
private:
    bool en_passant_move;
    bool canBeCapturedEnPassant() override;
    bool checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) override;

public:
    Pawn(Color color, Chessboard *chessboard);
    virtual ~Pawn();
}; 

#endif