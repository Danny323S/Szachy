#include "Square.h"

Square::Square(int file, int rank) {
    this->file = file;
    this->rank = rank;
    occupant = nullptr;
}

int Square::getRank() {
    return this->rank;
}

int Square::getFile() {
    return this->file;
}

bool Square::isOccupied() {
    if (occupant == nullptr) {
        return false;
    } else {
        return true;
    }
}

void Square::setOccupant(Piece* occupant) {
    if (occupant == nullptr) {
        this->occupant = occupant;
    } else {
        this->occupant = occupant;
        occupant->setPosition(this->file, this->rank);
    }
}

Piece* Square::getOccupant () {
    return this->occupant;
}