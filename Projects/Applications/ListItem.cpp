//
// Created by Raina Wan on 12/9/22.
//

#include "ListItem.h"

ListItem::ListItem() : ListItem("",{0.f,0.f}){

}

ListItem::ListItem(std::string text, sf::Vector2f size) {
    setupText(text);
    setupBox(size);
}

void ListItem::setupText(std::string text) {
    this->text.setFont(Fonts::getFont(LEMON_MILK));
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Red);
    Position::centerText(box, this->text);
}

void ListItem::setupBox(sf::Vector2f size) {
    setBoxSize(size);
}

//void ListItem::onClick(sf::RenderWindow& window) {
//
//}

//void ListItem::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
//    if(MouseEvent::isHovered(box, window)) {
//        box.setFillColor(hoverColor);
//        text.setFillColor(backgroundColor);
//    }
//    else {
//        box.setFillColor(backgroundColor);
//        text.setFillColor(hoverColor);
//    }
//}

void ListItem::update() {

}

void ListItem::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, text);
}

void ListItem::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
    Position::centerText(box, text);
}

void ListItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) { //only draw if not hidden
        target.draw(box);
        target.draw(text);
    }
}

sf::FloatRect ListItem::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void ListItem::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    Position::centerText(box, text);
}

void ListItem::setPosition(float x, float y) {
    setPosition({x, y});
}

void ListItem::setString(std::string text) {
    this->text.setString(text);
}

std::string ListItem::getString() {
    return text.getString();
}
