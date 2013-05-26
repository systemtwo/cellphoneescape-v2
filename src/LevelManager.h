#ifndef H_LEVELMANAGER
#define H_LEVELMANAGER

#include "BaseObj.h"

class LevelManager : public BaseObj {
	public:
		LevelManager();
		void update(float);
		void createLevel();
	private:
		int currLevel;
};

#endif
