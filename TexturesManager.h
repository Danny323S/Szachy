#ifndef TEXTURESMANAGER_H
#define TEXTURESMANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

class TexturesManager
{
private:
    sf::Texture white_pwan_texture;
    sf::Texture white_knight_texture;
    sf::Texture white_bishop_texture;
    sf::Texture white_rook_texture;
    sf::Texture white_queen_texture;
    sf::Texture white_king_texture;

    sf::Texture black_pwan_texture;
    sf::Texture black_knight_texture;
    sf::Texture black_bishop_texture;
    sf::Texture black_rook_texture;
    sf::Texture black_queen_texture;
    sf::Texture black_king_texture;

public:
    TexturesManager(/* args */);
    // ~TexturesManager();

    sf::Texture *getTexture(Piece *piece_ptr);
};




#endif