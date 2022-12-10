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

class Screens : public States, public Component, public Application{
private:
    sf::Text text;
    ListItem button;
public:
    Screens();
    Screens(std::string text, std::string buttonText);
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_SCREENS_H
