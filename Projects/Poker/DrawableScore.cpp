//
// Created by Raina Wan on 12/13/22.
//

#include "DrawableScore.h"

#include "DrawableScore.h"

sf::Font DrawableScore::font;

DrawableScore::DrawableScore() {

}

DrawableScore::DrawableScore(std::string scorer) : scorer(scorer) {
    initialize();
}

void DrawableScore::initialize() {
    setupBackground();
    setupScore();
}

void DrawableScore::setupBackground() {
    background.setSize({300,500}); //width, length
    background.setPosition({0,0});
}

void DrawableScore::setupScore() {
    if(!font.loadFromFile("Projects/Applications/fonts/lemon_milk/LEMONMILK-Medium.otf"))
        exit(22);
    score_text.setFont(font);
    score_text.setString(scorer);
    score_text.setCharacterSize(100);
    score_text.setPosition({10, 10});
    score_text.setFillColor(sf::Color(204,228,216));
}

void DrawableScore::setPosition(sf::Vector2f position) {
    sf::Transformable::setPosition(position);
}

void DrawableScore::setSize(float size) {
    score_text.setCharacterSize(size);
}

void DrawableScore::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();
    window.draw(score_text, states);
}
