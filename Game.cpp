#include "Game.h"

Game::Game() : board(), display_manager(board), w_player(white ,board), b_player(black ,board) {
    is_running = true;
    white_round = true;

    display_manager.render();
}

bool Game::run(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank) {
    turn(selected_piece_file, selected_piece_rank, destination_file, destination_rank);
    display_manager.render();
    return true;
}

void Game::turn(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank) {
    Player *actual_player;

    if(white_round) {
        actual_player = &w_player;
        std::cout << "Ruch Bialego\n";
    } else {
        actual_player = &b_player;
        std::cout << "Ruch Czarnego\n";
    }

    if (board.getSquareAt(selected_piece_file,selected_piece_rank)->isOccupied()) {
        if (actual_player->selectPiece(selected_piece_file, selected_piece_rank)) {
            if(actual_player->movePiece(destination_file, destination_rank)) {
                white_round = !white_round;
                std::cout << "Koniec tury";
            } else {
                std::cout << "Bierka nie może poruszyć się na dane pole";
            }
        } else {
            std::cout << "Na wybaranym polu nie ma bierki";
            std::cout << "Lub jest niewłaściwego koloru";
        }
    }

}

// void Game::turn(int selected_piece_file, int selected_piece_rank, int destination_file, int destination_rank) {
//     // Opis przebiegu tury
//     // Gracz którego jest tura musi wybrać pionek
//         // Stosowany jest komunikat do geracza aby wybrał swój pionek
//         // Gracz wybiera pionek
//         // Gracz może wybrać inny pionek lub poruszyć wybranym pionkiem
//     // Gracz porusza pionkiem 
//         // Stosowany jest komunikat aby gracz wybrał pole na, które chce się poruszyć
//         // Gracz wprowadza współrzędne pola lub chce wybrać inny pionek
//         // Jeżeli gracz wprowadzi współrzędne pola sprawdzane jest czy dany pionek może poruszyć się na to pole
//             // Sprawdzane jest czy pole pokrywa się ze schematem ruchu bierki 
//             // Czy na drodze nie stoi inny pionek i czy spełnione są inne warunki
//             // Jeżeli ruch jest możliwy pionek zmienia swoje położenie w innym wypadku
//             // ZWRACANY JEST KOMUNIKAT że pole jest nie osiągalne i można wprowadzić inne pole 

//     bool turn_end = false;


//     Player *actual_player;
//     char input[2];
//     int file = 0, rank = 0;



//     if(white_round) {
//         actual_player = &w_player;
//         std::cout << "Ruch Bialego\n";
//     } else {
//         actual_player = &b_player;
//         std::cout << "Ruch Czarnego\n";
//     }

//     while (!turn_end) {
//         if (actual_player->getSelectedPiece() == nullptr) {

//             std::cout << "wybierz bierke ";
//             std::cout << "(kolumna, rzad): \n";
//             std::cin >> input;
//             std::cout << "input: " << input << std::endl;
//             std::cin.clear();

//             file = (int)input[0] - 48;
//             rank = (int)input[1] - 48;

//             std::cout << board.getSquareAt(file, rank)->getOccupant()->getType();
//             std::cout << board.getSquareAt(file, rank)->getOccupant()->getColor() << std::endl;

//             actual_player->selectPiece(file, rank);

//             std::cout << "wybrana bierka: (" << file << ", " << rank << ")\n\n";
//         } else {
//             std::cout << "Gdzie poruszyc bierke? ";
//             std::cout << "(kolumna, rzad): \n";
//             std::cin >> input;
//             std::cin.clear();

//             file = (int)input[0] - 48;
//             rank = (int)input[1] - 48;

//             if(actual_player->movePiece(file, rank)){
//                 white_round = !white_round;
//                 turn_end = true;
//             }
//         }
//     }
// }

