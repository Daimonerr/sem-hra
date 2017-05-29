
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <unistd.h>
#include "ship.h"

using namespace std;


class CGame {
	public:
		CGame();
		~CGame();
		void runGame();
		void drawMap();
		void collision();

	private:
		void moveObstacles();
//		void spawnObstacles();
		void drawSquare(const int & height, 
						const int & width, 
						const int & startY, 
						const int & startX, 
						const char & printChar);
		void startMenu();
//		int mapX,mapY;
		vector<CObstacle> obstacles;
		int c_score, c_cntObst;
		CTimer cntTime;
};






#endif