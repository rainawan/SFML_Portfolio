//
// Created by Raina Wan on 12/13/22.
//

#include "Square.h"

Square::Square() {
    square.setSize({100,100});
    square.setFillColor(sf::Color::Transparent);
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(thickness);

    bomb.sf::RectangleShape::setScale({.15,.15});
    miss.sf::RectangleShape::setScale({.15,.15});
}

void Square::setPosition(const sf::Vector2f &position) {
    square.setPosition(position);
}

void Square::setPosition(float x, float y) {
    setPosition({x, y});
}

sf::Vector2f Square::getPosition() {
    return {square.getPosition().x, square.getPosition().y};
}

void Square::eventHandler(sf::RenderWindow &window, sf::Event event, states_enum state) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    miss.setPosition(square.getPosition().x - 10, square.getPosition().y - 4);
    bomb.setPosition(square.getPosition().x - 15, square.getPosition().y);

    if (square.getGlobalBounds().contains(mpos)
        && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        enableState(state);
    }
}

sf::FloatRect Square::getGlobalBounds() const {
    return square.getGlobalBounds();
}

void Square::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(square);
    if(getState(HIT)) {
        target.draw(bomb);
    }
    if(getState(MISS)) {
        target.draw(miss);
    }
}