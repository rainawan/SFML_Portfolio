//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_IMAGES_H
#define PORTFOLIO_IMAGES_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "image_enum.h"
#include <map>

class Images {
private:
    static std::map<image_enum, sf::Texture> images;
    static void load(image_enum image);
    static std::string getPath(image_enum image);
public:
    static sf::Texture& get(image_enum image);
};


#endif //PORTFOLIO_IMAGES_H
