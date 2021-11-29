#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "global.h"

class Object
{
protected:
	int		img;
	int		posX, posY;
	int		width, height;
	int		dir;

public:
	Object(int i, int x, int y, int w, int h, int d):
		img(i), posX(x), posY(y), width(w), height(h), dir(d) {}
	~Object() {}
	void move();
	int getImg() const;
	int getPosX() const;
	int getPosY() const;
	int getWidth() const;
	int getHeight() const;
	int getDir() const;
};

#endif