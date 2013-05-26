#ifndef SQUARE_OBJ
#define SQUARE_OBJ
#include "BaseObj.h"
#include <iostream>

class Square : public BaseObj {
	public:
		Square (int, int);
		void update (float dt);
		void draw(sf::RenderWindow*);
		void onCollide(BaseObj*, Direction);
		std::vector<BoundingBox> getBoundingBoxes();
	private:
		sf::RectangleShape rect;
		float x, y, w, h;
		
};

#endif
