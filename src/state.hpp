#ifndef STATE_H
#define STATE_H

#include <string>
#include <map>
#include <regex>

#include "transition.hpp"

class State {
    std::string _name;
    std::vector<std::pair<std::regex, Transition>> _transitions;

public:
    State(std::string name);
    void addTransition(std::string in, Transition transition);
    const std::string& getName();
    void printState() const;
    bool has(std::string in) const;
    const Transition& getTransition(std::string in);
};

#endif /* STATE_H */
