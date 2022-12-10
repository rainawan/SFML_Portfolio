//
// Created by Raina Wan on 12/8/22.
//

#ifndef PORTFOLIO_APPLICATION_H
#define PORTFOLIO_APPLICATION_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Component.h"

class Application {
private:
    std::vector<Component*> components;
    sf::VideoMode videoMode;
    std::string title;
public:
    Application();
    Application(sf::VideoMode videoMode, const std::string& title);
    void addComponent(Component& component);
    void run();
};


#endif //PORTFOLIO_APPLICATION_H
