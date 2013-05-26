#include "BaseObj.h"

//Move this somewhere else
BoundingBox::BoundingBox(int _x, int _y, int _w, int _h) {
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

void BaseObj::onCollide(BaseObj* b, int direction) {
	return;
}

std::vector<BoundingBox> BaseObj::getBoundingBoxes() {
	std::vector<BoundingBox> empty;
	return empty;
}
