#ifndef SHIP_H
#define SHIP_H

#include "bullet.h"

using namespace std;

class CShip {
	public:
		CShip();
	//	~CShip();
		void printShip();
		void clearShip();
		void newBullet();
		void moveBullets();
		void moveShip();
	private:
		vector<YXPART> ship;
		vector<CBullet> ammo;
		void buildPart(const int & Y,const int & X,const char & part);

		int cntBullets;
		int shipLength;
};






#endif