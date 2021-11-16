#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "global.h"

class Object
{
protected:
	int			posX, posY;
	int			width, height;
	int			vel, dir;

public:
	Object(int x, int y, int w, int h, int v, int d):
		posX(x), posY(y), width(w), height(h), vel(v), dir(d) {}
	void move(int opt);
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	int getDir();
};

#endif