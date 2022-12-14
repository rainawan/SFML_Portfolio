//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_POKERSCORE_H
#define PORTFOLIO_POKERSCORE_H


#include <iostream>
#include <vector>
#include "CardHand.h"
#include "PokerCard.h"
#include "../Card/rank_enum.h"

class PokerScore {
private:
public:
    enum Scores {
        ROYAL_FLUSH, //A, K, Q, J, 10, all the same _suit.
        STRAIGHT_FLUSH, //five card_hand of the same _suit and consecutive ranking
        FOUR_OF_A_KIND, //four card_hand of the same ranking
        FULL_HOUSE, //three card_hand of the same _rank along with two card_hand of the same _rank
        FLUSH, //five card_hand of the same _suit
        STRAIGHT, //five card_hand in consecutive ranking
        THREE_OK_A_KIND, //three card_hand of the same _rank
        TWO_PAIR, //two card_hand of the same _rank along with another two card_hand of the same _rank
        ONE_PAIR, //two card_hand of the same _rank
        HIGH_CARD //highest card in the player’s hand
    };
    static const int NUM_HANDS = 10;
    std::vector<PokerScore::Scores> scores;
    CardHand card_hand;
    int score = 0;
    bool isRoyalFlush();
    bool isStraightFlush(); // works
    bool isFourKind();
    bool isFullHouse();
    bool isFlush(); //works!
    bool isStraight(); //works!
    bool isThreeKind();
    bool isTwoPair();
    bool isOnePair(); //works
    bool isHighCard(); //works
    bool isSameSuit(); //works
    bool isSequence(); //works
    std::vector<int> checkScore();
    int size();
    PokerScore();
    PokerScore(CardHand card_hand);
};


#endif //PORTFOLIO_POKERSCORE_H
