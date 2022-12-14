//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_SHIP2SPRITE_H
#define PORTFOLIO_SHIP2SPRITE_H
#include "SFML/Graphics.hpp"
#include "Images.h"

class Ship2Sprite : public sf::Sprite {
public:
    Ship2Sprite();
    Ship2Sprite(const sf::Texture& texture);
    void draw();
};


#endif //PORTFOLIO_SHIP2SPRITE_H
