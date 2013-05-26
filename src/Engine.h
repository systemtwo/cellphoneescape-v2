#ifndef H_ENGINE
#define H_ENGINE

#include <vector>
#include <iostream>
#include <SFML/System.hpp>

#include "State.h"
#include "Ball.h"

class Engine {
	public:
		static Engine& getInstance();
		void draw(sf::RenderWindow*);
		void update();
		int addState (State*); // Returns length of states
		void setState(int);
		int findState(std::string);
		void addObj (BaseObj*);
		int countStates();



	private:
		static Engine* engine;
		sf::Time dt; //To be fed into update()s
		sf::Clock clock; //the timer
		std::vector<State* > states;
		int currState;

		Engine();
		void processCollisions();
};
#endif
