//
// Created by Raina Wan on 12/13/22.
//

#include "Ship2Sprite.h"

Ship2Sprite::Ship2Sprite() : Ship2Sprite(Images::get(SHIP2)) {
    setScale({2.3,2});
}

Ship2Sprite::Ship2Sprite(const sf::Texture &texture) {
    setTexture(texture);
}

void Ship2Sprite::draw(){

}