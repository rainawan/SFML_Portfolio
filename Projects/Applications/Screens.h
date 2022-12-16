//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_SCREENS_H
#define PORTFOLIO_SCREENS_H

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
#include <iostream>

class Screens : public States, public Component, public Application {
private:
//    std::vector<Screens> screens;
    sf::Text text;
    ListItem button;
    Ball ball;
    BouncingBall bouncing_ball;
//    TopHatGuy top_hat_guy;
    std::vector<States> states;
    std::vector<Application> games;
public:
    Screens();
    Screens(std::vector<Application>games);
    Screens(std::string text, std::string buttonText);
//    Screens(Ball ball, std::string text, std::string buttonText, states_enum state);
//    Screens(BouncingBall bouncing_ball, std::string text, std::string buttonText, states_enum state, sf::RenderWindow &window, sf::Event event);
//    Screens(TopHatGuy top_hat_guy, std::string text, std::string buttonText, states_enum state);
    static states_enum game_playing;
    void set_button(sf::Text text, ListItem button);
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_SCREENS_H
