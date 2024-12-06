#ifndef POINT_HPP
#define POINT_HPP

#include <SFML/Graphics.hpp>

class Point {
    public:
        Point(double widht, double height);
        ~Point();
        sf::RectangleShape getPointShape();
        void setPosition(double x, double y);
    
    private:
        sf::RectangleShape pointShape;
        double x;
        double y;
        double width;
        double height;
};

#endif