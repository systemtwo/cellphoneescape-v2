#include "Ball.h"
void Ball::draw(sf::RenderWindow* window) {
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setPosition(100,100);
	window->draw(circle);
}

void Ball::update(float dt) {
	return;
}

