#include "Player.h"
bool Player::texLoaded = false;
sf::Texture Player::tex;

Player::Player(int _x, int _y) {
	x = _x;
	y = _y;
	yspeed = 0;
	xspeed = 100;
	gravity = 500;
	name = "Player";
	//sprite.setSize(sf::Vector2f(w, h));
	collDown = 0;


	if (!texLoaded) {
		tex.loadFromFile("images/player.png");
		texLoaded = true;
	}

	sprite.setTexture(tex, true);
	w = sprite.getLocalBounds().width;
	h = sprite.getLocalBounds().height;
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
		std::cout << "Go Right" << std::endl;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !leftBlocked) {
		x -= dt*xspeed;
		std::cout << "Go Left" << std::endl;
	}

	sprite.setPosition(x, y);
	//sprite.setFillColor(sf::Color(0,255,255,255));
	falling = true;
	rightBlocked = leftBlocked = false;
	//if (collDown > 0) {
		//y -= collDown;
		//collDown = 0;
	//}
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
		//collDown = dist;
		std::cout << "Pop up" << std::endl;
		y -= (dist);
	}

	if (d == LEFT) {
		leftBlocked = true;
		x += dist;
		std::cout << "COL Left" << std::endl;
	}

	if (d == RIGHT) {
		rightBlocked = true;
		x -= dist;
		std::cout << "COL Right" << std::endl;
	}

	if (d == UP) {
		if (yspeed < 0) {
			//Only push down if the player is moving up
			y += dist;
			yspeed = 0;
		}
	}
	return;
}

std::vector<BoundingBox> Player::getBoundingBoxes() {
	std::vector<BoundingBox> v;
	v.push_back(BoundingBox(x, y, w, h));
	return v;
}
