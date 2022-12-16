//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_GRID_H
#define PORTFOLIO_GRID_H


#include <iostream>
#include <vector>
#include "Square.h"
#include "HiddenGrid.h"
#include "../Applications/States.h"
#include "../Applications/Position.h"
#include "Sprites/BombSprite.h"
#include "Sprites/MissSprite.h"
#include "Sprites/Ship1Sprite.h"
#include "Sprites/Ship2Sprite.h"
#include "Sprites/Ship3Sprite.h"
#include "Sprites/Ship4Sprite.h"

class Grid : public sf::Drawable, public States {
private:
    std::vector<sf::Text> letters;

    static sf::Font font;
    HiddenGrid hidden;
    Square square;
    const int num_rows = 5;
    const int num_cols = 5;
    const int spacing = 120;
    BombSprite bomb;
    MissSprite miss;
    Ship1Sprite ship1;
    Ship2Sprite ship2;
    Ship3Sprite ship3;
    Ship4Sprite ship4;
    std::vector<std::vector<bool>> hit =
            {
                    {false, false, false, false, false},
                    {false, false, false, false, false},
                    {false, false, false, false, false},
                    {false, false, false, false, false},
                    {false, false, false, false, false}
            };
public:
    std::vector<std::vector<Square>> board;
    Grid();
    void makeGrid();
    void makeCoord();
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void onClick(sf::RenderWindow& window);
    void is_hit(std::string ship);
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();

};


#endif //PORTFOLIO_GRID_H
