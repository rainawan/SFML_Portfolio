//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_DRAWABLESCORE_H
#define PORTFOLIO_DRAWABLESCORE_H


#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "CardHandScorer.h"

class DrawableScore : public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape background;
    sf::Text score_text;
    sf::Texture texture;
    std::string scorer;
    static sf::Font font;
    std::string scoreToString(PokerScore::Scores);
    void initialize();
    void setupScore();
    void setString();
    void setupBackground();
public:
    DrawableScore();
    DrawableScore(std::string scorer);
    void setPosition(sf::Vector2f position);
    void setSize(float size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //PORTFOLIO_DRAWABLESCORE_H
