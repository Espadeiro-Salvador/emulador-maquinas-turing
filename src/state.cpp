#include <string>
#include <algorithm>
#include "state.hpp"

State::State(std::string name) : _name(name) {}

void State::addTransition(std::string in, Transition transition) {
    std::replace(in.begin(), in.end(), '*', '.');
    if (in.find("$") != std::string::npos) {
        in = in.substr(0, in.find("$")) + "\\" + in.substr(in.find("$"));
    }
    _transitions.push_back(std::make_pair(std::regex(in), transition));
}

const std::string& State::getName() {
    return _name;
}

void State::printState() const {
    for (auto const& y : _transitions) {
        //y.second.printTransition(y.first);
    }
}

bool State::has(std::string in) const {
    for (auto const& y : _transitions) {
        if (std::regex_match(in, y.first)) {
            return true;
        }
    }

    return false;
}

const Transition& State::getTransition(std::string in) {
    for (auto const& y : _transitions) {
        if (std::regex_match(in, y.first)) {
            return y.second;
        }
    }

    return _transitions[0].second;
}
