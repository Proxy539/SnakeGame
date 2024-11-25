#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>

enum SnakeDirection {
    UP, DOWN, LEFT, RIGHT
};

class Snake {
    public: 
        Snake(double width, double height, double x, double y);
        ~Snake();
        sf::RectangleShape getSnakeShape();
        void move();
        void setDirection(SnakeDirection direction);

    private:
        sf::RectangleShape snakeShape;
        double x;
        double y;
        double width;
        double height;
        SnakeDirection direction;

};

#endif