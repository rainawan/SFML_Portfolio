//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_POKERCARD_H
#define PORTFOLIO_POKERCARD_H

#include "../Card/rank_enum.h"
#include "../Card/suit_enum.h"
#include <string>
#include <iostream>

class PokerCard {
private:
    suit_enum _suit;
    rank_enum _rank;
public:
    PokerCard();
    PokerCard(suit_enum suit, rank_enum rank);
    friend std::ostream& operator<<(std::ostream& out, const PokerCard& card);
    friend bool operator<(PokerCard const&lhs, PokerCard const& rhs);
    std::string rankToString() const;
    std::string suitToString() const;
    suit_enum getSuit();
    rank_enum getRank();
    void print();
};


#endif //PORTFOLIO_POKERCARD_H
