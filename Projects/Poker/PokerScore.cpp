//
// Created by Raina Wan on 12/13/22.
//

#include "PokerScore.h"

PokerScore::PokerScore() {

}

PokerScore::PokerScore(CardHand card_hand) {
    this->card_hand=card_hand;
}

int PokerScore::size() {
    return 0;
}


bool PokerScore::isRoyalFlush() {
    return (card_hand[0].getRank() == 0 && card_hand[1].getRank() == 9
            && isSequence() && isSameSuit());
}

bool PokerScore::isStraightFlush() {
    return (isSameSuit() and isSequence());
}

bool PokerScore::isFourKind() {
    int firstCount = 0;
    int secondCount = 0;
    int first = card_hand[0].getRank();
    int second = card_hand[1].getRank();
    for (int i = 1; i < CardHand::MAX_HAND_SIZE; ++i) {
        if (card_hand[i].getRank() == first)
            firstCount++;
        else if (card_hand[i].getRank() == second)
            secondCount++;
    }
    if(firstCount == 3 || secondCount == 4)
        return true;
    return false;
}

bool PokerScore::isFullHouse() {
    if(!isThreeKind())
        return false;
    for (int i = 0; i < 1; ++i) {
        if(card_hand[i].getRank() == card_hand[i+1].getRank()
           && card_hand[i].getRank() == card_hand[i+2].getRank()
           && card_hand[i+3].getRank() == card_hand[i+4].getRank())
            return true;
        if(card_hand[i].getRank() == card_hand[i+1].getRank()
           && card_hand[i+2].getRank() == card_hand[i+3].getRank()
           && card_hand[i+2].getRank() == card_hand[i+4].getRank())
            return true;
    }
    return false;
}

bool PokerScore::isFlush() {
    return (isSameSuit() and not isSequence());
}

bool PokerScore::isStraight() {
    return (isSequence() and not isSameSuit());
}

bool PokerScore::isSameSuit() {
    for (int i = 0; i < card_hand.size()-1; ++i) {
        if(card_hand[i].getSuit() != card_hand[i+1].getSuit())
            return false;
    }
    return true;
}

bool PokerScore::isSequence() {
    // A 2 3 4 5 // A 2 J Q K // J Q K A 2 //
    for (int i = 0; i < card_hand.size()-1; ++i) {
        if(card_hand[i+1].getRank() - card_hand[i].getRank() != 1
           && card_hand[i+1].getRank() - card_hand[i].getRank() != 9) {
            return false;
        }
    }
    return true;
}

bool PokerScore::isThreeKind() {
    for (int i = 0; i < 3; ++i) {
        if(card_hand[i].getRank() == card_hand[i+1].getRank()
           && card_hand[i].getRank() == card_hand[i+2].getRank())
            return true;
    }
    return false;
}

bool PokerScore::isTwoPair() {
    for (int i = 0; i < 2; ++i) {
        if(card_hand[i].getRank() == card_hand[i+1].getRank()
           && card_hand[i+2].getRank() == card_hand[i+3].getRank())
            return true;
    }
    return (card_hand[0].getRank() == card_hand[1].getRank()
            && card_hand[3].getRank() == card_hand[4].getRank());
}

bool PokerScore::isOnePair() {
    for (int i = 0; i < CardHand::MAX_HAND_SIZE-1; ++i) {

        if(card_hand[i].getRank() == card_hand[i+1].getRank())
            return true;
    }
    return false;
}

bool PokerScore::isHighCard() {
    return true;
}

std::vector<int> PokerScore::checkScore() {
    std::vector<int> score_counter(NUM_HANDS);

    if(isRoyalFlush())
        score_counter[Scores::ROYAL_FLUSH]++;
    if (isStraightFlush())
        score_counter[Scores::STRAIGHT_FLUSH]++;
    if (isFourKind())
        score_counter[Scores::FOUR_OF_A_KIND]++;
    if (isFullHouse())
        score_counter[Scores::FULL_HOUSE]++;
    if (isFlush())
        score_counter[Scores::FLUSH]++;
    if (isStraight())
        score_counter[Scores::STRAIGHT]++;
    if (isThreeKind())
        score_counter[Scores::THREE_OK_A_KIND]++;
    if (isTwoPair())
        score_counter[Scores::TWO_PAIR]++;
    if (isOnePair())
        score_counter[Scores::ONE_PAIR]++;
    if (isHighCard())
        score_counter[Scores::HIGH_CARD]++;

    return score_counter;
}
