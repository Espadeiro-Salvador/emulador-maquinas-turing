.PHONY: clean all

all: emulador

emulador: src/main.cpp src/state.cpp src/transition.cpp src/statemachine.cpp
	g++ -std=c++11 src/main.cpp src/state.cpp src/transition.cpp src/statemachine.cpp -o emulador

clean:
	rm emulador
