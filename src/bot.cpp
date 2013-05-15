#include <iostream>
#include <math.h>  
#include "Ball.h"
#include "Bot.h"
#include "Engine.h"
Bot::Bot() {
	y=100;
	x=100;
	speed = 30;
}
void Bot::update(float dt) {
	// float ball_x = 200;
	// float ball_y = 0;
	float delta_x; //How much it moves in the x dir
	float delta_y;
	float ball_x = Engine::getInstance()->getState()->ball_pointer -> x;
	float ball_y = Engine::getInstance()->getState()->ball_pointer -> y;
	float squared_dist = pow((ball_x - x), 2) + pow((ball_y - y), 2);

	if ( ball_y - y != 0) {
		delta_y = std::min(float(speed * dt * pow(( ball_y - y), 2)) / squared_dist, float( abs(ball_y - y)));

	}
	if ( ball_x - x != 0) {
		delta_x = std::min(float(speed * dt * pow(( ball_x - x), 2)) / squared_dist, float( abs(ball_x - x)));
	}
	if (ball_x > x) {
		x += delta_x;
	}
	if (ball_x < x) {
		x -= delta_x;
	}

	if (ball_y > y) {
		y += delta_y;
	}
	if (ball_y < y) {
		y -= delta_y;
	}
	return;
}

void Bot::draw(sf::RenderWindow* window) {
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setPosition(x,y);
	window->draw(circle);
}
