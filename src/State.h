#ifndef H_STATE
#define H_STATE

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "BaseObj.h"
#include "Ball.h"
class State {
	public:
		virtual void draw(sf::RenderWindow*);
		virtual void update(float dt);
		virtual void addObj(BaseObj*);
		Ball* ball_pointer;
		std::string getName();
		
	private:
		std::vector <BaseObj*> objs;
		std::string name;
		void cleanDestroyedObj();

};
#endif
