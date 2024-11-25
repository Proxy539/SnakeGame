#include "Snake.hpp"

Snake::Snake(double width, double height, double x, double y): width(width), height(height), x(x), y(y), direction(UP) {
    snakeShape = sf::RectangleShape(sf::Vector2f(width, height));
    snakeShape.setPosition(sf::Vector2f(x, y));
    snakeShape.setFillColor(sf::Color::Green);
    snakeShape.setOutlineColor(sf::Color::White);
    snakeShape.setOutlineThickness(1.f);
}

Snake::~Snake() {

}

sf::RectangleShape Snake::getSnakeShape() {
    return snakeShape;
}

void Snake::setDirection(SnakeDirection dir) {
    direction = dir;
}

void Snake::move() {
    
    switch(direction) {
        case UP:  
            y -= 30.f;
            break;
        case DOWN:
            y += 30.f;
            break;
        case LEFT:
            x -= 30.f;
            break;
        case RIGHT:
            x += 30.f;
            break;
    }


    snakeShape.setPosition(sf::Vector2f(x, y));
}