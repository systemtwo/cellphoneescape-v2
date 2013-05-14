#ifndef H_BOT 
#define H_BOT

#include <SFML/Graphics.hpp>
#include "BaseObj.h"
class Bot : public BaseObj {
	public:
		int x;
		int y;

		Bot();
		void draw(sf::RenderWindow*);
		void update(float);

	private:
};
#endif
