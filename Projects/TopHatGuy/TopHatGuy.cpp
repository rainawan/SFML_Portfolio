//
// Created by Raina Wan on 12/9/22.
//

#include "TopHatGuy.h"

TopHatGuy::TopHatGuy() {
    top.setSize({50,80});
    rim.setSize({90,20});
    circle.setRadius(40.0);

    top.setFillColor(sf::Color::Black);
    rim.setFillColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Yellow);
}

void TopHatGuy::eventHandler(sf::RenderWindow &window, sf::Event event) {
    window.setSize({2600,1550});
    TopHatGuy guy;
    guy.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while(window.isOpen() && gp::game_playing == TOP_HAT_GUY) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            gp::game_playing = PONG;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            gp::game_playing = CARD;
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
        }
        window.clear(sf::Color(255,140,0));
        window.draw(guy);
        window.display();
    }
}

void TopHatGuy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(circle);
    target.draw(top);
    target.draw(rim);
}

void TopHatGuy::setPosition(const sf::Vector2f &position) {
    top.setPosition(position);
    rim.setPosition({top.getPosition().x - 20,top.getPosition().y + top.getGlobalBounds().height});
    circle.setPosition({rim.getPosition().x + rim.getGlobalBounds().width/2 - circle.getRadius(), rim.getPosition().y + rim.getGlobalBounds().height - 10});
}

void TopHatGuy::setPosition(float x, float y) {
    top.setPosition({x, y});
    rim.setPosition({top.getPosition().x - 20,top.getPosition().y + top.getGlobalBounds().height});
    circle.setPosition({rim.getPosition().x + rim.getGlobalBounds().width/2 - circle.getRadius(), rim.getPosition().y + rim.getGlobalBounds().height - 10});
}
