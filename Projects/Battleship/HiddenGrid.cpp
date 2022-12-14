//
// Created by Raina Wan on 12/13/22.
//

#include "HiddenGrid.h"

bool HiddenGrid::check_hit(int p1, int p2) {
    if (hidden_grid[p1][p2] == 1)
        return true;
    else if (hidden_grid[p1][p2] == 2)
        return true;
    else if (hidden_grid[p1][p2] == 3)
        return true;
    else if (hidden_grid[p1][p2] == 4)
        return true;
    else
        return false;
}

std::string HiddenGrid::ship_hit(int p1, int p2) {
    if (hidden_grid[p1][p2] == 0)
        return "0";
    else if (hidden_grid[p1][p2] == 1)
        return "1";
    else if (hidden_grid[p1][p2] == 2)
        return "2";
    else if (hidden_grid[p1][p2] == 3)
        return "3";
    else if (hidden_grid[p1][p2] == 4)
        return "4";
}

bool HiddenGrid::check_sunk(int ship) const{
    return (ship == 0);
}

bool HiddenGrid::check_all_sunk() {
    if (ship1_life == 0 && ship2_life == 0
        && ship3_life == 0 && ship4_life == 0)
        std::cout << "all sunk" << std::endl;
    return true;
}

