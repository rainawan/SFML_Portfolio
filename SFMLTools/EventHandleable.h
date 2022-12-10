//
// Created by Raina Wan on 12/8/22.
//

#ifndef PORTFOLIO_EVENTHANDLEABLE_H
#define PORTFOLIO_EVENTHANDLEABLE_H

#include <SFML/Graphics.hpp>

class EventHandleable {
private:

public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;

};


#endif //PORTFOLIO_EVENTHANDLEABLE_H
