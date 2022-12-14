//
// Created by Raina Wan on 12/13/22.
//

#include "Ship4Sprite.h"

Ship4Sprite::Ship4Sprite() : Ship4Sprite(Images::get(SHIP4)) {
    setScale({2,2.7});
}

Ship4Sprite::Ship4Sprite(const sf::Texture &texture) {
    setTexture(texture);
}

void Ship4Sprite::draw(){

}