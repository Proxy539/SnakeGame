#include "GameEngine.hpp"
#include <iostream>
#include <stdlib.h>

GameEngine::GameEngine(): 
    window(sf::VideoMode(800, 600), "Game Engine"),
    border(Border(500.f, 500.f, 50.f, 50.f)),
    snake(Snake(30.f, 30.f, 300.f, 300.f)),
    point(Point(30.f, 30.f)) {
    window.setPosition(sf::Vector2i(800, 200)); 

}

GameEngine::~GameEngine() {
    //No dynaic memory here, but clean up if needed
}

void GameEngine::startGame() {
    showMenu();
    processPoint();
    while (window.isOpen()) {
        processEvents();
        checkBordersCollisions();
        snake.move();
        update();
        render();
    }
}

void GameEngine::processEvents() {
    sf::Event event;
    window.setFramerateLimit(5);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                snake.setDirection(UP);
            } else if (event.key.code == sf::Keyboard::Down) {
                snake.setDirection(DOWN);
            } else if (event.key.code == sf::Keyboard::Left) {
                snake.setDirection(LEFT);
            } else if (event.key.code == sf::Keyboard::Right) {
                snake.setDirection(RIGHT);
            }
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
    sf::RectangleShape snakeSnape = snake.getSnakeShape();
    sf::RectangleShape pointShape = point.getPointShape();

    window.draw(borderShape);
    window.draw(snakeSnape);
    window.draw(pointShape);

    window.display();
}

void GameEngine::showMenu() {
    sf::Font font;

    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    sf::Text snakeGameText;
    snakeGameText.setFont(font);
    snakeGameText.setString("Snake game menu");
    snakeGameText.setCharacterSize(50);
    snakeGameText.setFillColor(sf::Color::White);
    snakeGameText.setPosition(200, 50);

    sf::Text startGameText;
    startGameText.setFont(font);
    startGameText.setString("Start the game");
    startGameText.setCharacterSize(30);
    startGameText.setFillColor(sf::Color::Green);
    startGameText.setPosition(250, 200);

    sf::Text exitGameText;
    exitGameText.setFont(font);
    exitGameText.setString("Exit the game");
    exitGameText.setCharacterSize(30);
    exitGameText.setFillColor(sf::Color::Red);
    exitGameText.setPosition(250, 300);

    sf::RectangleShape snakeShape = sf::RectangleShape(sf::Vector2f(20, 20));
    snakeShape.setPosition(200, 210);
    snakeShape.setFillColor(sf::Color::Green);
    snakeShape.setOutlineColor(sf::Color::White);
    snakeShape.setOutlineThickness(1.f);

    window.clear(sf::Color::Black);

    window.draw(snakeGameText);
    window.draw(startGameText);
    window.draw(exitGameText);
    window.draw(snakeShape);

    window.setFramerateLimit(60);
    window.display();

    sf::Text menuOptions[2] = { startGameText, exitGameText};
    int currentOption = 0;

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    std::cout << "Up button pressed" << std::endl;
                    if (currentOption == 1) {
                        currentOption--;
                        snakeShape.setPosition(200, 210);
                    }
                } else if (event.key.code == sf::Keyboard::Down) {                
                    std::cout << "Down button pressed" << std::endl;
                    if (currentOption == 0) {
                        currentOption++;
                        snakeShape.setPosition(200, 310);
                    }
                } else if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    if (currentOption == 1) {
                        window.close();
                    } else if (currentOption == 0) {
                        return;
                    }
                }
            }

            window.clear();

            window.draw(snakeGameText);
            window.draw(startGameText);
            window.draw(exitGameText);
            window.draw(snakeShape);

            window.display();
        }
    }
}

void GameEngine::processPoint() {
    float borderX = border.getShape().getPosition().x;
    int borderWidth = (int) border.getShape().getSize().x;
    float borderY = border.getShape().getPosition().y;
    int borderHeight = (int) border.getShape().getSize().y;

    float pointx = borderX + (rand() % borderWidth);
    float pointy = borderY + (rand() % borderHeight);

    point.setPosition(pointx, pointy);
}

void GameEngine::checkBordersCollisions() {
    
    float snakeX = snake.getSnakeShape().getPosition().x;
    float snakeWidth = snake.getSnakeShape().getSize().x;
    float snakey = snake.getSnakeShape().getPosition().y;
    float snakeHeight = snake.getSnakeShape().getSize().y;

    float borderx = border.getShape().getPosition().x;
    float borderWidth = border.getShape().getSize().x;
    float bordery = border.getShape().getPosition().y;
    float borderHeight = border.getShape().getSize().y;

    if (snakeX + snakeWidth > border.getShape().getPosition().x + border.getShape().getSize().x) {
        std::cout << "Snake colide with right border. Exit the game " << std::endl;
        window.close();
        exit(0);
    } 

    if (snakeX < border.getShape().getPosition().x) {
        std::cout << "Snake colide with left border. Exit the game" << std::endl;
        window.close();
        exit(0);
    }

    if (snakey + snakeHeight > border.getShape().getPosition().y + border.getShape().getSize().y) {
        std::cout << "Snake collide with buttom border. Exit the game" << std::endl;
        window.close();
        exit(0);
    }

    if (snakey < border.getShape().getPosition().y) {
        std::cout << "Snake collide with top border. Exit the game" << std::endl;
        window.close();
        exit(0);
    }

}