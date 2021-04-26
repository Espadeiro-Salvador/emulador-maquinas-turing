#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <iostream>

class State;

class Transition {
    State *_dest;
    std::string _move;
    std::string _out;

public:
    Transition(State *dest, std::string move, std::string out);
    void printTransition(std::string in) const;
    std::string getMove() const;
    std::string getOut(std::string in) const;
    State *getNewState() const;
};

#endif /* TRANSITION_H */
