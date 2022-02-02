#ifndef SQUARE_H
#define SQUARE_H
#include "Piece.h"

class Piece;

class Square {
private:
    int file;
    int rank;
    Piece *occupant;

public:
    Square() = default;
    Square(int file, int rank);

    int getFile();
    int getRank();

    bool isOccupied();
    void setOccupant(Piece *occupant);
    Piece* getOccupant();
};

#endif