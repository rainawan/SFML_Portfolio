//
// Created by Raina Wan on 12/13/22.
//

#include "Images.h"

std::map<image_enum, sf::Texture> Images::images;

void Images::load(image_enum image) {
    if(!images[image].loadFromFile(getPath(image)))
        exit(65);
}

std::string Images::getPath(image_enum image) {
    switch(image) {
        case BOMB: return "Projects/Applications/images/explosion.png";
        case X: return "Projects/Applications/images/ex.png";
        case SHIP1: return "Projects/Applications/images/ship1.png";
        case SHIP2: return "Projects/Applications/images/ship2.png";
        case SHIP3: return "Projects/Applications/images/ship3.png";
        case SHIP4: return "Projects/Applications/images/ship4.png";
        case OCEAN: return "Projects/Applications/images/ocean.png";
        case LAST_IMAGE: "";
    }
    return std::string();
}

sf::Texture &Images::get(image_enum image) {
    load(image);
    return images.at(image);
}