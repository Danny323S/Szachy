#include <iostream>
#include "Game.h"

int main() {
Game game;

int file_b = 0, file_s = 0, rank_b = 0, rank_s = 0;

    while (true) {
        char pic[8];
        char pole[8];

        std::cout << "wybierz bierke: ";
        std::cin >> pic;
        std::cout << "input: " << pic << std::endl;
        std::cin.clear();

        std::cout << "wybierz pole: ";
        std::cin >> pole;
        std::cout << "input: " << pole << std::endl;
        std::cin.clear();

        file_b = (int)pic[0] - 48;
        rank_b = (int)pic[1] - 48;

        file_s = (int)pole[0] - 48;
        rank_s = (int)pole[1] - 48;

        std::cout << "(file_b, rank_b): (" << file_b << ", " << rank_b << ")";
        std::cout << "(file_s, rank_s): (" << file_s << ", " << rank_s << ")";

        game.run(file_b, rank_b, file_s, rank_s);
    }


    std::cout << "Zakonczenie dzialania programu\n";
    return 0;
}  