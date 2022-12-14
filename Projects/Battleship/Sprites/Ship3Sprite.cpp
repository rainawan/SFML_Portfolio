//
// Created by Raina Wan on 12/13/22.
//

#include "Ship3Sprite.h"

Ship3Sprite::Ship3Sprite() : Ship3Sprite(Images::get(SHIP3)) {
    setScale({2.5,1.8});
}

Ship3Sprite::Ship3Sprite(const sf::Texture &texture) {
    setTexture(texture);
}

void Ship3Sprite::draw(){

}