//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_BOMBSPRITE_H
#define PORTFOLIO_BOMBSPRITE_H

#include "SFML/Graphics.hpp"
#include "Images.h"
#include "../../Applications/States.h"

class BombSprite : public sf::Sprite, public States {
public:
    sf::Sprite square;
public:
    BombSprite();
    BombSprite(const sf::Texture& texture);
    BombSprite(float width, float height, const sf::Texture& texture);
    void draw();
    void setScale(float x, float y);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
//    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //PORTFOLIO_BOMBSPRITE_H
