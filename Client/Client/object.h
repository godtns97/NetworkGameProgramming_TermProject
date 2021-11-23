#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "global.h"

class Object
{
protected:
<<<<<<< HEAD
	int			num;
	int			posX, posY;
	int			width, height;
	int			vel, dir;

public:
	Object(int n, int x, int y, int w, int h, int v, int d):
		num(n), posX(x), posY(y), width(w), height(h), vel(v), dir(d) {}
	void move(int opt);
	int getNum() const;
	int getPosX() const;
	int getPosY() const;
	int getWidth() const;
	int getHeight() const;
	int getDir() const;
=======
	int		posX, posY;
	int		width, height;
	int		vel, dir;

public:
	Object(int x, int y, int w, int h, int v, int d):
		posX(x), posY(y), width(w), height(h), vel(v), dir(d) {}
	void	move(int opt);
	int		getPosX();
	int		getPosY();
	int		getWidth();
	int		getHeight();
	int		getDir();
>>>>>>> server
};

#endif