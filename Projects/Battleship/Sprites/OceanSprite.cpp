//
// Created by Raina Wan on 12/13/22.
//

#include "OceanSprite.h"

OceanSprite::OceanSprite() : OceanSprite(Images::get(OCEAN)) {

}

OceanSprite::OceanSprite(const sf::Texture &texture) : Sprite(texture) {
    setTexture(texture);
}

void OceanSprite::draw() {

}