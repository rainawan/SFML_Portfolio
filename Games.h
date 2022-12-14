//
// Created by Raina Wan on 12/8/22.
//

#ifndef PORTFOLIO_GAMES_H
#define PORTFOLIO_GAMES_H


#include <iostream>
#include "SFMLTools/Application.h"
#include "Projects/Ball/Ball.h"
#include "Projects/BouncingBall/BouncingBall.h"
#include "Projects/PingPong/Pong.h"
#include "Projects/TopHatGuy/TopHatGuy.h"
#include "Projects/Card/Card_Main.h"
#include "Projects/Poker/Poker.h"
#include "Projects/Battleship/Battleship.h"
#include "Projects/Applications/Screens.h"

class Games : public Application {
private:
    Ball ball;
    BouncingBall bouncing_ball;
    Pong pong;
    TopHatGuy top_hat_guy;
    Card_Main card;
    Poker poker;
    Battleship battleship;
    Screens screen;
public:
    Games();
};


#endif //PORTFOLIO_GAMES_H
