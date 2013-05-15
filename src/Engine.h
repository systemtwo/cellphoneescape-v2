#ifndef H_ENGINE
#define H_ENGINE

#include <vector>
#include <iostream>
#include <SFML/System.hpp>

#include "State.h"

class Engine {
	public:
		static Engine& getInstance() {
			static Engine e;
			return e;
		}
		void draw(sf::RenderWindow*);
		void update();
		void addState (State*);
		void setState(int);
		void addObj (BaseObj*);
		int countObjs();
		void setDummy(int i);
		int getDummy();


	private:
		sf::Time dt; //To be fed into update()s
		sf::Clock clock; //the timer
		std::vector<State* > states;
		int currState;
		int dummy;

		Engine();


};
#endif
