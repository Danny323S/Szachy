#include "Chessboard.h" 

Chessboard::Chessboard() {
    //utworzenie 
    for (int x = 0; x < DIMENSION; x++) {
        for (int y = 0; y < DIMENSION; y++) {
            chessboard[x][y] = Square(x, y);
        }
    }

//BLACK SET   
    chessboard[0][7].setOccupant(new Rook(black, this));
    chessboard[1][7].setOccupant(new Knight(black, this));
    chessboard[2][7].setOccupant(new Bishop(black, this));
    chessboard[3][7].setOccupant(new Queen(black, this));
    chessboard[4][7].setOccupant(new King(black, this));
    chessboard[5][7].setOccupant(new Bishop(black, this));
    chessboard[6][7].setOccupant(new Knight(black, this));
    chessboard[7][7].setOccupant(new Rook(black, this));

    chessboard[0][6].setOccupant(new Pawn(black, this));
    chessboard[1][6].setOccupant(new Pawn(black, this));
    chessboard[2][6].setOccupant(new Pawn(black, this));
    chessboard[3][6].setOccupant(new Pawn(black, this));
    chessboard[4][6].setOccupant(new Pawn(black, this));
    chessboard[5][6].setOccupant(new Pawn(black, this));
    chessboard[6][6].setOccupant(new Pawn(black, this));
    chessboard[7][6].setOccupant(new Pawn(black, this));

//WHITE SET
    chessboard[0][0].setOccupant(new Rook(white, this));
    chessboard[1][0].setOccupant(new Knight(white, this));
    chessboard[2][0].setOccupant(new Bishop(white, this));
    chessboard[3][0].setOccupant(new Queen(white, this));
    chessboard[4][0].setOccupant(new King(white, this));
    chessboard[5][0].setOccupant(new Bishop(white, this));
    chessboard[6][0].setOccupant(new Knight(white, this));
    chessboard[7][0].setOccupant(new Rook(white, this));

    chessboard[0][1].setOccupant(new Pawn(white, this));
    chessboard[1][1].setOccupant(new Pawn(white, this));
    chessboard[2][1].setOccupant(new Pawn(white, this));
    chessboard[3][1].setOccupant(new Pawn(white, this));
    chessboard[4][1].setOccupant(new Pawn(white, this));
    chessboard[5][1].setOccupant(new Pawn(white, this));
    chessboard[6][1].setOccupant(new Pawn(white, this));
    chessboard[7][1].setOccupant(new Pawn(white, this));
}

Square* Chessboard::getSquareAt(int file , int rank) {
    // if (((0 <= file) && (file <= 7)) && ((0 <= rank) && (rank <= 7)) == false) {
    //     return nullptr;
    // }

    return &chessboard[file][rank];
}


bool Chessboard::isRankClear(int rakn, int from_file, int to_file) {
    int from = 0, to = 0;

    if (to_file >= from_file) {
        to = to_file;
        from = from_file;
    } else {
        to = from_file;
        from = to_file;
    }

    for (int i = from; i <= to; i++) {
        if(this->getSquareAt(i, rakn)->isOccupied())
            return false;
    } 

    return true;
}

bool Chessboard::isFileClear(int file, int from_rank, int to_rank) {
    int from = 0, to = 0;

    if (to_rank >= from_rank) {
        to = to_rank;
        from = from_rank;
    } else {
        to = from_rank;
        from = to_rank;
    }

    for (int i = from; i <= to; i++) {
        if(this->getSquareAt(file, i)->isOccupied())
            return false;
    } 

    return true;
}

bool Chessboard::isDiagonalClear(int from_file, int from_rank, int to_file, int to_rank) {
    int from_f = 0, from_r = 0, /*to_f = 0,*/ to_r = 0;

    if (from_file <= to_file) {
        from_f = from_file;
        // to_f = to_file; 
        from_r = from_rank;
        to_r = to_rank;
    } else {
        from_f = to_file;
        // to_f = from_file; 
        from_r = to_rank;
        to_r = from_rank;        
    }

    if (from_r <= to_r) {
        for (int i = 0; i <= to_r - from_r; i++) {
            if(this->getSquareAt(from_f + i, from_r + i)->isOccupied())
                return false;
        }
    } else {
        for (int i = 0; i <= from_r - to_r; i++) {
            if(this->getSquareAt(from_f + i, from_r - i)->isOccupied())
                return false;
        }
    }

    return true;
}

void Chessboard::capture(int file, int rank) {
    this->getSquareAt(file, rank)->getOccupant()->deactivate();
    delete this->getSquareAt(file, rank)->getOccupant();
    this->getSquareAt(file, rank)->setOccupant(nullptr);
}

void Chessboard::castling(Piece *piece_to_move, int de_file, int de_rank) {
    if (!piece_to_move->wasItMoved()) {
        if(piece_to_move->getRank() == 0 && piece_to_move->getFile() == 4) {
            if (de_file == 6 && de_rank == 0) {
                move(getSquareAt(7,0)->getOccupant() , 5, 0);
            } else if (de_file == 2 && de_rank == 0) {
                move(getSquareAt(0,0)->getOccupant(), 3, 0);
            }
        } else if (piece_to_move->getRank() == 7 && piece_to_move->getFile() == 4) {
            if (de_file == 6 && de_rank == 7) {
                move(getSquareAt(7,7)->getOccupant() , 5, 7);
            } else if (de_file == 2 && de_rank == 7) {
                move(getSquareAt(0,7)->getOccupant(), 3, 7);
            }
        }
    }
}

void Chessboard::move(Piece *piece_to_move, int de_file, int de_rank) {
    getSquareAt(piece_to_move->getFile(), piece_to_move->getRank())->setOccupant(nullptr);
    getSquareAt(de_file, de_rank)->setOccupant(piece_to_move);
    piece_to_move->hasMoved();
}

bool Chessboard::checkPromotion() {
    int piece_to_promote_file = -1, piece_to_promote_rank = -1;

    for (int file = 0; file < 8; file++) {
        if (dynamic_cast<Pawn*>(getSquareAt(file, 7)->getOccupant())) {
            std::cout << "Promocja bialego Piona\n";
            return true;
        } else if (dynamic_cast<Pawn*>(getSquareAt(file, 0)->getOccupant())) {
            std::cout << "Promocja czarnego Piona\n";
            return true;
        }
    }

    return false;
}

void Chessboard::update(Piece *piece_to_move, int de_file, int de_rank, Piece *piece_to_capture) {
    if (piece_to_capture != nullptr){
        capture(piece_to_capture->getFile(), piece_to_capture->getRank());
    }
    castling(piece_to_move, de_file, de_rank);
    move(piece_to_move, de_file, de_rank);
    // promote();
}

