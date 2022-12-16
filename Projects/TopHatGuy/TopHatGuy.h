//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_TOPHATGUY_H
#define PORTFOLIO_TOPHATGUY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include "../../Projects/Applications/States.h"

class TopHatGuy : public Component, public Application {
private:
    sf::RectangleShape top;
    sf::RectangleShape rim;
    sf::CircleShape circle;
public:
    TopHatGuy();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_TOPHATGUY_H
