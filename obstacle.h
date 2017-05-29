#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>
#include <ncurses.h>
#include "timer.h"

struct YXPART{
	int posY;
	int posX;
	char partChar;
};

class CObstacle {
	public:
		CObstacle(const int & y, const int & x);
		void printObst();
		void clearObst();
		bool moveObst(CTimer & cntTime);
		bool isOnEdge();
	private:
		void buildPart(const int & Y,const int & X,const char & part);
		
		vector<YXPART> obstObj;
		int health;
		int obstLength;
		int speed;
};






#endif