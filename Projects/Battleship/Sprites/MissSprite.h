//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_MISSSPRITE_H
#define PORTFOLIO_MISSSPRITE_H

#include "SFML/Graphics.hpp"
#include "Images.h"
#include "../../Applications/States.h"

class MissSprite : public sf::Sprite, public States {
public:
    sf::Sprite square;
public:
    MissSprite();
    MissSprite(const sf::Texture& texture);
    MissSprite(float width, float height, const sf::Texture& texture);
    void draw();
    void setScale(float x, float y);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
};


#endif //PORTFOLIO_MISSSPRITE_H
