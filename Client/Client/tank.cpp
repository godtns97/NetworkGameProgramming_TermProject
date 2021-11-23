#include "tank.h"

Tank::Tank(int id, int n, int x, int y):
	Object(n, x * 20, y * 20, TANK_SIZE, TANK_SIZE, TANK_VELOCITY, dir), ID(id), HP(3), reload(2) {}

void Tank::run(int keypress)
{
	if (keypress > 0)
	{
		dir = keypress;
	}
}

int Tank::getID()
{
	return ID;
}

int Tank::getHP()
{
	return HP;
}