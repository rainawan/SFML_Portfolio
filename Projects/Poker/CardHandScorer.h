//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_CARDHANDSCORER_H
#define PORTFOLIO_CARDHANDSCORER_H


#include <iostream>
#include <string>
#include "CardHand.h"
#include "Deck.h"
#include "PokerScore.h"

class CardHandScorer {
private:
    CardHand card_hand;
    PokerScore poker_score;

    int score_counter[PokerScore::NUM_HANDS];
public:
    std::vector<int> final_score;
    std::vector<std::string> ratio;
    int score = 0;
    std::vector<PokerScore::Scores> scores[10];
    CardHandScorer();
    static void scorePokerHand(CardHand card_hand, int score);
    void countHands();
};


#endif //PORTFOLIO_CARDHANDSCORER_H
