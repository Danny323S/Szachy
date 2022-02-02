#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <vector>
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
    //void move();
    //void capture();

public: 
    Chessboard();
    Square* getSquareAt(int file, int rank);
    
    bool isRankClear(int rakn, int from_file, int to_file);
    bool isFileClear(int file, int from_rank, int to_rank);
    bool isDiagonalClear(int from_file, int from_rank, int to_file, int to_rank);

    void promote();
    void capture(int piece_file, int piece_rank);

    void update();
};

#endif