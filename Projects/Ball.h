//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_BALL_H
#define PORTFOLIO_BALL_H

#include <SFML/Graphics.hpp>
#include "../SFMLTools/Component.h"
#include "../SFMLTools/Application.h"

class Ball : public Component, public Application {
private:
    sf::CircleShape circle;
public:
    Ball();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_BALL_H
