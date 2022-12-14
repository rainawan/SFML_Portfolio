//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_CARDHAND_H
#define PORTFOLIO_CARDHAND_H


#include "Deck.h"
#include "PokerCard.h"
#include <iostream>

class CardHand {
private:
    std::vector<PokerCard> cards;
    int* ptr;
public:
    static const int MAX_HAND_SIZE = 5;
    CardHand();
    void add(PokerCard card);
    void print();
    void fullHand();
    PokerCard& operator[](unsigned int index);
    void sort();
    int size();
    friend std::ostream& operator<<(std::ostream& out, const CardHand& card_hand);
};


#endif //PORTFOLIO_CARDHAND_H
