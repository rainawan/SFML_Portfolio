//
// Created by Raina Wan on 12/13/22.
//

#include "CardHand.h"

CardHand::CardHand() {

}

void CardHand::add(PokerCard card) {
    if (cards.size() == MAX_HAND_SIZE)
        return;
    cards.push_back(card);
}

void CardHand::print() {
    for (int i = 0; i < cards.size(); ++i) {
        cards[i].print();
    }
}

void CardHand::fullHand() {
    std::vector<PokerCard> new_cards;
    Deck deck;
    deck.shuffle();
    for (int i = 0; i < MAX_HAND_SIZE; ++i) {
        PokerCard card = deck.getCards()[i];
        new_cards.push_back(card);
    }
    cards = new_cards;
    sort();
}

PokerCard& CardHand::operator[](unsigned int index) {
    if (index >= cards.size()) {
        std::cout << "Array index out of bound, exiting";
        exit(0);
    }
    return cards[index];
}

void CardHand::sort() {
    std::sort(cards.begin(), cards.end());
}

std::ostream& operator<<(std::ostream& out, const CardHand& card_hand) {
    for (int i = 0; i < 5; ++i) {
        return out << card_hand.cards[i];
    }
}
int CardHand::size() {
    return cards.size();
}
