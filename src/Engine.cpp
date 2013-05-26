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

void Engine::processCollisions() {
	for (int i = 0; i < states[currState]->countObjs(); i++) {
		for (int j = (i+1); j < states[currState]->countObjs(); j++) {
			BaseObj* a = states[currState]->getObj(i);
			BaseObj* b = states[currState]->getObj(j);

			//Compare all bounding boxes 
			for (int ai = 0; ai < a->getBoundingBoxes().size(); ai++) {
				BoundingBox aa = a->getBoundingBoxes()[ai];
				for (int bi = 0; bi < b->getBoundingBoxes().size(); bi++) {
					BoundingBox bb = b->getBoundingBoxes()[bi];
					if (((bb.x+bb.w) > (aa.x)) && ((bb.x) < (aa.x)) && (bb.y < (aa.y+aa.h)) && ((bb.y+bb.h) > (aa.y))) {
						//LEFT
						a->onCollide(b, LEFT);
						b->onCollide(a, RIGHT);
					} else if ((bb.x < (aa.x+aa.w)) && ((bb.x+bb.w) > (aa.x+aa.w)) && (bb.y < (aa.y+aa.h)) && ((bb.y+bb.h) > (aa.y))) {
						//right
						a->onCollide(b, RIGHT);
						b->onCollide(a, LEFT);
					}

					if (((bb.y+bb.h) > aa.y) && (bb.y < aa.y) && (bb.x < (aa.x+aa.w)) && ((bb.x+bb.w)> (aa.x))) {
						//up
						a->onCollide(b, UP);
						b->onCollide(a, DOWN);
					} else if (((bb.y) < (aa.y+aa.h)) && ((bb.y+bb.h) > (aa.y+aa.h)) && (bb.x < (aa.x+aa.w)) && ((bb.x+bb.w)> (aa.x))) {
						//down
						a->onCollide(b, DOWN);
						b->onCollide(a, UP);
					}
				}
			}
		}
	}
	return;
}
			

void Engine::update() {
	processCollisions();

	states[currState]->update(dt.asSeconds());
	return;
}

	
int Engine::countStates() {
	return states.size();
}

