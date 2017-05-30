
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <unistd.h>
#include "ship.h"

using namespace std;

struct LOADLEVEL{
	LOADLEVEL(const int & a, const int & b, const int & tik, const int & speedo)
	{
		y=a;
		x=b;
		time=tik;
		sp = speedo;
	}
	int y;
	int x;
	int time;
	int sp;
};

class CGame {
	public:
		CGame();
		~CGame();
		void runGame();
		void drawMap();
//		void obstacleOut();
		void drawScore();

	private:
		void moveObstacles();
		void deleteObst(const int & i);
		void spawnObstacles();
		void drawSquare(const int & height, 
						const int & width, 
						const int & startY, 
						const int & startX, 
						const char & printChar);
		void startMenu();
//		int mapX,mapY;
		vector<CObstacle> obstacles;
		int c_score, c_cntObst, c_health;
		CTimer cntTime;

		///////////////
		vector<LOADLEVEL> file;
		int fileObjs;
};






#endif