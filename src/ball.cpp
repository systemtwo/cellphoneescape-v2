#include "ball.h"
Ball::Ball() {
	circle.setPosition(0,0);
}
void Ball::draw(sf::RenderWindow* window) {
	circle.setRadius(10);
	window->draw(circle);
}

void Ball::update(float dt) {
	circle.move(dt*10, dt*10);
	
	return;
}

