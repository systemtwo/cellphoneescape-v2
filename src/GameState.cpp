#include "GameState.h"
#include "Ball.h"
#include "Square.h"
#include "LevelManager.h"

GameState::GameState() {
	name = "GameState";
	addObj(new Ball());
	addObj(new Square(100, 100));
	addObj(new LevelManager());
	return;
}

void GameState::update(float dt) {
	State::update(dt);
	return;
}

