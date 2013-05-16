#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "State.h"
#include "GameState.h"
#include "Ball.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Cell Phone Escape");
	Engine& eng = Engine::getInstance();


	State* gameState = new GameState();

	eng.addState(gameState);
	eng.setState(eng.findState("GameState"));
	
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
		eng.draw(&window);
		window.display();

	}
	return 0;
}
