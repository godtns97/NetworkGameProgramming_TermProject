#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "global.h"
#include "tank.h"

class Surface
{
private:
	Surface() = default;
	~Surface() = default;
	SDL_Surface* loadSurface(string path);
	SDL_Surface* background;
	SDL_Surface* tankSurface[5][5];
	SDL_Surface* bulletSurface[1];

public:
	Surface(Surface&) = delete;
	static Surface& getInstance()
	{
		static Surface instance;
		return instance;
	}
	void loadImage();
	void closeSurface();
	void drawSurface(const list<Tank>& tanks);
};

#endif