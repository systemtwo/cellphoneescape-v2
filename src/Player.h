#ifndef PLAYER_OBJ
#define PLAYER_OBJ
#include "BaseObj.h"
#include <iostream>
class Player : public BaseObj {
	public:
		Player(int, int);
		void update(float);
		void draw(sf::RenderWindow*);
		void onCollide(BaseObj*, Direction, float);
		std::vector<BoundingBox> getBoundingBoxes();
	private:
		sf::Sprite sprite;
		static sf::Texture tex;
		static bool texLoaded;

		float x, y;
		int w, h;
		int gravity;
		float xspeed, yspeed;
		bool falling;
		bool readyToJump;
		bool leftBlocked, rightBlocked;
		float collDown;
};
#endif
