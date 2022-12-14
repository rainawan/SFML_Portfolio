//
// Created by Raina Wan on 12/13/22.
//

#include "PokerCard.h"

PokerCard::PokerCard() : _suit(SPADES), _rank(ACE) {

}

PokerCard::PokerCard(suit_enum suit, rank_enum rank) : _suit(suit), _rank(rank) {

}

std::string PokerCard::rankToString() const{
    switch(_rank) {
        case ACE: return "ACE";
        case TWO: return "TWO";
        case THREE: return "THREE";
        case FOUR: return "FOUR";
        case FIVE: return "FIVE";
        case SIX: return "SIX";
        case SEVEN: return "SEVEN";
        case EIGHT: return "EIGHT";
        case NINE: return "NINE";
        case TEN: return "TEN";
        case JACK: return "JACK";
        case QUEEN: return "QUEEN";
        case KING: return "KING";
        default: return std::to_string(_rank + 1);
    }
}

std::string PokerCard::suitToString() const{
    switch(_suit) {
        case DIAMONDS: return "DIAMONDS";
        case CLUBS: return "CLUBS";
        case HEARTS: return "HEARTS";
        case SPADES: return "SPADES";
        default: return "INVALID";
    }
}
std::ostream& operator<<(std::ostream& out, const PokerCard& card) {
    return out << card.rankToString() << " of " << card.suitToString();
}

bool operator<(const PokerCard &lhs, const PokerCard &rhs) {
    return lhs._rank < rhs._rank;
}

void PokerCard::print() {
    std::cout << rankToString() << " of " << suitToString() << std::endl;
}

suit_enum PokerCard::getSuit() {
    return _suit;
}

rank_enum PokerCard::getRank() {
    return _rank;
}