#include "Rook.h"

Rook::Rook(Color color, Chessboard *chessboard) : RestrictedPiece(color, chessboard) {
    this->type = Type::TRook;
}

bool Rook::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {                                               
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
    }
    return false;
}
