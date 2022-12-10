//
// Created by Raina Wan on 12/8/22.
//

#ifndef PORTFOLIO_GAMES_H
#define PORTFOLIO_GAMES_H


#include "SFMLTools/Application.h"
#include "Projects/Ball.h"
#include "Projects/BouncingBall.h"
#include "Projects/PingPong/Pong.h"
#include "Projects/TopHatGuy.h"
#include <iostream>

class Games : public Application {
private:
    Ball ball;
    BouncingBall bouncing_ball;
    Pong pong;
    TopHatGuy top_hat_guy;
public:
    Games();
};


#endif //PORTFOLIO_GAMES_H
