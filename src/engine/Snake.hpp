#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>

class Snake {
    public: 
        Snake(double width, double height, double x, double y);
        ~Snake();
        sf::RectangleShape getSnakeShape();

    private:
        sf::RectangleShape snakeShape;
        double x;
        double y;
        double width;
        double height;

};

#endif