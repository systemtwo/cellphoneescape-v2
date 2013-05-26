#include "LevelManager.h"

LevelManager::LevelManager() {
	currLevel = -1;
	switchToLevel = 1;
	return;
}

void LevelManager::update(float dt) {
	Engine &eng = Engine::getInstance();
	if (switchToLevel != currLevel) {
		createLevel();
	}
	return;
}

void LevelManager::createLevel() {
	std::cout << "Making level" << std::endl;
	Engine &eng = Engine::getInstance();
	std::cout << eng.countStateObjs();
	int height = 0, width = 0;
	//Parse level from file
	std::ifstream infile;
	
	//Convert level number to string
	std::stringstream ss;
	ss << switchToLevel;

	infile.open("levels/" + ss.str() + ".txt");
	infile >> width >> height;
	std::cout << width << height;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << "Looking at: " << j << " " << i << std::endl;
			int item = 0;
			infile >> item;
			if (item == 1) {
				std::cout << "Making square at: " << j << i << std::endl;
				Square* s = new Square(Square::w*j, Square::h*i);
				currLevelObjs.push_back(s);
				eng.addObj(s);
			}
		}
	}
	currLevel = switchToLevel;

}

