#ifndef H_GAMESTATE
#define H_GAMESTATE
#include "State.h"

class GameState : public State {
	public:
		GameState();
		void update(float);
};
#endif


