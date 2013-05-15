#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "State.h"
#include "Ball.h"
#include "Bot.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Cell Phone Escape");

	Engine* eng = Engine::getInstance();

	State* testState = new State();

	Ball* b = new Ball();
	eng->addState(testState);
	eng->setState(0);
	b = new Ball();
	eng->addObj(b);
	eng->addObj(new Bot());
	testState->ball_pointer = b;
	std::cout << Engine::getInstance()->getState()->ball_pointer;
	std::cout << "\n" << testState->ball_pointer->x << "\n";
	if (eng == Engine::getInstance()) {
		std::cout << "getInstance works\n";
	}
	if (eng->getState() == Engine::getInstance()->getState()) {
		std::cout << "getState performs the same\n";
	}
	if (eng->getState() == testState) {
		std::cout << "getState performs correctly\n";
	}
	if (eng->getState()->ball_pointer == testState->ball_pointer) {
		std::cout << "ball_pointer performs the same\n";
	}
	std::cout << eng->getState()->ball_pointer << std::endl;
	std::cout << Engine::getInstance()->getState()->ball_pointer->x;
	
	while(window.isOpen()) {
		//Loop thru events
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//Game Loop
		window.clear();
		eng->update();
		eng->draw(&window);
		window.display();

	}
	return 0;
}
