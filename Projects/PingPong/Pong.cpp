//
// Created by Raina Wan on 12/9/22.
//

#include "Pong.h"

Pong::Pong() {
    paddleLeft.setFillColor(sf::Color::Blue);
    paddleLeft.setPosition(0,100);
    paddleRight.setFillColor(sf::Color::Blue);
    paddleRight.setPosition(770,100);
}

void Pong::eventHandler(sf::RenderWindow &window, sf::Event event) {
    window.setSize(sf::Vector2u(800,500));

    while(window.isOpen()) {

        sf::Event event;
        pong_ball.bounce(window, paddleLeft, paddleRight);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            paddleLeft.shiftUp(window);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            paddleLeft.shiftDown(window);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            paddleRight.shiftUp(window);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            paddleRight.shiftDown(window);
        }
        while(window.pollEvent(event)) {
            pong_ball.move(5, 0);
            if(event.type == sf::Event::Closed) {
                window.close(); //close window if user clicks red X
            }
        }
        std::move(paddleLeft);
        std::move(paddleRight);
        window.clear(sf::Color::Yellow);
        window.draw(paddleLeft);
        window.draw(paddleRight);
        window.draw(pong_ball);
        window.display();
    }
}

void Pong::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(paddleLeft);
    target.draw(paddleRight);
    target.draw(pong_ball);
}
