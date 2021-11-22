#ifndef _TANK_H_
#define _TANK_H_

#include "object.h"
#include "bullet.h"

class Tank : public Object
{
private:
	int		ID;
	int		HP;
	int		reload;

public:
	Tank(int id, int n, int x, int y);
	void run(int cmd);
	int getID();
	int getHP();
	Bullet shoot()
	{
		Bullet b(0, posX + 10, posY + 10, dir);
		b.move(+1);
		return b;
	}
};

#endif