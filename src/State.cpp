#include "State.h"
#include <iostream>

void State::draw(sf::RenderWindow* window) {
	for (int i = 0; i < objs.size(); i++) {
		objs[i]->draw(window);
	}
		
	return;
}

void State::update(float dt) {
	for (int i = 0; i < objs.size(); i++) {
		objs[i]->update(dt);
	}
	return;
}

void State::addObj(BaseObj* bo) {
	objs.push_back(bo);
	return;
}

//Private methods
void State::cleanDestroyedObj() {
	return;
}