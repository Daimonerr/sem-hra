#include "GUI.h"

CGame::CGame(): c_score(0), c_cntObst(0)
{
	initscr();
	curs_set(0);
	noecho();

	mvprintw(25,35,"Press any key to start");
	getch();

//	int maxY,maxX;
	keypad(stdscr, true);
//	getmaxyx(stdscr, maxY,maxX);


//-------OKNO PRO VYBRANI LODI


}


CGame::~CGame()
{
	nodelay(stdscr, false);
//	delwin(win);
	endwin();

}

void CGame::runGame()
{

	startMenu();
	clear();
	nodelay(stdscr,true);

	CShip BattleShip;

	CObstacle tmp(2,10);
	obstacles.push_back(tmp);
	CObstacle tmp2(2,20);
	obstacles.push_back(tmp2);

	c_cntObst = 2;

	drawMap();
	

	while(1)
	{

		BattleShip.printShip();

		mvprintw(4,66,"%s", cntTime.printTime().c_str());	
		


		moveObstacles();

		refresh();
		usleep(10000);

//		collision();

//		for (int i = 0; i < c_cntObst; i++)
//			obstacles[i].clearObst();



		//		obst.moveObst(cntTime);

		BattleShip.clearShip();
		BattleShip.moveShip();
		BattleShip.moveBullets();
		BattleShip.bulletHit(obstacles, c_cntObst, c_score);
		drawScore();

		cntTime.addTime();
	//		BattleShip.fire();
		

	}

}


void CGame::drawSquare(const int & height,const int & width, const int & startY, const int & startX, const char & printChar)
{

	attron(A_BOLD);

	for (int i = startY; i < (height+startY); i++)
	{
		mvaddch(i, startX, printChar);
		mvaddch(i, startX+width, printChar);
	}

	for (int i = startX; i < (width+startX+1); i++)
	{
		mvaddch(startY, i, printChar);
		mvaddch(startY+height, i, printChar);
	}

	attroff(A_BOLD);
}
void CGame::startMenu()
{
	drawSquare(45, 60, 0, 0, (char)219);
	attron(A_BOLD);
	mvprintw(10,22,"PRESS ANY KEY TO START");
	attroff(A_BOLD);


	attron(A_UNDERLINE);
	mvprintw(16,5,"SUMMARY:");
	attroff(A_UNDERLINE);

	mvprintw(18,10,"This game is a action-shooter.");
	mvprintw(19,10,"Your main objective is to destroy as many"); 
	mvprintw(20,10,"obstacles as u can and not being hit by them.");					
	mvprintw(21,10,"Game has 10 levels in total.");
	mvprintw(22,10,"Higher levels are going to be harder to survive.");
	mvprintw(23,10,"Each destroyed obstacle highers your score.");
	mvprintw(24,10,"There are randomly spawned bonuses that");
	mvprintw(25,10,"will grant you some kind of a upgrade.");


	attron(A_UNDERLINE);
	mvprintw(27,5,"CONTROLLS:");
	attroff(A_UNDERLINE);

	mvprintw(29,10,"Right Arrow-Key - to move right");
	mvprintw(31,10,"Left Arrow-Key  - to move left");
	mvprintw(33,10,"Upper Arrow-Key - to move up");
	mvprintw(35,10,"Lower Arrow-Key - to move down");
	mvprintw(37,10,"F               - to shoot");
	mvprintw(39,10,"P               - to pause the game");
	
	
	getch();
}


void CGame::drawMap()
{
//----------------------------------VYKRESLENI MAPY
	int score;
	score = 0;

	drawSquare(45, 60, 0, 0, (char)219);
	drawSquare(45, 15, 0, 60, (char)219);

	/*
	for (int i = 0; i<80; i++)
	{
		move (0,i);
		addch(border);
		move (50,i);
		addch(border);
	}
*/
//---------------------------------VYKRESLENI PANELU
	
	attron(A_BOLD);
	attron(A_UNDERLINE);
	mvprintw(3,66,"TIME");
	attroff(A_UNDERLINE);
	mvprintw(9,63,"SCORE: %d", score);
	mvprintw(12,63,"BONUS: %d", score);
	mvprintw(15,63,"SHIP: %d", score);


	attroff(A_BOLD);
	refresh();
}

void CGame::collision()
{

	for (int i = 0; i<c_cntObst; i++)
	{
		if (obstacles[i].isOnEdge())
		{
			c_cntObst--;
			obstacles.erase(obstacles.begin()+i);
			i--;
		}
	}
 
}

void CGame::moveObstacles()
{

	for (int i = 0; i < c_cntObst; i++)
	{
		if( ! obstacles[i].moveObst(cntTime))
		{
			c_cntObst--;
			obstacles.erase(obstacles.begin()+i);
			i--;
		}
	}
}

void CGame::drawScore()
{
	mvprintw(9,70,"%d", c_score);
}