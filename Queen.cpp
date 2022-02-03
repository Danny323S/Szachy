#include "Queen.h"

Queen::Queen(Color color, Chessboard *chessboard) : Piece(color, chessboard) {
    this->type = Type::TQueen;
}

bool Queen::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank){                                                   
    //połączenie metod checkMove() klas Bishop i Rook
    //możliwe aruchy - po przekątnej - wertykalnie - horyzontalnie
    if (de_file == this->getFile() && de_rank != this->getRank()) { // poruszanie vertykalne
        if (abs(de_rank - this->getRank()) == 1) { // jeżeli ruch o jedno pole 
            if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) { //jeżeli pole jest okupowane
                if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) { 
                    capture_file = de_file;
                    capture_rank = de_rank;
                    return true;
                }
            } else return true;
        } else if (de_rank - this->getRank() > 0) { // ruch w górę 
            if(getChessboard()->isFileClear(this->getFile(), this->getRank() + 1, de_rank - 1)) {
                if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    }
                } else return true;
            }
        } else if (de_rank - this->getRank() < 0 ) { // ruch w dół planszy
            if(getChessboard()->isFileClear(this->getFile(), this->getRank() - 1, de_rank + 1)) {
                if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    }
                } else return true;
            }
        }
    } else if (de_file != this->getFile() && de_rank == this->getRank()) { // poruszanie horyzontalne
        if (abs(de_file - this->getFile()) == 1) { // jeżeli ruch o jedno pole 
            if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) { //jeżeli pole jest okupowane
                if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) { 
                    capture_file = de_file;
                    capture_rank = de_rank;
                    return true;
                }
            } else return true;     
        } else if (de_file - this->getFile() > 0) {//ruch w prawo o więcje niż jedno pole
            if(getChessboard()->isRankClear(this->getRank(), this->getFile() + 1, de_file - 1)) {
                if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    }
                } else return true;
            } 
        } else if (de_file - this->getFile() < 0) {// ruch w lewo o więcej niz jedno pole 
            if(getChessboard()->isRankClear(this->getRank(), this->getFile() - 1, de_file + 1)) {
                if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) {
                    if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank;
                        return true;
                    }
                } else return true;
            }
        }
    } else if (abs(de_file - this->getFile()) == abs(de_rank - this->getRank())) {// jeżeli ruch jest po przekątnje 
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

