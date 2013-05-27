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
	//Debug (Draw bounding box)
	/*
	sf::RectangleShape r(sf::Vector2f(10,10));
	r.setPosition(x,y);
	r.setFillColor(sf::Color(255,0,0,128));
	window->draw(r);
	r.setPosition(x+20,y+20);
	window->draw(r);
	*/
	//End debug

}

void Ball::update(float dt) {
	circle.move(dt*10, dt*10);
	Engine &e= Engine::getInstance();
	//std::cout << e.countStateObjs();



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

std::vector<BoundingBox> Ball::getBoundingBoxes() {
	std::vector<BoundingBox> v;
	v.push_back(BoundingBox(x, y, 10, 10));
	v.push_back(BoundingBox(x+20, y+20, 10, 10));

	return v;
}

void Ball::onCollide(BaseObj* obj, Direction dir) {
	/*
	switch (dir) {
		case UP:
			std::cout << "UP" << std::endl;
			break;
		case DOWN:
			std::cout << "DOWN" << std::endl;
			break;
		case RIGHT:
			std::cout << "RIGHT" << std::endl;
			break;
		case LEFT:
			std::cout << "LEFT" << std::endl;
			break;
	}
	*/
}

