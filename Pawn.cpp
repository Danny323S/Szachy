#include "Pawn.h"

Pawn::Pawn(Color color, Chessboard *chessboard) : RestrictedPiece(color, chessboard) {
    this->type = Type::TPawn;
}

Pawn::~Pawn() {
    std::cout << "Pawn destructed\n";
}

bool Pawn::canBeCapturedEnPassant() {
    return en_passant_move;
//     if ((this->getColor() == white && this->getRank() == 3) || (this->getColor() == black && this->getRank() == 4)) {
//         if (this->en_passant_move == true ) {
//             return true;
//         }
//     }
//     return false;
}

bool Pawn::checkMove(int de_file, int de_rank, int &capture_file, int &capture_rank) {
//Możliwe ruchy 
//BIAŁY PION (0,1) - ruch podstawowy. możliwy jeżeli na polu nie stoi żaden inny pionek 
//           (0,2) - ruch specjalny, możliwy jeżeli bierka nie była wcześniej ruszona (wasItMoved == false), jeżeli pole po drodze jest puste i to pole także, 
//           (1,1) - bicie, na polu musi znajdować się bierka przeciwnego koloru, lub bicie w przelocie
//           (-1,1) - bicie, na polu musi znajdować się bierka przeciwnego koloru, lub bicie w przelocie
//CZARNY PION (0,-1), (0,-2),  (1,-1), (-1,-1)

    int y_direction = 1;
    en_passant_move = false;

    if (this->getColor() == white) {
        y_direction = 1;
    } else {
        y_direction = -1;
    }

    if (de_file == this->getFile() && de_rank == this->getRank() + 1*y_direction) { //ruch o jeden w przód
        if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied() == false) {
            // std::cout << "returning true: \n";
            return true;
        }

    } else if (de_file == this->getFile() && de_rank == this->getRank() + 2*y_direction) { //ruch o dwa pola w pierwszej turze
        //sprwdzenie czy pionek był ruszany 
        //sprawdzenie czy na drodze nie stoi żadna inna bierka
        //sprawdzenei czy pole "destination" nie jest zajmowane przez inny pionek

        //jeżeli bierka zostanie poruszona:
        //1.en_passant_move == true 
        //2.zmiana wasMove == true

        if(!this->wasItMoved()) {
            if(getChessboard()->isFileClear(this->getFile(), this->getRank() + 1*y_direction, de_rank) == true) {
                this->en_passant_move = true;
                this->hasMoved(); //Powinno być w klasie gracza
                return true;
            }
        }
    } else if (de_file == this->getFile() + 1 && de_rank == this->getRank() + 1*y_direction) { 
        if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) { //podstawowe bicie
            if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                capture_file = de_file;
                capture_rank = de_rank;
                return true;
            }
        } else { //bicie w przelocie
            if (getChessboard()->getSquareAt(this->getFile() + 1, this->getRank())->isOccupied()) { 
                if (getChessboard()->getSquareAt(this->getFile() + 1, this->getRank())->getOccupant()->canBeCapturedEnPassant()) {
                    if (getChessboard()->getSquareAt(this->getFile() + 1, this->getRank())->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank - 1*y_direction;
                        return true;
                    }
                }
            }
        }
    } else if (de_file == this->getFile() - 1 && de_rank == this->getRank() + 1*y_direction) { 
        if (getChessboard()->getSquareAt(de_file, de_rank)->isOccupied()) { //podstawowe bicie
            if (getChessboard()->getSquareAt(de_file, de_rank)->getOccupant()->getColor() != this->getColor()) {
                capture_file = de_file;
                capture_rank = de_rank;
                return true;
            }
        } else { //bicie w przelocie
            if (getChessboard()->getSquareAt(this->getFile() - 1, this->getRank())->isOccupied()) {
                if (getChessboard()->getSquareAt(this->getFile() - 1, this->getRank())->getOccupant()->canBeCapturedEnPassant()) {
                    if (getChessboard()->getSquareAt(this->getFile() - 1, this->getRank())->getOccupant()->getColor() != this->getColor()) {
                        capture_file = de_file;
                        capture_rank = de_rank - 1*y_direction;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

