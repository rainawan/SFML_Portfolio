//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_PADDLE_H
#define PORTFOLIO_PADDLE_H


#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape {
private:
    sf::Vector2f velocity = {1,1};
public:
    Paddle();
    void shiftUp(const sf::RenderWindow& window);
    void shiftDown(const sf::RenderWindow& window);
    void setVelocity(const sf::Vector2f& velocity);
};


#endif //PORTFOLIO_PADDLE_H
