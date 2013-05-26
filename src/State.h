#ifndef H_STATE
#define H_STATE

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "BaseObj.h"
#include "Ball.h"
class State {
	public:
		State();
		virtual void draw(sf::RenderWindow*);
		virtual void update(float dt);
		std::string getName();
		void addObj(BaseObj*);
		int countObjs();
		BaseObj* getObj(int);
		std::vector<BaseObj*>& getAllObjs();
		
	protected:
		std::vector <BaseObj*> objs;
		std::string name;
		void cleanDestroyedObj();

};
#endif
