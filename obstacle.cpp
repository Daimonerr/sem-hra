#include "obstacle.h"



CObstacle::CObstacle(const int & y, const int & x): health(3), obstLength(6), speed(5)
{
	buildPart(y,x, '#');
	buildPart(y,x+1, '#');
	buildPart(y+1,x, '#');
	buildPart(y+1,x+1, '#');
	buildPart(y,x+2, '#');
	buildPart(y+1,x+2, '#');
}

void CObstacle::printObst()
{
	for (int i = 0; i < obstLength; i++)
		mvaddch(obstObj[i].posY, obstObj[i].posX, obstObj[i].partChar);
	
}

void CObstacle::clearObst()
{
	for (int i = 0; i < obstLength; i++)
		mvaddch(obstObj[i].posY, obstObj[i].posX, ' ');
	
}

bool CObstacle::moveObst(CTimer & cntTime)
{	
	if (cntTime.getMsec() % 33 == 1)
	{	
		if ( isOnEdge() )
			return false;

		clearObst();
		for (int i = 0; i < obstLength; i++)
		{
			obstObj[i].posY += 1;
		}
		printObst();
	}


	return true;
}


void CObstacle::buildPart(const int & Y,const int & X,const char & part)
{
	YXPART tmp;
	tmp.posY=Y;
	tmp.posX=X;
	tmp.partChar=part;
	obstObj.push_back(tmp);
}

bool CObstacle::isOnEdge()
{
	if(obstObj[2].posY == 44)
	{
		clearObst();
		return true;	
	}
	return false;
}