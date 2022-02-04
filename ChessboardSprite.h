#ifndef CHESSBOARDSPRITE_H
#define CHESSBOARDSPRITE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Chessboard.h"
#include "PieceSprite.h"
#include "TexturesManager.h"

class ChessboardSprite {
private:
    sf::Vector2u window_size;
    Chessboard *chessboard;
    std::vector<sf::RectangleShape> squares;
    std::vector<PieceSprite> pieces_sprites;
    TexturesManager textures_manager;

public:
    ChessboardSprite(Chessboard *chessboard);
    void resize(sf::Vector2u window_size); 
    void updateSpritesPositions();

    std::vector<sf::RectangleShape> *getSquares();
    std::vector<PieceSprite> *getPiecesSprites();
};

#endif