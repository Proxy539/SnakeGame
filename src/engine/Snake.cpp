#include "Snake.hpp"

Snake::Snake(double width, double height, double x, double y): width(width), height(height), x(x), y(y) {
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