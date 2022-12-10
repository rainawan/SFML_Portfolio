//
// Created by Raina Wan on 12/8/22.
//

#ifndef PORTFOLIO_BOUNCINGBALL_H
#define PORTFOLIO_BOUNCINGBALL_H

#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include <SFML/Graphics.hpp>

class BouncingBall : public Component, public Application {
private:
    sf::RectangleShape square;
    sf::CircleShape circle;
public:
    BouncingBall();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    virtual void update();
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_BOUNCINGBALL_H
