//
// Created by Raina Wan on 12/13/22.
//

#include "Card_Main.h"


Card_Main::Card_Main() {

}

void Card_Main::eventHandler(sf::RenderWindow &window, sf::Event event) {

    window.setFramerateLimit(60);
    Card c(CLUBS, SIX);
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
        }
        window.clear();
        window.draw(c);
        window.display();
    }
}

void Card_Main::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
