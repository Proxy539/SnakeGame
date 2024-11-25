#ifndef BORDER_HPP
#define BORDER_HPP

#include <SFML/Graphics.hpp>

class Border {
    public:
        Border(double width, double height, double x, double y);
        ~Border();
        sf::RectangleShape getShape();
    
    private:
        sf::RectangleShape borderShape;
        double width;
        double height;
        double x;
        double y;
};       

#endif