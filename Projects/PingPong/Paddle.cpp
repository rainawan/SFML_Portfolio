//
// Created by Raina Wan on 12/9/22.
//

#include "Paddle.h"

Paddle::Paddle() : sf::RectangleShape() {
    setSize({40,200});
}

void Paddle::shiftUp(const sf::RenderWindow& window) {
    if (getPosition().y >= 0)
        move({0,-10});
}

void Paddle::shiftDown(const sf::RenderWindow& window) {
    if(getPosition().y + getSize().y <= window.getSize().y)
        move({0,10});
}

void Paddle::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}