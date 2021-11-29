#include "object.h"

void Object::move()
{
	posX += 10;
	posY += 10;
}
int Object::getImg() const
{
	return img;
}
int Object::getPosX() const
{
	return posX;
}
int Object::getPosY() const
{
	return posY;
}
int Object::getWidth() const
{
	return width;
}
int Object::getHeight() const
{
	return height;
}
int Object::getDir() const
{
	return dir;
}