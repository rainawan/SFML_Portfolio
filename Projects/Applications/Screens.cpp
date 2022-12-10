//
// Created by Raina Wan on 12/9/22.
//

#include "Screens.h"

Screens::Screens() : Screens("default", "text"){

}

Screens::Screens(std::string text, std::string buttonText)
        : text(text, Fonts::getFont(LEMON_MILK), 24), button(buttonText, {200,50})  {
    sf::RectangleShape r({720,420});
    Position::centerText(r, this->text);
    Position::bottom(this->text, button, 50.f);
}

void Screens::eventHandler(sf::RenderWindow &window, sf::Event event) {
    std::vector<Screens> screens;
    for (int i = 0; i < 5; ++i) {
        screens.emplace_back("Screens " + std::to_string(i+1),
                             "Button " + std::to_string(i+1));
    }
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
        window.clear(sf::Color::Blue);
        window.draw(*iter);
        window.display();
    }
}

void Screens::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
    target.draw(button);
}