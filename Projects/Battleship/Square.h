//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_SQUARE_H
#define PORTFOLIO_SQUARE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Applications/States.h"
#include "Sprites/BombSprite.h"
#include "Sprites/MissSprite.h"
#include "../../SFMLTools/MouseEvent.h"
#include "../Applications/Position.h"

class Square : public sf::Drawable, public States {
private:
    sf::RectangleShape square;
    BombSprite bomb;
    MissSprite miss;
public:
    const float thickness = 8.0;
    Square();
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void onClick(void (*f)(), sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow &window, sf::Event event, states_enum state);
    sf::FloatRect getGlobalBounds() const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //PORTFOLIO_SQUARE_H
