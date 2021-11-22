#include "object.h"

void Object::move(int opt)
{
	posX += opt * dx[dir - 1] * vel;
	posY += opt * dy[dir - 1] * vel;
}

int Object::getNum() const
{
	return num;
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