#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "global.h"

class Surface
{
private:
	SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];	//The images that correspond to a keypress
	SDL_Surface* gCurrentSurface = NULL;						//Current displayed image

	SDL_Surface* loadSurface(string path);
	SDL_Surface* screen;
	SDL_Surface* background;

public:
	Surface() {}
	~Surface() {}
};

#endif