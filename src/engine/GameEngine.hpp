#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <SFML/Graphics.hpp>
#include "Border.hpp"
#include "Snake.hpp"
#include "Point.hpp"

class GameEngine {
    public: 
        GameEngine();
        ~GameEngine();
        void startGame();

    private: 
        Border border;
        Snake snake;
        Point point;
        sf::RenderWindow window;
        void processEvents();
        void update();
        void render();
        void showMenu();
        void processPoint();
        void checkBordersCollisions();
};

#endif