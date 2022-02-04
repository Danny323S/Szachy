#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <vector>
#include <typeinfo>
#include "Square.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"


#define DIMENSION 8


class Chessboard {
private:
    Square chessboard[DIMENSION][DIMENSION];

    // std::vector<Piece*> pieces;
    // std::vector<Piece> white_set;
    // std::vector<Piece> black_set;

    void capture(int piece_file, int piece_rank);
    void castling(Piece *piece_to_move, int de_file, int de_rank);
    void move(Piece *piece_to_move, int de_file, int de_rank);
    bool promote();

public: 
    Chessboard();
    Square* getSquareAt(int file, int rank);
    
    bool isRankClear(int rakn, int from_file, int to_file);
    bool isFileClear(int file, int from_rank, int to_rank);
    bool isDiagonalClear(int from_file, int from_rank, int to_file, int to_rank);

    void update(Piece *piece_to_move, int de_file, int de_rank, Piece *piece_to_capture);
    bool checkPromotion();
};

#endif