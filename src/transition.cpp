#include "transition.hpp"
#include "state.hpp"

Transition::Transition(State *dest, std::string move, std::string out)
    : _dest(dest), _move(move), _out(out) {}

void Transition::printTransition(std::string in) const {
    std::cout << "  " << _dest->getName() << ": " 
        << in << " -> " << _out << ", " << _move << std::endl;
}

std::string Transition::getMove() const {
    return _move;
}

std::string Transition::getOut(std::string in) const {
    std::string out = _out;
    for (size_t i = 0; i < out.size(); i++) {
        if (out[i] == '*') {
            out[i] = in[i];
        }
    }
    return out;
}

State *Transition::getNewState() const {
    return _dest;
}
