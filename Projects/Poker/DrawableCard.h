//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_DRAWABLECARD_H
#define PORTFOLIO_DRAWABLECARD_H


#include "SFML/Graphics.hpp"
#include "../Card/rank_enum.h"
#include "../Card/suit_enum.h"
#include <string>
#include <iostream>

class DrawableCard : public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape background;
    sf::Text topRank, bottomRank, poker_score;
    sf::Sprite suit;
    sf::Texture texture;
    static sf::Font font;
    suit_enum _suit;
    rank_enum _rank;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setupBackground();
    void setupRank();
    void setupSuit();
    void setupPokerScore();
public:
    DrawableCard();
    DrawableCard(suit_enum suit, rank_enum rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setFillColor(const sf::Color& color);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void flip();
};


#endif //PORTFOLIO_DRAWABLECARD_H
