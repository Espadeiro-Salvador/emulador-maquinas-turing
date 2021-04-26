#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <string>
#include <vector>
#include <map>

#include "state.hpp"

class StateMachine {
    std::vector<std::string> _strips;
    std::vector<int> _cursors;
    std::map<std::string, State> _states;
    State *_currentState;
    bool _initialState = true;
    
    /* Configs */
    bool _rejectOnAbort = false;
    std::string _onAccept, _onReject;
public:
    StateMachine(std::vector<std::string> strips);
    void setNumberOfStrips(int strips);
    State& addState(std::string name);

    void printStates() const;
    void printStrips() const;

    std::string getIn();
    void run();

    /* Configs */
    void rejectOnAbort();
    void setMessages(std::string onAccept, std::string onReject);
};

#endif /* STATEMACHINE_H */
