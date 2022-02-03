#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "ChessboardSprite.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000


class MainWindow {
private:
    sf::RenderWindow main_window;
    ChessboardSprite *chessboard_sprite;
    Game game;

    void resizeMainWindow(sf::Vector2u new_size);
    void render();


    bool quit;
    sf::CircleShape shape;

    int pressed_file_1;
    int pressed_rank_1;
    int pressed_file_2;
    int pressed_rank_2;
public:
    MainWindow();
    void run();
};

#endif