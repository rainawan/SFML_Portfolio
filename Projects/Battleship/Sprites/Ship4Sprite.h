//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_SHIP4SPRITE_H
#define PORTFOLIO_SHIP4SPRITE_H


#include "SFML/Graphics.hpp"
#include "Images.h"

class Ship4Sprite: public sf::Sprite {
public:
    Ship4Sprite();
    Ship4Sprite(const sf::Texture& texture);
    void draw();
};


#endif //PORTFOLIO_SHIP4SPRITE_H
