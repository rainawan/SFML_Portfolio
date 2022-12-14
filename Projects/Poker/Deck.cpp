//
// Created by Raina Wan on 12/13/22.
//

#include "Deck.h"

Deck::Deck() {
    for(int suit = 0; suit < 4; suit++) {
        for(int rank = 0; rank < 13; rank++) {
            PokerCard card(static_cast<suit_enum>(suit), static_cast<rank_enum>(rank));
            cards.push_back(card);
        }
    }
    shuffle();
}


bool Deck::empty() {
    if (cards.empty())
        return true;
    return false;
}

void Deck::shuffle() {
    PokerCard temp;

    for(int i = 0; i < DECK_SIZE; i++) {
        std::swap(cards[i],cards[rand() % DECK_SIZE]);
    }
}

DrawableCard Deck::dealCard() {
    return DrawableCard();
}

DrawableCard Deck::getCardAt(int index) {
    return DrawableCard();
}



void Deck::print() {
    for (int i = 0; i < cards.size(); ++i) {
        cards[i].print();
    }
}


std::ostream &operator<<(std::ostream& out, const Deck& rank) {
    return out << "hello";
}

std::istream &operator>>(std::istream &in, Deck &deck) {
    return in >> deck;
}

void Deck::draw(sf::RenderTarget &window, sf::RenderStates states) const {

}

const std::vector<PokerCard> &Deck::getCards() const {
    return cards;
}
