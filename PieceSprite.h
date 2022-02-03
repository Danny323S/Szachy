#ifndef PIECESPRITE_H
#define PIECESPRITE_H
#include <SFML/Graphics.hpp>
#include "Piece.h"

class PieceSprite {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Sprite sprite;

    Piece *piece;

public:
    PieceSprite(Piece *piece_ptr);
    void setSpritePosition(sf::Vector2f position);
    void setSpritePiece(Piece *piece_ptr);
    Piece* getSpritePiece();
    sf::Sprite *getSprite();

};

#endif