//
// Created by Raina Wan on 12/13/22.
//

#ifndef PORTFOLIO_HIDDENGRID_H
#define PORTFOLIO_HIDDENGRID_H


#include <iostream>
#include <vector>
#include <string>

class HiddenGrid {
private:
    std::vector<std::vector<int>> hidden_grid {
            {0,2,2,2,2},
            {0,0,0,3,0},
            {1,0,0,3,0},
            {1,0,0,0,0},
            {0,4,4,4,0}
    };
public:
    int ship1_life = 2;
    int ship2_life = 4;
    int ship3_life = 2;
    int ship4_life = 3;
    bool check_hit(int p1, int p2);
    std::string ship_hit(int p1, int p2);
    bool check_sunk(int ship) const;
    bool check_all_sunk();
};



#endif //PORTFOLIO_HIDDENGRID_H
