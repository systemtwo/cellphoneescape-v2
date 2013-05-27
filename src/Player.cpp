#include "Player.h"

Player::Player(int _x, int _y) {
	x = _x;
	y = _y;
	w = 16;
	h = 32;
	yspeed = 0;
	xspeed = 100;
	gravity = 500;
	sprite.setSize(sf::Vector2f(w, h));
	return;
}

void Player::update(float dt) {
	if (falling) {
		yspeed += gravity*dt;
	} else {
		yspeed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && readyToJump) {
		readyToJump = false;
		yspeed = -200;
	}

	y += yspeed*dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !rightBlocked) {
		x += dt*xspeed;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !leftBlocked) {
		x -= dt*xspeed;
	}

	sprite.setPosition(x, y);
	sprite.setFillColor(sf::Color(0,255,255,255));
	falling = true;
	rightBlocked = leftBlocked = false;
	return;
}

void Player::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	
	return;
}

void Player::onCollide(BaseObj* obj, Direction d, float dist) {
	if (d == DOWN) {
		falling = false;
		readyToJump = true;
		y -= dist;
	}

	if (d == LEFT) {
		leftBlocked = true;
	}
	if (d == RIGHT) {
		rightBlocked = true;
	}
	return;
}

std::vector<BoundingBox> Player::getBoundingBoxes() {
	std::vector<BoundingBox> v;
	v.push_back(BoundingBox(x, y, w, h));
	return v;
}
