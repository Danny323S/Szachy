#include "Bishop.h"

Bishop::Bishop(Color color, Chessboard *chessboard) : Piece(color, chessboard) {
    this->type = Type::TBishop;
}

bool Bishop::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {                                                   
    if (abs(de_file - this->getFile()) == abs(de_rank - this->getRank())) {// jeżeli ruch jest po przekątnje 
        if (abs(de_file - this->getFile()) == 1) { //jeżeli ruch o jedno pole 
            if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                    capture_file = de_file;
                    capture_rank = de_rank;
                    return true;
                } 
            } else return true;
        } else if (de_file - this->getFile() > 0 && de_rank - this->getRank() > 0) { //(+,+)
            if (getChessboard()->isDiagonalClear(this->getFile() + 1, this->getRank() + 1, de_file - 1, de_rank - 1)) {
                if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    } 
                } else return true;
            }
        } else if (de_file - this->getFile() < 0 && de_rank - this->getRank() < 0) { //(-,-)
            if (getChessboard()->isDiagonalClear(this->getFile() - 1, this->getRank() - 1, de_file + 1, de_rank + 1)) {
                if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    } 
                } else return true;
            }
        } else if (de_file - this->getFile() < 0 && de_rank - this->getRank() > 0) { //(-,+)
            if (getChessboard()->isDiagonalClear(this->getFile() - 1, this->getRank() + 1, de_file + 1, de_rank - 1)) {
                if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    } 
                } else return true;
            }
        } else if (de_file - this->getFile() > 0 && de_rank - this->getRank() < 0) { //(+,-)
            if (getChessboard()->isDiagonalClear(this->getFile() + 1, this->getRank() - 1, de_file - 1, de_rank + 1)) {
                if(getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    } 
                } else return true;
            }
        }
    }
    return false;
}
