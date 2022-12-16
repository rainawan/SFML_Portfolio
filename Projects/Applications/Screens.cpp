//
// Created by Raina Wan on 12/9/22.
//

#include "Screens.h"



Screens::Screens() {

};

Screens::Screens(std::vector<Application> games) {
//    games.emplace_back(ball);

//    this->games = games;
//    Screens::game_playing = BOUNCING_BALL;
}

//Screens::Screens(Ball ball, std::string text, std::string buttonText, states_enum state)
//: ball(), text(text, Fonts::getFont(LEMON_MILK), 24), button(buttonText, {200,50}) {
//    addComponent(ball);
//    std::cout << " 1 ";
//    sf::RectangleShape r({720,420});
//    Position::centerText(r, this->text);
//    Position::bottom(this->text, button, 50.f);
//    enableState(BALL);
//}
//
//Screens::Screens(BouncingBall bouncing_ball, std::string text, std::string buttonText, states_enum state, sf::RenderWindow &window, sf::Event event)
//        : bouncing_ball(), text(text, Fonts::getFont(LEMON_MILK), 24), button(buttonText, {200,50})  {
//    std::cout << " 2 ";
//    addComponent(bouncing_ball);
//    sf::RectangleShape r({720,420});
//    Position::centerText(r, this->text);
//    Position::bottom(this->text, button, 50.f);
//
////    screens[0].bouncing_ball.eventHandler(window, event);
//    enableState(BOUNCING_BALL);
//}


void Screens::eventHandler(sf::RenderWindow &window, sf::Event event) {

    std::cout << " 3 ";

//    screens.emplace_back();
//    screens.emplace_back(ball, "Screens " + std::to_string(1),
//                         "Button " + std::to_string(1), BALL);
//    screens.emplace_back(bouncing_ball, "Screens " + std::to_string(2),
//                         "Button " + std::to_string(2), BOUNCING_BALL, window, event);

//    bouncing_ball.eventHandler(window, event);

    auto iter = games.begin();


    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if(iter != games.begin())
                    --iter;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                auto iter2 = iter;
                if(iter2 != games.end()-1)
                    ++iter;
            }
        }

        window.clear(sf::Color::Transparent);
//        window.draw(games[game_playing]);
//        window.draw(*iter);
        window.display();
    }
}

void Screens::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    if (getState(BALL)) {target.draw(ball);}
//    if(getState(BOUNCING_BALL)) {target.draw(bouncing_ball);}
//    if(getState(TOP_HAT_GUY)) {target.draw(top_hat_guy);}
    target.draw(text);
    target.draw(button);
}