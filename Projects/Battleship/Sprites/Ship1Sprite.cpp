//
// Created by Raina Wan on 12/13/22.
//

#include "Ship1Sprite.h"

Ship1Sprite::Ship1Sprite() : Ship1Sprite(Images::get(SHIP1)) {
    setScale({2.5,1.6});
}

Ship1Sprite::Ship1Sprite(const sf::Texture &texture) {
    setTexture(texture);
}

void Ship1Sprite::draw(){

}
