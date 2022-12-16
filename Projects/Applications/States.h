//
// Created by Raina Wan on 12/9/22.
//

#ifndef PORTFOLIO_STATES_H
#define PORTFOLIO_STATES_H

#include <map>
#include <SFML/System/Clock.hpp>
#include "states_enum.h"

namespace gp{
    extern states_enum game_playing;
}


class States {
private:
    std::map<states_enum, bool> map; //<key, value>
    void load();
public:
    States();
    sf::Clock clock;
    bool getState(states_enum state) const;
    void enableState(states_enum state); //will make state true inside map
    void disableState(states_enum state); //will set state to false
    void setState(states_enum state, bool value);
    void toggleState(states_enum state); //change b/w true and false
};


#endif //PORTFOLIO_STATES_H
