//
// Created by Raina Wan on 12/13/22.
//

#include "Poker.h"

Poker::Poker() {

}

void Poker::eventHandler(sf::RenderWindow &window, sf::Event event) {
    window.setFramerateLimit(60);

    CardHandScorer hand;
    hand.countHands();
    DrawableScore poker_scores[10] = {
            DrawableScore(hand.ratio[PokerScore::Scores::ROYAL_FLUSH]),
            DrawableScore(hand.ratio[PokerScore::Scores::STRAIGHT_FLUSH]),
            DrawableScore(hand.ratio[PokerScore::Scores::FOUR_OF_A_KIND]),
            DrawableScore(hand.ratio[PokerScore::Scores::FULL_HOUSE]),
            DrawableScore(hand.ratio[PokerScore::Scores::FLUSH]),
            DrawableScore(hand.ratio[PokerScore::Scores::STRAIGHT]),
            DrawableScore(hand.ratio[PokerScore::Scores::THREE_OK_A_KIND]),
            DrawableScore(hand.ratio[PokerScore::Scores::TWO_PAIR]),
            DrawableScore(hand.ratio[PokerScore::Scores::ONE_PAIR]),
            DrawableScore(hand.ratio[PokerScore::Scores::HIGH_CARD]),
    };
    poker_scores[0].setPosition({1030,100});
    poker_scores[5].setPosition({2320,100});

    // height distance between poker scores
    for (int i = 1; i < 5; ++i) {
        poker_scores[i].setPosition({poker_scores[i - 1].getPosition().x, poker_scores[i - 1].getPosition().y + 320});
    }
    for (int i = 6; i < 10; ++i) {
        poker_scores[i].setPosition({poker_scores[i - 1].getPosition().x, poker_scores[i - 1].getPosition().y + 320});
    }
    // poker score character size
    for (int i = 0; i < 10; ++i) {
        poker_scores[i].setSize(45);
    }

    DrawableCard cards[10][5] = {{DrawableCard(SPADES, ACE), DrawableCard(SPADES, TEN), DrawableCard(SPADES, JACK), DrawableCard(SPADES, QUEEN), DrawableCard(SPADES, KING) },
                                 {DrawableCard(HEARTS, FIVE), DrawableCard(HEARTS, SIX), DrawableCard(HEARTS, SEVEN), DrawableCard(HEARTS, EIGHT), DrawableCard(HEARTS, NINE) },
                                 {DrawableCard(DIAMONDS, TWO), DrawableCard(CLUBS, TWO), DrawableCard(HEARTS, TWO), DrawableCard(SPADES, TWO), DrawableCard(DIAMONDS, NINE) },
                                 {DrawableCard(CLUBS, ACE), DrawableCard(SPADES, ACE), DrawableCard(DIAMONDS, ACE), DrawableCard(CLUBS, SEVEN), DrawableCard(SPADES, SEVEN) },
                                 {DrawableCard(CLUBS, THREE), DrawableCard(CLUBS, SEVEN), DrawableCard(CLUBS, TEN), DrawableCard(CLUBS, QUEEN), DrawableCard(CLUBS, KING) },
                                 {DrawableCard(HEARTS, ACE), DrawableCard(HEARTS, TWO), DrawableCard(SPADES, THREE), DrawableCard(SPADES, FOUR), DrawableCard(SPADES, FIVE) },
                                 {DrawableCard(DIAMONDS, FOUR), DrawableCard(CLUBS, FOUR), DrawableCard(HEARTS, FOUR), DrawableCard(DIAMONDS, QUEEN), DrawableCard(CLUBS, QUEEN) },
                                 {DrawableCard(HEARTS, THREE), DrawableCard(SPADES, THREE), DrawableCard(CLUBS, SEVEN), DrawableCard(DIAMONDS, NINE), DrawableCard(SPADES, NINE) },
                                 {DrawableCard(CLUBS, ACE), DrawableCard(SPADES, ACE), DrawableCard(HEARTS, FIVE), DrawableCard(DIAMONDS, SEVEN), DrawableCard(HEARTS, KING) },
                                 {DrawableCard(SPADES, TWO), DrawableCard(DIAMONDS, THREE), DrawableCard(CLUBS, EIGHT), DrawableCard(DIAMONDS, JACK), DrawableCard(CLUBS, KING) }};

    cards[0][0].setPosition({30,30});
    cards[5][0].setPosition({1300,30});

    // set size of cards
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cards[i][j].setSize(185,250);
        }
    }

    // distance between each row of cards
    for (int i = 1; i < 5; ++i) {
        cards[i][0].setPosition({cards[i-1][0].getPosition().x, cards[i-1][0].getPosition().y+310});
    }
    for (int i = 6; i < 10; ++i) {
        cards[i][0].setPosition({cards[i-1][0].getPosition().x, cards[i-1][0].getPosition().y+310});
    }

    // distance between column; width between one hand of cards
    for (int i = 0; i < 10; ++i) {
        for (int j = 1; j < 5; ++j) {
            cards[i][j].setPosition({cards[i][j - 1].getPosition().x + 200, cards[i][j - 1].getPosition().y});
        }
    }


    while(window.isOpen() && gp::game_playing == POKER) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            gp::game_playing = CARD;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            gp::game_playing = BATTLESHIP;
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
        }
        window.clear(sf::Color(53,101,77));
        //draw card hands
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                window.draw(cards[i][j]);
            }
        }
        //draw poker score
        for (int i = 0; i < 10; ++i) {
            window.draw(poker_scores[i]);
        }

        window.display();
    }
}

void Poker::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
