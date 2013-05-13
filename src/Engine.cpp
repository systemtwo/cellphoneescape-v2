#include "Engine.h"
Engine::Engine() {
	currState = -1;

	return;
}


Engine& Engine::getInstance() {
	static Engine e;
	return e;
}

void Engine::addState(State* s) {
	states.push_back(s);
	return;
}

void Engine::setState(int stateNum) {
	currState = stateNum;
}

void Engine::addObj(BaseObj* bo) {
	if (states.size() == 0) {
		return;
	} else {
		states[currState]->addObj(bo);
		return;
	}
}

void Engine::draw(sf::RenderWindow* window) {
	if (states.size() == 0) {
		return;
	}
	//Sort by zlevel then draw
	

	states[currState]->draw(window);
	
	
	//Reset the clock
	dt = clock.getElapsedTime();
	clock.restart();
	return;
}

void Engine::update() {
	return;
}

	

