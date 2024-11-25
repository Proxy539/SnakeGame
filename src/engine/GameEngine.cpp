#include "GameEngine.hpp"

GameEngine::GameEngine(): 
    window(sf::VideoMode(800, 600), "Game Engine"),
    border(Border(500.f, 500.f, 50.f, 50.f)) {
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(800, 200)); 

}

GameEngine::~GameEngine() {
    //No dynaic memory here, but clean up if needed
}

void GameEngine::startGame() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameEngine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameEngine::update() {
    //Add game logic updates here
}

void GameEngine::render() {
    window.clear(sf::Color::Black);

    //Add drawing code here (draw objects)
    sf::RectangleShape borderShape = border.getShape();


    window.draw(borderShape);


    window.display();
}