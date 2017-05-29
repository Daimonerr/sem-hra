#include "bullet.h"

CBullet::CBullet(const int & y, const int & x): c_posY(y), c_posX(x), c_bulletChar('*')
{} 

bool CBullet::moveBullet()
{
	mvaddch(c_posY,c_posX, ' ');
	c_posY -= 1;
	
	if (c_posY == 1)
	{
		mvaddch(c_posY, c_posX, ' ');
		return false;
	}else
		mvaddch(c_posY,c_posX, c_bulletChar);
	return true;
}

//bool CBullet::collision(vector<CObstacle> & obstacles)
//{
//	return false;
//}