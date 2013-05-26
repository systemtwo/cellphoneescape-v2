#ifndef H_LEVELMANAGER
#define H_LEVELMANAGER

#include "BaseObj.h"
#include "Engine.h"
#include "Square.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

class LevelManager : public BaseObj {
	public:
		LevelManager();
		void update(float);
		void createLevel();

	private:
		int currLevel;
		int switchToLevel;
		std::vector <BaseObj*> currLevelObjs;
};

#endif
