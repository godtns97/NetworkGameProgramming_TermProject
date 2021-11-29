#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "global.h"

class Object
{
protected:
	int		ID;
	int		posX, posY;
	int		width, height;

public:
	Object(int id, int x, int y, int w, int h):
		ID(id), posX(x), posY(y), width(w), height(h) {}
	~Object() {}
	void move();
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
};

#endif