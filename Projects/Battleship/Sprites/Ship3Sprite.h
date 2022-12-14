//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_SHIP3SPRITE_H
#define PORTFOLIO_SHIP3SPRITE_H


#include "SFML/Graphics.hpp"
#include "Images.h"

class Ship3Sprite : public sf::Sprite {
public:
    Ship3Sprite();
    Ship3Sprite(const sf::Texture& texture);
    void draw();
};

#endif //PORTFOLIO_SHIP3SPRITE_H
