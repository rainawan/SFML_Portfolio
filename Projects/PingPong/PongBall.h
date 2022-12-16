//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_PONGBALL_H
#define PORTFOLIO_PONGBALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"

class PongBall : public sf::CircleShape {
private:
    sf::CircleShape circle;
    sf::Vector2f velocity = {8,8};
public:
    PongBall();
    void bounce(const sf::RenderWindow& window, Paddle paddleLeft, Paddle paddleRight);
    void setVelocity(const sf::Vector2f& velocity);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_PONGBALL_H
