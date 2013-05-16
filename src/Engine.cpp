#include "Engine.h"
Engine::Engine() {
	currState = -1;
	return;
}

Engine& Engine::getInstance() {
	static Engine e;
	return e;
}

int Engine::addState(State* s) {
	//Returns the position of the newly added state
	states.push_back(s);
	return states.size() - 1 ;
}

int Engine::findState(std::string name) {
	//Find the position of a state by name
	for (int i = 0; i < states.size(); i++) {
		if (states[i]->getName().compare(name) == 0) {
			return i;
		}
	}
	return -1;
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
	//^ is now state responsibility
	

	states[currState]->draw(window);
	
	
	//Reset the clock
	dt = clock.getElapsedTime();
	clock.restart();
	return;
}

void Engine::update() {
	states[currState]->update(dt.asSeconds());
	return;
}

	
int Engine::countObjs() {
	return states.size();
}

