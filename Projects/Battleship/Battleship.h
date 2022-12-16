//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_BATTLESHIP_H
#define PORTFOLIO_BATTLESHIP_H


#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include "Grid.h"
#include "Sprites/OceanSprite.h"
#include "../../Projects/Applications/States.h"

class Battleship : public Component, public Application {
public:
    Battleship();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_BATTLESHIP_H
