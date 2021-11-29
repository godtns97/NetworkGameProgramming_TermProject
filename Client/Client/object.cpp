#include "object.h"

void Object::move()
{
	posX += 10;
	posY += 10;
}
int Object::getPosX()
{
	return posX;
}
int Object::getPosY()
{
	return posY;
}
int Object::getWidth()
{
	return width;
}
int Object::getHeight()
{
	return height;
}