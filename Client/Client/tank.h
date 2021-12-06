#ifndef _TANK_H
#define _TANK_H

#include "object.h"

class Tank: public Object
{
private:
	int		ID;
	int		HP;

public:
	Tank(int id, int i, int x, int y) :
		Object(i, x, y, TANK_SIZE, TANK_SIZE, 1, TANK_VEL, TANK_VEL), ID(id), HP(3) {}
	~Tank() {}
	void tankMove();
	int getID();
	int getHP();
};

#endif