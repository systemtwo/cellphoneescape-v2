#ifndef H_BASEOBJ
#define H_BASEOBJ

#include <SFML/Graphics.hpp>
class BaseObj {
	public:
		bool selfDestruct;

		BaseObj();
		virtual void update(float dt);
		virtual void draw(sf::RenderWindow*);

	private:
};
#endif
