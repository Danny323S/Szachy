#include "ChessboardSprite.h"
#include "TexturesManager.h"

ChessboardSprite::ChessboardSprite(Chessboard *chessboard) {
    this->chessboard = chessboard;
   
    window_size = sf::Vector2u(1000, 1000);  
    textures_manager = TexturesManager();
    sf::Color color(62, 125, 65);

//utworzenie szachwnicy
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y%2 ==0) {
                if (x%2 == 0) {
                    squares.push_back(sf::RectangleShape(sf::Vector2f(window_size.x/8, window_size.y/8)));
                    squares.back().setFillColor(color);
                    squares.back().setPosition(window_size.x/8*x, window_size.x/8*y);
                }
            } else if (y%2 ==1) {
                if (x%2 == 1) {
                    squares.push_back(sf::RectangleShape(sf::Vector2f(window_size.x/8, window_size.y/8)));
                    squares.back().setFillColor(color);
                    squares.back().setPosition(window_size.x/8*x, window_size.x/8*y);
                }
            }
        }
    }

// utworzenie pionków 
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (chessboard->getSquareAt(x,y)->isOccupied() == true) {
                pieces_sprites.push_back(PieceSprite(chessboard->getSquareAt(x,y)->getOccupant()));
                pieces_sprites.back().getSprite()->setTexture(*textures_manager.getTexture(chessboard->getSquareAt(x,y)->getOccupant()));
                pieces_sprites.back().getSprite()->setPosition(sf::Vector2f(x*(window_size.x/8), (-1)*(y-7)*(window_size.y/8)));
            }
        }
    }    
}

void ChessboardSprite::resize(sf::Vector2u size) {
    window_size = size;

    for (unsigned int i = 0; i == squares.size(); i++) {
        squares[i].setSize(sf::Vector2f(window_size.x/8, window_size.y/8));
    }
}

std::vector<sf::RectangleShape> *ChessboardSprite::getSquares() {
    return &squares;
}

std::vector<PieceSprite> *ChessboardSprite::getPiecesSprites() {
    return &pieces_sprites;
}

void ChessboardSprite::updateSpritesPositions() {
    for (unsigned int i = 0; i < pieces_sprites.size(); i++) {
        pieces_sprites.at(i).updatePosition();
    }
}
