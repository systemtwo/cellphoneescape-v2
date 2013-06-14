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
		std::cout << "noState!" << std::endl;
		return;
	} else {
		std::cout << "Added obj" << std::endl;
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

	//Show collision if set
	if (showCollisions) {
		drawCollisions(window);
	}
	
	
	//Reset the clock
	dt = clock.getElapsedTime();
	clock.restart();
	return;
}


void Engine::update() {
	std::cout << "Running at " << 1/dt.asSeconds() << "fps" << std::endl;
	processCollisions();

	states[currState]->update(dt.asSeconds());
	return;
}

int Engine::countStates() {
	return states.size();
}

void Engine::setShowCollisions(bool show) {
	showCollisions = show;
}

int Engine::countStateObjs() {
	if (states.size() == 0) {
		return 0;
	}

	return states[currState]->countObjs();
}

BaseObj* Engine::getObj(std::string name) {
	for (int i = 0; i < countStateObjs(); i++) {
		if (states[currState]->getObj(i)->getName().compare(name) == 0) {
			return states[currState]->getObj(i);
		}
	}
	return NULL;
}

//Private methods

void Engine::processCollisions() {
	//Reset showCollisions collisions vector to nothing
	collisions.erase(collisions.begin(), collisions.end());
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
						a->onCollide(b, LEFT, (bb.x+bb.w)-aa.x);
						b->onCollide(a, RIGHT, (bb.x+bb.w)-aa.x);
						collisions.push_back(aa);
						collisions.push_back(bb);
					} else if ((bb.x < (aa.x+aa.w)) && ((bb.x+bb.w) > (aa.x+aa.w)) && (bb.y < (aa.y+aa.h)) && ((bb.y+bb.h) > (aa.y))) {
						//right
						a->onCollide(b, RIGHT, (aa.x+aa.w)-bb.x);
						b->onCollide(a, LEFT, (aa.x+aa.w)-bb.x);
						collisions.push_back(aa);
						collisions.push_back(bb);
					}

					if (((bb.y+bb.h) > aa.y) && (bb.y < aa.y) && (bb.x < (aa.x+aa.w)) && ((bb.x+bb.w)> (aa.x))) {
						//up
						a->onCollide(b, UP, (bb.y+bb.h)-aa.y);
						b->onCollide(a, DOWN, (bb.y+bb.h)-aa.y);
						collisions.push_back(aa);
						collisions.push_back(bb);
					} else if (((bb.y) < (aa.y+aa.h)) && ((bb.y+bb.h) > (aa.y+aa.h)) && (bb.x < (aa.x+aa.w)) && ((bb.x+bb.w)> (aa.x))) {
						//down
						a->onCollide(b, DOWN, (aa.y+aa.h)-bb.y);
						b->onCollide(a, UP, (aa.y+aa.h)-bb.y);
						collisions.push_back(aa);
						collisions.push_back(bb);
					}
				}
			}
		}
	}
	return;
}

void Engine::drawCollisions(sf::RenderWindow* window) {
	for (int i = 0; i < collisions.size(); i++) {
		BoundingBox b = collisions[i];
		sf::RectangleShape r(sf::Vector2f(b.w, b.h));
		r.setFillColor(sf::Color(255,0,0,128));
		r.setPosition(b.x, b.y);
		window->draw(r);
	}
}



