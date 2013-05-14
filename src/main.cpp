#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "State.h"
#include "Ball.h"
#include "Bot.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Cell Phone Escape");
	Engine eng = Engine::getInstance();

	State* testState = new State();

	Ball* b = new Ball();
	eng.addState(testState);
	eng.setState(0);

	eng.addObj(new Bot());
	
	



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
		eng.update();
		std::cout << "One loop";
		eng.draw(&window);
		window.display();

	}



	



	return 0;
}
