//
// Created by Raina Wan on 12/13/22.
//

#include "MissSprite.h"

MissSprite::MissSprite() : MissSprite(Images::get(X)){

}

MissSprite::MissSprite(const sf::Texture &texture) : MissSprite(4.0,12.0,texture){

}

MissSprite::MissSprite(float width, float height, const sf::Texture &texture) {
    setTexture(texture);
}

void MissSprite::draw() {

}

void MissSprite::setScale(float x, float y){

}

void MissSprite::setPosition(const sf::Vector2f &position) {
    Transformable::setPosition(position);
    square.setPosition(position);
}

void MissSprite::setPosition(float x, float y) {
    setPosition({x,y});
}
