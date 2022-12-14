//
// Created by Raina Wan on 12/13/22.
//

#include "Grid.h"

Grid::Grid() {
    makeGrid();
}

void Grid::makeGrid() {
    for (int i = 0; i < num_rows; ++i) {
        std::vector<Square> row;
        for (int j = 0; j < num_cols; ++j) {
            row.push_back(square);
        }
        board.push_back(row);
    }
}

void Grid::setPosition(const sf::Vector2f &position) {

}

void Grid::setPosition(float x, float y) {

    board[0][0].setPosition({x,y});
    board[1][0].setPosition({0,0});

    for (int i = 1; i < num_rows; ++i) {
        board[0][i].setPosition({board[0][i - 1].getPosition().x + spacing, board[0][i - 1].getPosition().y});
    }
    for (int i = 1; i < num_cols; ++i) {
        board[i][0].setPosition({board[i-1][0].getPosition().x,board[i-1][0].getPosition().y + spacing});
    }
    for (int i = 1; i < num_rows; ++i) {
        for (int j = 1; j < num_cols; ++j) {
            board[i][j].setPosition({board[i-1][j].getPosition().x, board[i][i-1].getPosition().y});
            board[j][i].setPosition({board[i-1][i].getPosition().x, board[j][i-1].getPosition().y});
        }
    }
    ship1.setPosition({board[0][0].getPosition().x + 10, board[0][0].getPosition().y + 250});
    ship2.setPosition({board[0][0].getPosition().x + 125, board[0][0].getPosition().y + 10});
    ship3.setPosition({board[0][0].getPosition().x + 390, board[0][0].getPosition().y + 125});
    ship4.setPosition({board[0][0].getPosition().x + 125, board[0][0].getPosition().y + 500});
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            target.draw(board[i][j]);
        }
    }
    if(hidden.check_sunk(hidden.ship1_life))
        target.draw(ship1);
    if(hidden.check_sunk(hidden.ship2_life))
        target.draw(ship2);
    if(hidden.check_sunk(hidden.ship3_life))
        target.draw(ship3);
    if(hidden.check_sunk(hidden.ship4_life))
        target.draw(ship4);
}

void Grid::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            board[i][j].eventHandler(window, event, SHOWN);
            if (hidden.check_hit(i,j))
                board[i][j].eventHandler(window, event, HIT);
            else
                board[i][j].eventHandler(window, event, MISS);
            if(hidden.check_sunk(hidden.ship1_life))
                board[i][j].eventHandler(window, event, HIDDEN);
        }
    }
}

void Grid::onClick(sf::RenderWindow &window) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if(MouseEvent::isClicked(board[i][j], window)) {
                std::cout << i << " " << j << std::endl;
                if (hidden.check_hit(i, j) && hit[i][j] == false) {
                    is_hit(hidden.ship_hit(i, j));
                    std::cout << "1: " << hidden.ship1_life << std::endl
                              << "2: " << hidden.ship2_life << std::endl
                              << "3: " << hidden.ship3_life << std::endl
                              << "4: " << hidden.ship4_life << std::endl << std::endl;
                    hit[i][j] = true;
                }
            }
        }
    }
}

void Grid::is_hit(std::string ship) {
    if (ship == "1" && hidden.ship1_life != 0)
        hidden.ship1_life -= 1;
    else if (ship == "2" && hidden.ship2_life != 0)
        hidden.ship2_life -= 1;
    else if (ship == "3" && hidden.ship3_life != 0)
        hidden.ship3_life -= 1;
    else if (ship == "4" && hidden.ship4_life != 0)
        hidden.ship4_life -= 1;
}

sf::FloatRect Grid::getGlobalBounds() {
    sf::FloatRect square = board[0][0].getGlobalBounds();
    square.width *= num_cols;
    square.width += 480;
    square.height *= num_rows;
    square.height += 480;
    return square;
}

sf::Vector2f Grid::getPosition() {
    return {board[0][0].getPosition().x, board[0][0].getPosition().y};
}