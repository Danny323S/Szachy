#include "PieceSprite.h"

PieceSprite::PieceSprite(Piece *piece_ptr) {
    this->piece = piece_ptr;
    main_window_size = sf::Vector2f(1000.0f, 1000.0f);
}

void PieceSprite::setSpritePiece(Piece *piece_ptr) {
    this->piece = piece_ptr;
}

Piece* PieceSprite::getSpritePiece() {
    return this->piece;
}

void PieceSprite::updatePosition() {
    position = sf::Vector2f(this->piece->getFile()*(main_window_size.x/8), (7 - this->piece->getRank())*(main_window_size.y/8));
    this->sprite.setPosition(position);
}

sf::Sprite *PieceSprite::getSprite() {
    return &sprite;
}

// void PieceSprite::updatePosition() {
//     position = 
//     // sprite.setPosition(sf::Vector2f(this->piece->getFile()*(main_window_size.x/8), (7 - this->piece->getRank())*(main_window_size.y/8)));
// }


// PieceSprite