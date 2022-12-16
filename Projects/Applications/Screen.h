//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_SCREEN_H
#define PORTFOLIO_SCREEN_H

#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Component.h"
#include "../../SFMLTools/Application.h"
#include "ListItem.h"
#include "Fonts.h"
#include "../../Projects/Ball/Ball.h"
#include "../../Projects/BouncingBall/BouncingBall.h"
#include "../../Projects/TopHatGuy/TopHatGuy.h"
#include "../../Projects/Card/Card_Main.h"
#include "../../Projects/PingPong/Pong.h"
#include "../../Projects/Poker/Poker.h"
#include "../../Projects/Battleship/Battleship.h"
#include "../../Games.h"

//enum of games

class Screen : public States, public Component, public Application {
private:
    sf::Text text;
    ListItem button;
    Ball ball;
    BouncingBall bouncing_ball;
    TopHatGuy top_hat_guy;
    Games games;
//    std::vector<Component> games;
public:
    Screen();

    void changeGame();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_SCREEN_H
