#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLTools/Application.h"
#include "Projects/Ball/Ball.h"
#include "Projects/BouncingBall/BouncingBall.h"
#include "Games.h"
#include "Projects/Applications/Screens.h"
#include "Projects/Applications/Screen.h"

int main() {

    Games games;
    games.run();

    return 0;
}
