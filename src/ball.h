#ifndef H_BALL
#define H_BALL

#include <SFML/Graphics.hpp>
#include "BaseObj.h"
class Ball : public BaseObj {
	public:
		void draw(sf::RenderWindow*);
		void update(float);
	private:
};
#endif
