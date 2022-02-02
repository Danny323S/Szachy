#include "Player.h"

Piece* Player::getSelectedPiece() {
    return selected_piece;
}

Player::Player(Color color, Chessboard &chessboard) {
    // z konsoli pobierana jest nazwa użytkownika, i przypisywana jest graczowi
    // przypisywany jest wektor bierek gracza
    // przypisywany jest wskaźnik na króla
    this->chessboard = &chessboard;
    this->color = color;
    this->selected_piece = NULL; 
}

void Player::selectPiece(int file, int rank) {
    //do klasy ChessBoard wysyłane jest zapytanie czy pionek na polu (rank, file)
    //może zostać wybrany przez gracza
    //jeżeli na wskazanym polu znajduje się pionek i jest on koloru gracza
    //bierka jest wybierana.
    // board->getSquareAt(rank, file)

    if(chessboard->getSquareAt(file, rank)->isOccupied()) {
        if (chessboard->getSquareAt(file, rank)->getOccupant()->getColor() == this->color)
            selected_piece = chessboard->getSquareAt(file, rank)->getOccupant();
    }    
}

//funkcja zwraca wartość true jezeli pionek został poruszony
//jeżeli nie zwraca false
bool Player::movePiece(int file, int rank) {
    // Piece *piece_to_capture = nullptr;
    //poruszana jest wybrana przez gracza bierka, (selected_piece)
    //tak więc należy najpierw sprawdzić czy jakikolwiek pionek jest wybrany
    // selected_piece -> moveAt Square(rank, file),
    //Na podstawie, schematu ruchów pionka oraz sytuacji na SDzachownicy oceniana jest możliwość 
    //Wykonania danego ruchu i odbywa się on bądź nie
    //Sprawdzenie czy pionek może poruszyć się na dane pole 
    
    if(selected_piece->checkMove(file, rank)) {
        //Zmiana ustawienia na szachwonicy
        std::cout << "Przesuwanie pionka. \n";
        std::cout << "Selected piece (file: " << selected_piece->getFile() << ", rank: ";
        std::cout << selected_piece->getRank() << ")" << std::endl;

//###########################################################################################################
        //ustawienie pola na którym poprzednio znajdował się pionek na puste
        chessboard->getSquareAt(selected_piece->getFile(), selected_piece->getRank())->setOccupant(nullptr);

        //jeżeli docelowe pole jest okupowane -> zbicie znajdującego się na nim pionka
        if (chessboard->getSquareAt(file, rank)->isOccupied()){
            chessboard->capture(file, rank);
        }

        //umieszczenie poruszanego pionka na docelowym polu 
        chessboard->getSquareAt(file, rank)->setOccupant(selected_piece);
        selected_piece = nullptr;

//###########################################################################################################

        return true;
    } else {
        std::cout << "Pozycja nie zgodna ze schematem ruchow pionka. \n";
        selected_piece = nullptr;
        return false;
    }
}