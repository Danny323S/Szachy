#include "King.h"

King::King(Color color, Chessboard *chessboard) : RestrictedPiece(color, chessboard) {
    this->type = Type::TKing;
}

bool King::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {
    if ((abs(de_file - this->getFile()) <= 1) && (abs(de_rank - this->getRank()) <= 1)) {
        if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()){
            if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                capture_file = de_file;
                capture_rank = de_rank;
                return true;
            }
        } else return true;
    } else if (!this->wasItMoved()) { // jeżeli nie był ruszany -> sprawdzenie możliwośći roszady
        if (de_file == 2 && de_rank == this->getRank()) { //queenside
            if (getChessboard()->getSquareAt(0, this->getRank())->isOccupied()) {
                if(!getChessboard()->getSquareAt(0, this->getRank())->getOccupant()->wasItMoved()) {
                    if (getChessboard()->isRankClear(this->getRank(), 1, 3)) {
                        return true;
                    }
                }
            }
        } else if (de_file == 6 && de_rank == this->getRank()) { // kingside
            if (getChessboard()->getSquareAt(7, this->getRank())->isOccupied()) {
                if(!getChessboard()->getSquareAt(7, this->getRank())->getOccupant()->wasItMoved()) {
                    if (getChessboard()->isRankClear(this->getRank(), 5, 6)) {
                        return true;
                    }
                }
            }
        }
    }                                   

    return false;
}

