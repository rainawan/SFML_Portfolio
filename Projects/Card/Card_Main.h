//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_CARD_MAIN_H
#define PORTFOLIO_CARD_MAIN_H


#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include "Card.h"
#include "rank_enum.h"
#include "suit_enum.h"

class Card_Main: public Component, public Application {
public:
    Card_Main();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_CARD_MAIN_H
