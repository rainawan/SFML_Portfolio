//
// Created by Raina Wan on 12/9/22.
//

#include "Ball.h"

Ball::Ball() {
    circle.setRadius(200.0);
    circle.setFillColor(sf::Color::Red);
}

void Ball::eventHandler(sf::RenderWindow &window, sf::Event event) {
    window.setSize({2600,1550});
    while(window.isOpen() && gp::game_playing == BALL) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                gp::game_playing = BOUNCING_BALL;
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Blue);
        window.draw(circle);
        window.display();
    }
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(circle);
}
