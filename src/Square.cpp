#include "Square.h"

Square::Square(int _x, int _y) {
	x = _x;
	y = _y;
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
	switch (d) {
		case UP:
			std::cout << "Square: UP" << std::endl;
			break;
		case DOWN:
			std::cout << "Square: DOWN" << std::endl;
			break;
		case RIGHT:
			std::cout << "Square: RIGHT" << std::endl;
			break;
		case LEFT:
			std::cout << "Square: LEFT" << std::endl;
			break;
	}
	return;
}
	
