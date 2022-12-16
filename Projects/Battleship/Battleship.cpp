//
// Created by Raina Wan on 12/13/22.
//

#include "Battleship.h"

Battleship::Battleship() {

}

void Battleship::eventHandler(sf::RenderWindow &window, sf::Event event) {
    window.setFramerateLimit(60);

    Grid grid;
    grid.setPosition(window.getSize().x/2 - grid.getGlobalBounds().width/3.5, window.getSize().y/2 - grid.getGlobalBounds().height/3.5);

    OceanSprite ocean;
    ocean.setScale(4.1,1.9);


    while(window.isOpen() && gp::game_playing == BATTLESHIP) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            gp::game_playing = POKER;
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            grid.eventHandler(window, event);
            grid.onClick(window);
        }

        window.clear(sf::Color::White);
        window.draw(ocean);
        window.draw(grid);
        window.display();
    }
}

void Battleship::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
