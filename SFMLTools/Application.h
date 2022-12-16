//
// Created by Raina Wan on 12/8/22.
//

#ifndef PORTFOLIO_APPLICATION_H
#define PORTFOLIO_APPLICATION_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Component.h"
#include <iostream>

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
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //PORTFOLIO_APPLICATION_H
