//
// Created by Raina Wan on 12/9/22.
//

#include "Screens.h"

Screens::Screens() {
//    addComponent(bouncing_ball);
};

Screens::Screens(Ball ball, std::string text, std::string buttonText, states_enum state)
: ball(), text(text, Fonts::getFont(LEMON_MILK), 24), button(buttonText, {200,50}) {
    addComponent(ball);
    sf::RectangleShape r({720,420});
    Position::centerText(r, this->text);
    Position::bottom(this->text, button, 50.f);
    enableState(BALL);
}

Screens::Screens(BouncingBall bouncing_ball, std::string text, std::string buttonText, states_enum state)
        : bouncing_ball(), text(text, Fonts::getFont(LEMON_MILK), 24), button(buttonText, {200,50}) {
    addComponent(bouncing_ball);
    sf::RectangleShape r({720,420});
    Position::centerText(r, this->text);
    Position::bottom(this->text, button, 50.f);
    enableState(BOUNCING_BALL);
}

Screens::Screens(TopHatGuy top_hat_guy, std::string text, std::string buttonText, states_enum state)
        : top_hat_guy(), text(text, Fonts::getFont(LEMON_MILK), 24), button(buttonText, {200,50}) {
    addComponent(top_hat_guy);
    sf::RectangleShape r({720,420});
    Position::centerText(r, this->text);
    Position::bottom(this->text, button, 50.f);
    enableState(TOP_HAT_GUY);
}

void Screens::eventHandler(sf::RenderWindow &window, sf::Event event) {

    screens.emplace_back(ball, "Screens " + std::to_string(1),
                         "Button " + std::to_string(1), BALL);
    screens.emplace_back(bouncing_ball, "Screens " + std::to_string(2),
                         "Button " + std::to_string(2), BOUNCING_BALL);
    screens.emplace_back(top_hat_guy, "Screens " + std::to_string(4),
                         "Button " + std::to_string(4), TOP_HAT_GUY);

    auto iter = screens.begin();


    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if(iter != screens.begin())
                    --iter;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                auto iter2 = iter;
                if(iter2 != screens.end()-1)
                    ++iter;
            }
        }
        window.clear(sf::Color::Transparent);
        window.draw(*iter);
        window.display();
    }
}

void Screens::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (checkState(BALL)) {target.draw(ball);}
    if(checkState(BOUNCING_BALL)) {target.draw(bouncing_ball);}
    if(checkState(TOP_HAT_GUY)) {target.draw(top_hat_guy);}
    target.draw(text);
    target.draw(button);
}