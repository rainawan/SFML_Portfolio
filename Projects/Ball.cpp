//
// Created by Raina Wan on 12/9/22.
//

#include "Ball.h"

Ball::Ball() {
    circle.setRadius(200.0);
    circle.setFillColor(sf::Color::Green);
}

void Ball::eventHandler(sf::RenderWindow &window, sf::Event event) {
    while(window.isOpen()) {
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
