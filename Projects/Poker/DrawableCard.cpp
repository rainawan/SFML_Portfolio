//
// Created by Raina Wan on 12/13/22.
//

#include "DrawableCard.h"

sf::Font DrawableCard::font;

DrawableCard::DrawableCard() {

}

DrawableCard::DrawableCard(suit_enum suit, rank_enum rank) : _suit(suit), _rank(rank){
    initialize();
}

void DrawableCard::initialize() {
    setupBackground();
    setupRank();
    setupSuit();
}

void DrawableCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(background, states);
    window.draw(suit, states);
    window.draw(topRank, states);
    window.draw(bottomRank, states);
}

void DrawableCard::setFillColor(const sf::Color &color) {
    if(_suit == HEARTS || _suit == DIAMONDS) {
        topRank.setFillColor(sf::Color::Red);
        bottomRank.setFillColor(sf::Color::Red);
    }
    if(_suit == SPADES || _suit == CLUBS) {
        topRank.setFillColor(sf::Color::Black);
        bottomRank.setFillColor(sf::Color::Black);
    }
}

void DrawableCard::setSize(float width, float height) {
    background.setSize({width, height});
    topRank.setCharacterSize(background.getSize().x * 4 / 25);
    topRank.setPosition({background.getSize().x / 50, background.getSize().y / 70});
    bottomRank.setCharacterSize(background.getSize().x * 4 / 25);
    bottomRank.setPosition({background.getSize().x*24/25, background.getSize().y});

    suit.setScale({background.getSize().x/1000,background.getSize().y/1400}); //_suit size
    suit.setPosition(background.getSize().x*7/25,background.getSize().y*12/35);
}

void DrawableCard::setPosition(sf::Vector2f position) {
    sf::Transformable::setPosition(position);
}

sf::Vector2f DrawableCard::getPosition() {
    return {sf::Transformable::getPosition().x, sf::Transformable::getPosition().y};
}

void DrawableCard::flip() {
    bottomRank.rotate(180);
}

std::string DrawableCard::rankToString() {
    switch(_rank) {
        case ACE: return "A";
        case KING: return "K";
        case QUEEN: return "Q";
        case JACK: return "J";
        default: return std::to_string(_rank+1);
    }
}
std::string DrawableCard::suitToString() {
    switch (_suit) {
        case HEARTS: return "Projects/Applications/images/heart.png";
        case DIAMONDS: return "Projects/Applications/images/diamond.png";
        case CLUBS: return "Projects/Applications/images/clove.png";
        case SPADES: return "Projects/Applications/images/spades.png";
        default: return "Invalid";
    }
}

void DrawableCard::setupBackground() {
    background.setSize({500,700}); //width, length
    background.setPosition({0,0}); // changes rectangle origin
}

void DrawableCard::setupRank() {
    if(!font.loadFromFile("Projects/Applications/fonts/lemon_milk/LEMONMILK-Bold.otf"))
        exit(20); //exit if font doesn't load

    topRank.setFont(font);
    topRank.setString(rankToString());
    topRank.setCharacterSize(background.getSize().x * 4 / 25);
    topRank.setPosition({background.getSize().x / 50, background.getSize().y / 70});

    bottomRank.setFont(font);
    bottomRank.setString(rankToString());
    bottomRank.setCharacterSize(background.getSize().x * 4 / 25);
    bottomRank.setPosition({background.getSize().x * 9/25, background.getSize().y * 5/14});
    flip();
    setFillColor(sf::Color::Black);
}

void DrawableCard::setupSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit(21);
    suit.setTexture(texture);
    suit.setScale({background.getSize().x/1000,background.getSize().y/1400}); //_suit size
    suit.setPosition(background.getSize().x*7/25,background.getSize().y*12/35);
}