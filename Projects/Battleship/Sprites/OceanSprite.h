//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_OCEANSPRITE_H
#define PORTFOLIO_OCEANSPRITE_H

#include "SFML/Graphics.hpp"
#include "Images.h"

class OceanSprite : public sf::Sprite {
private:
    sf::Sprite square;
public:
    OceanSprite();
    OceanSprite(const sf::Texture& texture);
    void draw();
};


#endif //PORTFOLIO_OCEANSPRITE_H
