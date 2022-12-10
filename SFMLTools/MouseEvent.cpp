//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_MOUSEEVENT_CPP
#define PORTFOLIO_MOUSEEVENT_CPP

#include "MouseEvent.h"

template<class T>
bool MouseEvent::isHovered(const T &Obj, const sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvent::isClicked(const T &Obj, const sf::RenderWindow &window) {
    return isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvent::isNotClicked(const T &Obj, const sf::RenderWindow &window) {
    return !isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif