#include "Point.hpp"

Point::Point(double width, double height): width(width), height(height) {
    pointShape = sf::RectangleShape(sf::Vector2f(width, height));
    pointShape.setFillColor(sf::Color::Red);
    pointShape.setOutlineColor(sf::Color::White);
    pointShape.setOutlineThickness(1.f);
}

Point::~Point() {}

sf::RectangleShape Point::getPointShape() {
    return pointShape;
}

void Point::setPosition(double x, double y) {
    pointShape.setPosition(x, y);
}