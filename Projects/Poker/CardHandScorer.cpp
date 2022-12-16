//
// Created by Raina Wan on 12/13/22.
//

#include "CardHandScorer.h"

CardHandScorer::CardHandScorer() {
    std::vector<std::string> ratio(10);
    this->ratio = ratio;
}

void CardHandScorer::scorePokerHand(CardHand card_hand, int score) {
    score += 1;
}

void CardHandScorer::countHands() {
    const int NUM_TRIALS = 100000;
    CardHand cardHand;
    std::vector<int> final_score(10);
    std::vector<int> current_score(10);

    for (int i = 0; i < NUM_TRIALS; ++i) {
        card_hand.fullHand();

        PokerScore poker_score(card_hand);
        current_score = poker_score.checkScore();
        for (int hand_type = PokerScore::Scores::ROYAL_FLUSH; hand_type < PokerScore::NUM_HANDS; hand_type+=1) {
            final_score[hand_type] += current_score[hand_type];
        }
    }

//    std::cout<< "Royal Flush: " << final_score[PokerScore::Scores::ROYAL_FLUSH] << std::endl;
//    std::cout<< "Straight Flush: " << final_score[PokerScore::Scores::STRAIGHT_FLUSH] << std::endl;
//    std::cout<< "Four of a kind: " << final_score[PokerScore::Scores::FOUR_OF_A_KIND] << std::endl;
//    std::cout<< "Full House: " << final_score[PokerScore::Scores::FULL_HOUSE] << std::endl;
//    std::cout<< "Flush: " << final_score[PokerScore::Scores::FLUSH] << std::endl;
//    std::cout<< "Straight: " << final_score[PokerScore::Scores::STRAIGHT] << std::endl;
//    std::cout<< "Three of a Kind: " << final_score[PokerScore::Scores::THREE_OK_A_KIND] << std::endl;
//    std::cout<< "Two Pair: " << final_score[PokerScore::Scores::TWO_PAIR] << std::endl;
//    std::cout<< "One Pair: " << final_score[PokerScore::Scores::ONE_PAIR] << std::endl;
//    std::cout<< "High Card: " << final_score[PokerScore::Scores::HIGH_CARD] << std::endl;

    int denominator;
    for (int hand_type = PokerScore::Scores::ROYAL_FLUSH; hand_type < PokerScore::NUM_HANDS; hand_type++) {


        denominator = NUM_TRIALS / final_score[hand_type];
        final_score[hand_type] /=  final_score[hand_type];

        ratio[hand_type] = std::to_string(final_score[hand_type]) + " : " + std::to_string(denominator);
//        std::cout << ratio[hand_type] << std::endl;
    }
}