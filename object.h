#ifndef OBJECT_H
#define OBJECT_H

//#include "bullet.h"

using namespace std;

class CObject {
	public:
		CObject();
		CObject(const int & oLength);
	//	~CShip();
		void printO()const;
		virtual void clearO()const;
		virtual void moveO();
		
		void buildPart(const int & y,const int & x,const char & part);
	
	//	void newBullet();
	//	void moveBullets();
	//	void bulletHit(vector<CObstacle> & obstacles, int & cntObst, int & c_score);
	//	bool shipHit(vector<CObstacle> & obstacles, int & cntObst);
	private:
		vector<YXPART> parts;
//		vector<CBullet> ammo;
		
	//	int cntBullets;
		int c_objLength;
};






#endif