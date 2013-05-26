#include "Square.h"

Square::Square(int _x, int _y) {
	x = _x;
	y = _y;
	h = 10;
	w = 10;
	rect.setPosition(x, y);
	rect.setSize(sf::Vector2f(w, h));
	return;
}

void Square::update(float dt) {
	return;
}

void Square::draw(sf::RenderWindow* window) {
	window->draw(rect);
}

std::vector <BoundingBox> Square::getBoundingBoxes() {
	std::vector <BoundingBox> v;
	v.push_back(BoundingBox(x, y, w, h));
	return v;
}

void Square::onCollide(BaseObj* obj, Direction d) {
	std::cout << d;
	return;
}
	
