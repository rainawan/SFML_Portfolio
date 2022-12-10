//
// Created by Raina Wan on 12/8/22.
//

#include "Application.h"

Application::Application() : Application({1500, 1200, 32}, "Application") {

}

Application::Application(sf::VideoMode videoMode, const std::string &title) : videoMode(videoMode), title(title){

}

void Application::addComponent(Component &component) {
    components.push_back(&component);
}

void Application::run() {
    sf::RenderWindow window(videoMode,title);

    window.setFramerateLimit(60);
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
            for(EventHandleable *c : components)
                c->eventHandler(window, event);
            //onclickable
        }

        window.clear(sf::Color::White);

        for(sf::Drawable *c : components)
            window.draw(*c);

        window.display();
    }
}