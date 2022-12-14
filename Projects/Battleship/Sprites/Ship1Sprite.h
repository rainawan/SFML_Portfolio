//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_SHIP1SPRITE_H
#define PORTFOLIO_SHIP1SPRITE_H

#include "SFML/Graphics.hpp"
#include "Images.h"

class Ship1Sprite : public sf::Sprite {
public:
    Ship1Sprite();
    Ship1Sprite(const sf::Texture& texture);
    void draw();
};


#endif //PORTFOLIO_SHIP1SPRITE_H
