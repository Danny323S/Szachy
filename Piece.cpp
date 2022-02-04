#include "Piece.h"

Piece::Piece(Color color, Chessboard *chessboard) {
    this->color = color;
    this->is_active = true;
    this->type = Type::TPiece;
    this->chessboard = chessboard;
}

Piece::~Piece() {
    std::cout << "Piece destructed\n";
}

Color Piece::getColor() {
    return this->color;
}

Type Piece::getType() {
    return this->type;
}

int Piece::getFile() {
    return this->file;
}

int Piece::getRank() {
    return this->rank;
}

Chessboard* Piece::getChessboard() {
    return this->chessboard;
}

void Piece::setPosition(int file, int rank) {
    this->file = file;
    this->rank = rank;
}

bool Piece::canBeCapturedEnPassant() {
    return false;
}

bool Piece::wasItMoved() {
    return true;
}

void Piece::hasMoved() {
    std::cout << "hasMoved() dla klasy Piece\n";
}

void Piece::deactivate() {
    this->is_active = false;
}

bool Piece::isActive() {
    return this->is_active;
}
