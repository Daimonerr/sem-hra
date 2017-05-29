#include "ship.h"



CShip::CShip (): cntBullets(0), shipLength(21)
{
	buildPart(40,28,'|');
	buildPart(40,30,'|');

	buildPart(41,27,'/');
	buildPart(41,28,'#');
	buildPart(41,29,'A');
	buildPart(41,30,'#');
	buildPart(41,31,'\\');

	buildPart(42,26,'/');
	buildPart(42,27,'/');
	buildPart(42,28,'O');
	buildPart(42,29,'|');
	buildPart(42,30,'O');
	buildPart(42,31,'\\');
	buildPart(42,32,'\\');

	buildPart(43,26,'^');
	buildPart(43,27,'^');
	buildPart(43,28,'^');
	buildPart(43,29,'^');
	buildPart(43,30,'^');
	buildPart(43,31,'^');
	buildPart(43,32,'^');
}

void CShip::buildPart(const int & Y,const int & X,const char & part)
{
	YXPART tmp;
	tmp.posY=Y;
	tmp.posX=X;
	tmp.partChar=part;
	ship.push_back(tmp);
}

void CShip::printShip()
{
	for (int i = 0; i < shipLength; i++)
	{
		move(ship[i].posY, ship[i].posX);
		addch(ship[i].partChar);
	}
}

void CShip::clearShip()
{
	for (int i = 0; i < shipLength; i++)
	{
		move(ship[i].posY, ship[i].posX);
		addch(' ');
	}
}

void CShip::newBullet()
{
	CBullet tmp(ship[4].posY -1, ship[4].posX);

		ammo.push_back(tmp);
		cntBullets++;
}

void CShip::moveBullets()
{
	for (int i = 0; i < cntBullets; i++)
	{
		if ( ! ammo[i].moveBullet())
		{
			cntBullets--;
			ammo.erase(ammo.begin()+i);
			i--;
		}
	}	


}

void CShip::moveShip()
{
	int direction = getch();

	switch (direction)
	{
		case KEY_UP:
			if (ship[0].posY == 1 )
				break;

			for (int i = 0; i < 21; i++)
			{
				ship[i].posY -= 1;
			}
			break;
		case KEY_DOWN:
			if (ship[14].posY == 44 )
				break;
			for (int i = 0; i < 21; i++)
			{
				ship[i].posY += 1;
			}
			break;
		case KEY_LEFT:
			if (ship[14].posX == 2 )
				break;
			for (int i = 0; i < 21; i++)
			{
				ship[i].posX -= 2;
			}
			break;
		case KEY_RIGHT:
			if (ship[20].posX == 58 )
				break;
			for (int i = 0; i < 21; i++)
			{
				ship[i].posX += 2;
			}
			break;
		case 'f':
			newBullet();
		case 'l':
			return;
	}



}