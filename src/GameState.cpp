#include "GameState.h"
#include "Ball.h"

GameState::GameState() {
	name = "GameState";
	addObj(new Ball());
	return;
}

void GameState::update(float dt) {
	State::update(dt);
	return;
}

