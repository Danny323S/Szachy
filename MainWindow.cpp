#include "MainWindow.h"

MainWindow::MainWindow() : game() {
    main_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Chess");
    main_window.setFramerateLimit(60);

    chessboard_sprite = new ChessboardSprite(game.getChessboard());

    pressed_file_1 = -1;
    pressed_rank_1 = -1;
    pressed_file_2 = -1;
    pressed_rank_2 = -1;
}

void MainWindow::resizeMainWindow(sf::Vector2u new_size) {
    main_window.setSize(sf::Vector2u(new_size.x,new_size.x));
}

void MainWindow::render() { 
    main_window.clear(sf::Color(255,255,255));

    //rysowanie szachownicy
    for (unsigned int i = 0; i < chessboard_sprite->getSquares()->size(); i++) {
        main_window.draw(chessboard_sprite->getSquares()->at(i));
    }

    //rysowanie pionków
    for (unsigned int i = 0; i < chessboard_sprite->getPiecesSprites()->size(); i++) {
        main_window.draw(*chessboard_sprite->getPiecesSprites()->at(i).getSprite());
    }

    main_window.display();
}

void MainWindow::run() {

    while (main_window.isOpen())
    {
        sf::Event event;
        while (main_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                main_window.close();
            } else if(event.type == sf::Event::Resized) {
                resizeMainWindow(sf::Vector2u(event.size.width, event.size.height));
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "mouse pressed\n";
                    if (pressed_file_1 == -1) {
                        pressed_file_1 = event.mouseButton.x/(main_window.getSize().x/8);
                        pressed_rank_1 = -(event.mouseButton.y/(main_window.getSize().y/8)-7);
                        std::cout << "1 pressed square: " << pressed_file_1 << ", " << pressed_rank_1 << "\n"; 
                    } else {
                        pressed_file_2 = event.mouseButton.x/(main_window.getSize().x/8);
                        pressed_rank_2 = -(event.mouseButton.y/(main_window.getSize().y/8)-7);
                        std::cout << "2 pressed square: " << pressed_file_2 << ", " << pressed_rank_2 << "\n"; 
                    }
                }
            }
        } 

        if (pressed_file_1 != -1 && pressed_file_2 != -1){
            game.run(pressed_file_1, pressed_rank_1, pressed_file_2, pressed_rank_2);
            
            pressed_file_1 = -1;
            pressed_rank_1 = -1;
            pressed_file_2 = -1;
            pressed_rank_2 = -1;
            chessboard_sprite->updateSpritesPositions();
        }

        render();
    }
}

