//
// Created by Raina Wan on 12/8/22.
//

#include "BouncingBall.h"

BouncingBall::BouncingBall() {
    circle.setRadius(50.0);
    circle.setFillColor(sf::Color::Blue);
}

void BouncingBall::eventHandler(sf::RenderWindow &window, sf::Event event) {
    window.setSize({2600,1550});
    window.setFramerateLimit(240);

    sf::CircleShape shape;
    shape.setRadius(80.0);
    shape.setFillColor(sf::Color::Blue);
    float xstep = 5;
    float ystep = 5;

    while(window.isOpen() && gp::game_playing == BOUNCING_BALL) {
        sf::Event event;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            gp::game_playing = BALL;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            gp::game_playing = PONG;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        if (shape.getPosition().x > window.getSize().x - shape.getRadius() * 2) //diameter of bouncing_ball
            xstep = -5;
        else if (shape.getPosition().x < 0)
            xstep = 5;
        if (shape.getPosition().y > window.getSize().y - shape.getRadius() * 2)
            ystep = -5;
        else if (shape.getPosition().y < 0)
            ystep = 5;

        shape.move(xstep,ystep);
        window.clear(sf::Color(173, 216, 230));
        window.draw(shape);
        window.display();
    }
}

void BouncingBall::update() {

}

void BouncingBall::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(circle);
}