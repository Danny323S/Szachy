#include "PieceSprite.h"

PieceSprite::PieceSprite(Piece *piece_ptr) {
    this->piece = piece_ptr;
}

void PieceSprite::setSpritePiece(Piece *piece_ptr) {
    this->piece = piece_ptr;
}

Piece* PieceSprite::getSpritePiece() {
    return this->piece;
}

void PieceSprite::setSpritePosition(sf::Vector2f position) {
    this->sprite.setPosition(position);
}

sf::Sprite *PieceSprite::getSprite() {
    return &sprite;
}


// PieceSprite