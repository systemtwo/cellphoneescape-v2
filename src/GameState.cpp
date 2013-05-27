#include "GameState.h"
#include "Ball.h"
#include "Square.h"
#include "LevelManager.h"
#include "Player.h"

GameState::GameState() {
	name = "GameState";
	//addObj(new Ball());
	//addObj(new Square(100, 100));
	addObj(new LevelManager());
	addObj(new Player(100, 10));
	return;
}

void GameState::update(float dt) {
	State::update(dt);
	return;
}

