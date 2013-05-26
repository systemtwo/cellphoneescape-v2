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
		void setShowCollisions(bool);
		int countStateObjs();



	private:
		static Engine* engine;
		sf::Time dt; //To be fed into update()s
		sf::Clock clock; //the timer
		std::vector<State* > states;
		int currState;
		bool showCollisions;
		std::vector<BoundingBox> collisions;

		Engine();
		void processCollisions();
		void drawCollisions(sf::RenderWindow*);
};
#endif
