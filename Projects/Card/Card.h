//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_CARD_H
#define PORTFOLIO_CARD_H


#include "SFML/Graphics.hpp"
#include "rank_enum.h"
#include "suit_enum.h"
#include <string>
#include <iostream>

class Card : public sf::Drawable {
private:
    sf::RectangleShape background;
    sf::Text rank;
    sf::Text rank2;
    sf::Sprite suit; //holds image of heart
    static sf::Texture texture;
    static sf::Font font;
    suit_enum _suit;
    rank_enum _rank; //user input of image
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setupBackground();
    void setupRank();
    void setupSuit();
public:
    Card();
    Card(suit_enum suit, rank_enum rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void flip();
    friend std::ostream& operator<<(std::ostream& out, const Card& rank);
    friend std::string getSuitString(suit_enum);
    std::string getRank();
    std::string getSuit();
};


#endif //PORTFOLIO_CARD_H
