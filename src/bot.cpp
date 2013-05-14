#include <iostream>
#include "ball.h"
#include "bot.h"
Bot::Bot() {
	y=100;
	x=100;
}
void Bot::update(float dt) {
	x++;
	y++;
	std::cout << "updated bot";
	return;
}

void Bot::draw(sf::RenderWindow* window) {
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setPosition(x,y);
	window->draw(circle);
}
