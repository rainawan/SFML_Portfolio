//
// Created by Raina Wan on 12/13/22.
//

#include "BombSprite.h"

BombSprite::BombSprite() : BombSprite(Images::get(BOMB)){

}

BombSprite::BombSprite(const sf::Texture &texture) : BombSprite(4.0,12.0,texture) {

}

BombSprite::BombSprite(float width, float height, const sf::Texture &texture) {
    setTexture(texture);
}

void BombSprite::draw() {

}

void BombSprite::setScale(float x, float y){

}

void BombSprite::setPosition(const sf::Vector2f &position) {
    Transformable::setPosition(position);
    square.setPosition(position);
}

void BombSprite::setPosition(float x, float y) {
    setPosition({x,y});
}