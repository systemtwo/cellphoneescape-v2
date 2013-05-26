#ifndef H_BASEOBJ
#define H_BASEOBJ

#include <SFML/Graphics.hpp>

//Move this somewhere else
class BoundingBox {
	public:
		BoundingBox(int, int, int, int);
		int x, y, h, w;
	private:
};


enum Direction {LEFT, RIGHT, UP, DOWN};
class BaseObj {
	public:
		bool selfDestruct;

		BaseObj();
		virtual void update(float dt);
		virtual void draw(sf::RenderWindow*);
		virtual void onCollide(BaseObj*, Direction);
		virtual std::vector<BoundingBox> getBoundingBoxes();
	private:
};
#endif
