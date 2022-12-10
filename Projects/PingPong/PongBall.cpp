//
// Created by Raina Wan on 12/9/22.
//

#include "PongBall.h"

PongBall::PongBall() {
    circle.setRadius(30.0);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(100,100);
}

void PongBall::bounce(const sf::RenderWindow& window, Paddle paddleLeft, Paddle paddleRight) {
    sf::FloatRect b = getGlobalBounds();
    circle.move(velocity);



    if(circle.getGlobalBounds().top + circle.getGlobalBounds().height >= window.getSize().y || circle.getGlobalBounds().top <= 0) {
        velocity.y = -velocity.y;
    }

    if (
            (circle.getGlobalBounds().left + circle.getGlobalBounds().width >= paddleRight.getGlobalBounds().left
             || circle.getGlobalBounds().left <= paddleLeft.getGlobalBounds().width)
            && ((circle.getPosition().y >= paddleLeft.getPosition().y) && (circle.getPosition().y <= (paddleLeft.getPosition().y + paddleLeft.getSize().y)))
            && ((circle.getPosition().y >= paddleRight.getPosition().y) && (circle.getPosition().y <= (paddleRight.getPosition().y + paddleRight.getSize().y)))
            )
        velocity.x = -velocity.x;
}

void PongBall::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}

void PongBall::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(circle);
}
