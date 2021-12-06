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
	int		velX, velY;

public:
	Object(int i, int x, int y, int w, int h, int d, int vx, int vy):
		img(i), posX(x), posY(y), width(w), height(h), dir(d), velX(vx), velY(vy) {}
	~Object() {}
	int getImg() const;
	int getPosX() const;
	int getPosY() const;
	int getWidth() const;
	int getHeight() const;
	int getDir() const;
};

#endif