#include "ball.h"
#include "Engine.h"
Ball::Ball() {
	circle.setPosition(0,0);
	x= 10;
	y=10;
	speed = 100;
}
void Ball::draw(sf::RenderWindow* window) {
	window->draw(circle);
}

void Ball::update(float dt) {
	circle.move(dt*10, dt*10);
	Engine &e= Engine::getInstance();



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		y -= dt*speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		y += dt*speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		x -= dt*speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x += dt*speed;
	}
	circle.setRadius(10);
	circle.setPosition(x,y);
	
	return;
}

