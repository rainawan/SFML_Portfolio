//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_LISTITEM_H
#define PORTFOLIO_LISTITEM_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Fonts.h"
#include "../../SFMLTools/MouseEvent.h"
#include "States.h"

class ListItem : public sf::Drawable, public States {
private:
    sf::RectangleShape box;
    sf::Text text;
    void setupText(std::string text);
    void setupBox(sf::Vector2f size);
    sf::Color backgroundColor = sf::Color::White, hoverColor = sf::Color::Blue;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    ListItem();
    ListItem(std::string text, sf::Vector2f size);
//    void onClick(sf::RenderWindow& window);
//    void eventHandler(sf::RenderWindow& window, const sf::Event &event);
    void update();
    void setBoxSize(sf::Vector2f size);
    void setTextSize(unsigned int size);
    sf::FloatRect getGlobalBounds() const;
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setString(std::string text);
    std::string getString();
};



#endif //PORTFOLIO_LISTITEM_H
