//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_PONG_H
#define PORTFOLIO_PONG_H


#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include "PongBall.h"
#include "Paddle.h"

class Pong : public Component, public Application {
private:
    PongBall pong_ball;
    Paddle paddleLeft;
    Paddle paddleRight;
public:
    Pong();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_PONG_H
