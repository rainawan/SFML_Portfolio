//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_POKER_H
#define PORTFOLIO_POKER_H


#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include "PokerScore.h"
#include "CardHandScorer.h"
#include "DrawableScore.h"

class Poker : public Component, public Application {
public:
    Poker();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_POKER_H
