#include "Engine.h"
Engine::Engine() {
	currState = -1;

	return;
}


bool Engine::instanceFlag = false;
Engine* Engine::engine = NULL;
Engine* Engine::getInstance() {
	if(! instanceFlag)
    {
        engine = new Engine();
        instanceFlag = true;
        return engine;
    }
    else
    {
        return engine;
    }
}

int Engine::addState(State* s) {
	states.push_back(s);
	return states.size();
}

void Engine::setState(int stateNum) {
	currState = stateNum;
}
State* Engine::getState() {
	return states[currState];
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
	states[currState]->update(dt.asSeconds());
	return;
}

	


