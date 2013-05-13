#ifndef H_ENGINE
#define H_ENGINE

#include <vector>
#include <iostream>
#include <SFML/System.hpp>

#include "State.h"

class Engine {
	public:
		static Engine& getInstance();
		void draw(sf::RenderWindow*);
		void update();
		void addState (State*);
		void setState(int);
		void addObj (BaseObj*);


	private:
		sf::Time dt; //To be fed into update()s
		sf::Clock clock; //the timer
		std::vector<State* > states;
		int currState;

		Engine();


};
#endif
