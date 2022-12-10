//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_MOUSEEVENT_H
#define PORTFOLIO_MOUSEEVENT_H

#include <SFML/Graphics.hpp>

class MouseEvent {
public:
    template<class T>
    static bool isHovered(const T& Obj, const sf::RenderWindow& window);
    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);
    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow& window);
};

#include "MouseEvent.cpp"
#endif //PORTFOLIO_MOUSEEVENT_H
