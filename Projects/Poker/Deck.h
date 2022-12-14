//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_DECK_H
#define PORTFOLIO_DECK_H


#include "SFML/Graphics.hpp"
#include "DrawableCard.h"
#include "PokerCard.h"
#include "../Card/rank_enum.h"
#include "../Card/suit_enum.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

class Deck : public sf::Drawable {
private:
    std::vector<DrawableCard> drawable_deck;
    std::vector<PokerCard> cards;
public:
    Deck();
    bool empty();
    int cardIndex;
    const int DECK_SIZE = 52;
    void shuffle();
    friend std::ostream& operator<<(std::ostream& out, const Deck& rank);
    friend std::istream& operator>>(std::istream& in, Deck& deck);
    DrawableCard dealCard();
    DrawableCard getCardAt(int index);
    void print();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    const std::vector<PokerCard> &getCards() const;

};


#endif //PORTFOLIO_DECK_H
