#include "BaseObj.h"

//Move this somewhere else
BoundingBox::BoundingBox(float _x, float _y, float _w, float _h) {
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}



BaseObj::BaseObj() {
	selfDestruct = false;
}

void BaseObj::update(float dt) {
	return;
}

void BaseObj::draw(sf::RenderWindow* window) {
	return;
}

void BaseObj::onCollide(BaseObj* b, Direction direction, float dist) {
	return;
}

std::vector<BoundingBox> BaseObj::getBoundingBoxes() {
	std::vector<BoundingBox> empty;
	return empty;
}

std::string BaseObj::getName() {
	return name;
}
