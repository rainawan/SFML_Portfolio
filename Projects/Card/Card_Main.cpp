//
// Created by Raina Wan on 12/13/22.
//

#include "Card_Main.h"


Card_Main::Card_Main() {

}

void Card_Main::eventHandler(sf::RenderWindow &window, sf::Event event) {

    window.setFramerateLimit(60);
    Card c(CLUBS, SIX);
    c.setPosition({500,500});
    while(window.isOpen() && gp::game_playing == CARD) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            gp::game_playing = TOP_HAT_GUY;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            gp::game_playing = POKER;
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
        }
        window.clear(sf::Color(166, 163, 186));
        window.draw(c);
        window.display();
    }
}

void Card_Main::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
