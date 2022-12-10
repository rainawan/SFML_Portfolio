//
// Created by Raina Wan on 12/9/22.
//

#include "Fonts.h"

std::map<fonts_enum, sf::Font> Fonts::map;

void Fonts::load(fonts_enum font) {
    map[font].loadFromFile(getPath(font));
}

std::string Fonts::getPath(fonts_enum font) {
    switch(font) {
        case LEMON_MILK: return "Projects/Applications/fonts/lemon_milk/LEMONMILK-Medium.otf";
        case LAST_FONT: return "";
    }
}

sf::Font &Fonts::getFont(fonts_enum font) {
    load(font);
    return map[font];
}