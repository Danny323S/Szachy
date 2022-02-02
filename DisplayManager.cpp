#include "DisplayManager.h"

DisplayManager::DisplayManager(Chessboard &chessboard) {
    this->chessboard = &chessboard;
}

void DisplayManager::printDivider() {
    std::cout << "-------------------------------------------------------------------------\n";
}
    
void DisplayManager::printOddFile() {
    std::cout << "|        |++++++++|        |++++++++|        |++++++++|        |++++++++|\n";
}

void DisplayManager::printEvenFile() {
    std::cout << "|++++++++|        |++++++++|        |++++++++|        |++++++++|        |\n";
}

void DisplayManager::printPiece(int x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,14);

    if (chessboard->getSquareAt(x,y)->isOccupied() == false) {
        SetConsoleTextAttribute(h,7);
        if(x%2 == 1 && y%2 == 0) {
            std::cout << "  ";
        } else if(x%2 == 1 && y%2 == 1) {
            std::cout << "++";
        } else if(x%2 == 0 && y%2 == 0) {
            std::cout << "++";
        } else if(x%2 == 0 && y%2 == 1) {
            std::cout << "  ";
        }    
    } else if (chessboard->getSquareAt(x,y)->getOccupant()->getType() == Type::TKing) {
        if (chessboard->getSquareAt(x,y)->getOccupant()->getColor() == Color::black) {
            std::cout << "Kb";
        } else {
            std::cout << "Kw";
        }
    } else if (chessboard->getSquareAt(x,y)->getOccupant()->getType() == Type::TPawn) {
        if (chessboard->getSquareAt(x,y)->getOccupant()->getColor() == Color::black) {
            std::cout << "Pb";
        } else {
            std::cout << "Pw";
        }
    } else if (chessboard->getSquareAt(x,y)->getOccupant()->getType() == Type::TQueen) {
        if (chessboard->getSquareAt(x,y)->getOccupant()->getColor() == Color::black) {
            std::cout << "Qb";
        } else {
            std::cout << "Qw";
        }
    } else if (chessboard->getSquareAt(x,y)->getOccupant()->getType() == Type::TRook) {
        if (chessboard->getSquareAt(x,y)->getOccupant()->getColor() == Color::black) {
            std::cout << "Rb";
        } else {
            std::cout << "Rw";
        }
    } else if (chessboard->getSquareAt(x,y)->getOccupant()->getType() == Type::TBishop) {
        if (chessboard->getSquareAt(x,y)->getOccupant()->getColor() == Color::black) {
            std::cout << "Bb";
        } else {
            std::cout << "Bw";
        }
    }  else if (chessboard->getSquareAt(x,y)->getOccupant()->getType() == Type::TKnight) {
        if (chessboard->getSquareAt(x,y)->getOccupant()->getColor() == Color::black) {
            std::cout << "Nb";
        } else {
            std::cout << "Nw";
        }
    }
    SetConsoleTextAttribute(h,7);
}

void DisplayManager::printSquare(int x, int y) {
    if(x%2 == 1 && y%2 == 0) {
        std::cout << "   ";
        printPiece(x, y); 
        std::cout << "   ";
    } else if(x%2 == 1 && y%2 == 1) {
        std::cout << "+++";
        printPiece(x, y); 
        std::cout << "+++";
    } else if(x%2 == 0 && y%2 == 0) {
        std::cout << "+++";
        printPiece(x, y); 
        std::cout << "+++";
    } else if(x%2 == 0 && y%2 == 1) {
        std::cout << "   ";
        printPiece(x, y); 
        std::cout << "   ";
    }
}

void DisplayManager::render() {
    printDivider();
    for (int y = 7; y >= 0; y--) {
        if (y%2 == 0) { 
            printEvenFile();
            for (int x = 0; x <= 7; x++) {
                std::cout << "|";
                printSquare(x, y);
            }  
            std::cout << "| [" << y << "]\n";
            printEvenFile();
            printDivider();
        } else {
            printOddFile();
            for (int x = 0; x <= 7; x++) {
                std::cout << "|";
                printSquare(x, y);
            }  
            std::cout << "| [" << y << "]\n";
            printOddFile();
            printDivider();
        }
    }
    std::cout << "   [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]    \n";
    
}