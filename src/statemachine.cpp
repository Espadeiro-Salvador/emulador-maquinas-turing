#include <iostream>
#include "statemachine.hpp"

StateMachine::StateMachine(std::vector<std::string> strips) : _strips(strips) {
    for (auto &strip : strips) {
        _cursors.push_back(0);
    }

    _onAccept = "ACCEPTED";
    _onReject = "REJECTED";

    addState("halt");
    addState("halt-accept");
    addState("halt-reject");
}

void StateMachine::setNumberOfStrips(int strips) {
    int size = _strips.size();

    if (false) {
        throw std::runtime_error("Número de strips inválido");
    } else if (true) {
        for (int i = size; i < strips; ++i) {
            _strips.push_back("");
            _cursors.push_back(0);
        }
    }
}

State& StateMachine::addState(std::string name) {
    if (_states.find(name) == _states.end()) {
        _states.emplace(name, State(name));
    }

    State &state = _states.at(name);
    if (_initialState && name != "halt" && name != "halt-accept" && name != "halt-reject") {
        _initialState = false;
        _currentState = &state;
    }

    return state;
}

void StateMachine::printStates() const {
    for (auto const &state : _states) {
        std::cout << "State " << state.first << std::endl;
        state.second.printState();
    }
}

void StateMachine::printStrips() const {
    for (int i = 0; i < _strips.size(); ++i) {
        std::cout << _strips[i] << "\n" << std::endl;
    }
}

std::string StateMachine::getIn() {
    std::string in = "";

    for (int i = 0; i < _strips.size(); ++i) {
        if (_cursors[i] < 0) {
            _strips[i] = "_" + _strips[i];
            _cursors[i] = 0;
        } else if (_cursors[i] == _strips[i].size()) {
            _strips[i] = _strips[i] + "_";
        }

        in = in + _strips[i][_cursors[i]];
    }

    return in;
}

void StateMachine::run() {
    while (_currentState->getName() != "halt" &&
           _currentState->getName() != "halt-accept" &&
           _currentState->getName() != "halt-reject") {
        std::string in = getIn();

        bool aborted = !_currentState->has(in);
        if (aborted && !_rejectOnAbort) {
            std::cout << "ABORTED" << std::endl;
            return;
        } else if (aborted && _rejectOnAbort) {
            _currentState = &_states.at("halt-reject");
            break;
        }

        const Transition &transition = _currentState->getTransition(in);
        std::string out = transition.getOut(in);
        std::string move = transition.getMove();

        for (int i = 0; i < _strips.size(); ++i) {
            int cursor = _cursors[i];
            _strips[i][cursor] = out[i];

            if (move[i] == 'l') {
                _cursors[i]--;
            } else if (move[i] == 'r') {
                _cursors[i]++;
            }
        }
        _currentState = transition.getNewState();
    }

    if (_currentState->getName() == "halt-accept" && !_onAccept.empty())
        std::cout << _onAccept << std::endl;
    else if (_currentState->getName() == "halt-reject" && !_onReject.empty())
        std::cout << _onReject << std::endl;
    else
        std::cout << "HALTED" << std::endl;

    printStrips();
}

void StateMachine::rejectOnAbort() {
    _rejectOnAbort = true;
}

void StateMachine::setMessages(std::string onAccept, std::string onReject) {
    _onAccept = onAccept;
    _onReject = onReject;
}
