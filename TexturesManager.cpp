#include "TexturesManager.h"

TexturesManager::TexturesManager() {
    //Wczytanie wszystkich używanych tekstur
    if(!white_pwan_texture.loadFromFile("./src/textures/white_pawn.png")) {
        std::cout << "white_pawn texture load error\n";
    } else white_pwan_texture.setSmooth(true);

    if(!black_pwan_texture.loadFromFile("./src/textures/black_pawn.png")) {
        std::cout << "black_pawn texture load error\n";
    } else black_pwan_texture.setSmooth(true);
    
    if(!white_knight_texture.loadFromFile("./src/textures/white_knight.png")) {
        std::cout << "white_knight texture load error\n";
    } else white_knight_texture.setSmooth(true);

    if(!black_knight_texture.loadFromFile("./src/textures/black_knight.png")) {
        std::cout << "black_knight texture load error\n";
    } else black_knight_texture.setSmooth(true);

    if(!white_bishop_texture.loadFromFile("./src/textures/white_bishop.png")) {
        std::cout << "white_bishop texture load error\n";
    } else white_bishop_texture.setSmooth(true);

    if(!black_bishop_texture.loadFromFile("./src/textures/black_bishop.png")) {
        std::cout << "black_bishop texture load error\n";
    } else black_bishop_texture.setSmooth(true);

    if(!white_rook_texture.loadFromFile("./src/textures/white_rook.png")) {
        std::cout << "white_rook texture load error\n";
    } else white_rook_texture.setSmooth(true);

    if(!black_rook_texture.loadFromFile("./src/textures/black_rook.png")) {
        std::cout << "black_rook texture load error\n";
    } else black_rook_texture.setSmooth(true);

    if(!white_queen_texture.loadFromFile("./src/textures/white_queen.png")) {
        std::cout << "white_queen texture load error\n";
    } else white_queen_texture.setSmooth(true);

    if(!black_queen_texture.loadFromFile("./src/textures/black_queen.png")) {
        std::cout << "black_queen texture load error\n";
    } else black_queen_texture.setSmooth(true);

    if(!white_king_texture.loadFromFile("./src/textures/white_king.png")) {
        std::cout << "white_king texture load error\n";
    } else white_king_texture.setSmooth(true);

    if(!black_king_texture.loadFromFile("./src/textures/black_king.png")) {
        std::cout << "black_king texture load error\n";
    } else black_king_texture.setSmooth(true);
}

// TexturesManager::~TexturesManager()
// {
// }

sf::Texture *TexturesManager::getTexture(Piece *piece_ptr) {
    if (piece_ptr->getRank() == 6) {
        return &black_pwan_texture;
    } else if (piece_ptr->getRank() == 1) {
        return &white_pwan_texture;
    } else if (piece_ptr->getRank() == 7) {
        if (piece_ptr->getFile() == 0 || piece_ptr->getFile() == 7) {
            return &black_rook_texture;
        } else if (piece_ptr->getFile() == 1 || piece_ptr->getFile() == 6) {
            return &black_knight_texture;
        } else if (piece_ptr->getFile() == 2 || piece_ptr->getFile() == 5) {
            return &black_bishop_texture;
        } else if (piece_ptr->getFile() == 3) {
            return &black_queen_texture;
        } else if (piece_ptr->getFile() == 4) {
            return &black_king_texture;
        }
    } else if (piece_ptr->getRank() == 0) {
        if (piece_ptr->getFile() == 0 || piece_ptr->getFile() == 7) {
            return &white_rook_texture; 
        } else if (piece_ptr->getFile() == 1 || piece_ptr->getFile() == 6) {
            return &white_knight_texture;
        } else if (piece_ptr->getFile() == 2 || piece_ptr->getFile() == 5) {
            return &white_bishop_texture;
        } else if (piece_ptr->getFile() == 3) {
            return &white_queen_texture;
        } else if (piece_ptr->getFile() == 4) {
            return &white_king_texture;
        }
    }
    
    return &black_pwan_texture;
}
