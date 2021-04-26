#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "transition.hpp"
#include "state.hpp"
#include "statemachine.hpp"

std::vector<std::string> imports;

void processInput(std::ifstream &input, StateMachine &stateMachine) {
    std::string line;
    
    while (std::getline(input, line)) {
        if (line.empty() || line[0] == ' ' || line[0] == ';') continue;

        std::stringstream ss(line);

        if (line[0] == '#') {
            std::string modifier;
            ss >> modifier;

            if (modifier == "#reject_on_abort") {
                stateMachine.rejectOnAbort();
            } else if (modifier == "#messages") {
                std::string onAccept, onReject;
                ss >> onAccept >> onReject;
                stateMachine.setMessages(onAccept, onReject);
            } else if (modifier == "#import") {
                std::string import;
                ss >> import;
                if (std::find(imports.begin(), imports.end(), import) == imports.end()) {
                    std::ifstream importFile(import);
                    imports.push_back(import);
                    processInput(importFile, stateMachine);
                }
            } else {
                std::cout << "Aviso: " << modifier << " não está definido." << std::endl;
            }

            continue;
        }
        
        
        std::string state, in, out, move, newState;
        ss >> state >> in >> out >> move >> newState;

        stateMachine.setNumberOfStrips(in.size());
        stateMachine.setNumberOfStrips(out.size());
        stateMachine.setNumberOfStrips(move.size());

        for (auto const &c : move) {
            if (c != 'r' && c != 'l' && c != 's' && c != '*') {
                throw std::runtime_error("Movimento do cursor inválido (Tem que ser r, l, s ou *).");
            }
        }

        if (state == "halt-accept" || state == "halt-reject" || state == "halt") {
            throw std::runtime_error("Os estados halt, halt-accept e halt-reject estão reservados.");
        }

        State &from = stateMachine.addState(state);
        State &to = stateMachine.addState(newState);

        Transition transition(&to, move, out);
        from.addTransition(in, transition);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        std::vector<std::string> strips;
        for (int i = 2; i < argc; ++i) {
            strips.push_back(argv[i]);
        }
        
        StateMachine stateMachine(strips);

        std::ifstream input(argv[1]);
        imports.push_back(argv[1]);
        processInput(input, stateMachine);
        input.close();

        // stateMachine.printStrips();
        // stateMachine.printStates();

        stateMachine.run();
    } else {
        std::cout << "Precisas de passar um ficheiro de texto com a máquina de turing." << std::endl;
    }

    return 0;
}
