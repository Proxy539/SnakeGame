#include "Border.hpp"

Border::Border(double width, double height, double x, double y): width(width), height(height), x(x), y(y) {
    borderShape = sf::RectangleShape(sf::Vector2f(width, height));
    borderShape.setPosition(x, y);
    borderShape.setFillColor(sf::Color::Transparent);
    borderShape.setOutlineColor(sf::Color::White);
    borderShape.setOutlineThickness(5.f);
}

Border::~Border() {

}

sf::RectangleShape Border::getShape() {
    return borderShape;
}
