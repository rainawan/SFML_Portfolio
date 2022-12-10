//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_FONTS_H
#define PORTFOLIO_FONTS_H

#include "fonts_enum.h"
#include <SFML/Graphics.hpp>
#include <map>

class Fonts {
private:
    static std::map<fonts_enum, sf::Font> map;
    static void load(fonts_enum font);
    static std::string getPath(fonts_enum font);
public:
    static sf::Font& getFont(fonts_enum font);
};


#endif //PORTFOLIO_FONTS_H
