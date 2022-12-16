//
// Created by Raina Wan on 12/13/22.
//

#include "Card.h"

sf::Texture Card::texture;
sf::Font Card::font;

Card::Card() : Card(HEARTS, ACE){

}

Card::Card(suit_enum suit, rank_enum rank) : _suit(suit), _rank(rank){
    initialize();
}


void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(suit);
    window.draw(rank);
    window.draw(rank2);
}

void Card::setFillColor(const sf::Color &color) {
    if(_suit == HEARTS || _suit == DIAMONDS) {
        rank.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
    }
    if(_suit == SPADES || _suit == CLUBS) {
        rank.setFillColor(sf::Color::Black);
        rank2.setFillColor(sf::Color::Black);
    }

}

void Card::setSize(sf::Vector2f size) {

}

void Card::setSize(float width, float height) {

}

void Card::setPosition(sf::Vector2f position) {
    rank.setPosition({80,60});
    rank2.setPosition(rank.getPosition().x+400, rank.getPosition().y+580);
}

void Card::setPosition(float x, float y) {

}

void Card::flip() {
    rank2.rotate(180);
}

std::string Card::rankToString() {
    switch(_rank) {
        case ACE: return "A";
        case KING: return "K";
        case QUEEN: return "Q";
        case JACK: return "J";
        default: return std::to_string(_rank+1);
    }
}
std::string Card::suitToString() {
    switch (_suit) {
        case HEARTS: return "Projects/Applications/images/heart.png";
        case DIAMONDS: return "Projects/Applications/images/diamond.png";
        case CLUBS: return "Projects/Applications/images/clove.png";
        case SPADES: return "Projects/Applications/images/spades.png";
        default: return "Invalid";
    }
}

std::string Card::getRank() {
    switch(_rank) {
        case ACE: return "ACE";
        case SIX: return "SIX";
        default: return "invalid";
    }
}

std::string Card::getSuit() {
    switch(_suit) {
        case HEARTS: return "HEARTS";
        case DIAMONDS: return "DIAMONDS";
        case CLUBS: return "CLUBS";
        case SPADES: return "SPADES";
        default: return "Invalid";
    }
}

void Card::initialize() {
    setupBackground();
    setupRank();
    setupSuit();
}

void Card::setupBackground() {
    background.setSize({250,350}); //width, length
    background.setScale({2,2}); //changes size of rectangle
    background.setPosition({50,50}); // changes rectangle origin
}

void Card::setupRank() {
    if(!font.loadFromFile("Projects/Applications/fonts/lemon_milk/LEMONMILK-Bold.otf"))
        exit(20); //exit if font doesn't load

    rank.setFont(font);
    rank.setString(rankToString());
    rank.setCharacterSize(80);

    setFillColor(sf::Color::Black);
    setPosition({60,50});
    setPosition(background.getSize());

    rank2.setFont(font);
    rank2.setString(rankToString());
    rank2.setCharacterSize(80);
//    flip();
}

void Card::setupSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit(21);
    suit.setTexture(texture);
    suit.setScale({.5,.5}); //suit size
    suit.setOrigin({5.0,5.0});
    suit.setPosition(suit.getPosition().x + 180,suit.getPosition().y + 250);
}

std::ostream& operator<<(std::ostream& out, const Card& rank) {
    return out << rank;
}