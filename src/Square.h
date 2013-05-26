#ifndef SQUARE_OBJ
#define SQUARE_OBJ
#include "BaseObj.h"
#include <iostream>

class Square : public BaseObj {
	public:
		static const int w = 10;
		static const int h = 10;

		Square (int, int);
		void update (float dt);
		void draw(sf::RenderWindow*);
		void onCollide(BaseObj*, Direction);
		std::vector<BoundingBox> getBoundingBoxes();
	private:
		sf::RectangleShape rect;
		float x, y;
		
};

#endif
