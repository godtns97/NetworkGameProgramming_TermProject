#include "tank.h"

void Tank::tankMove()
{
	posX += velX;
	if ((posX < 0) || (posX + TANK_SIZE > SCREEN_WIDTH)) posX -= velX;

	posY += velY;
	if ((posY < 0) || (posY + TANK_SIZE > SCREEN_HEIGHT)) posY -= velY;
}
int Tank::getID()
{
	return ID;
}
int Tank::getHP()
{
	return HP;
}