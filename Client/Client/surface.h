#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <list>
#include "global.h"
#include "bullet.h"
#include "tank.h"
using std::list;

// 수정 필요!!!

class Surface
{
private:
	Surface() = default;
	~Surface() = default;
	SDL_Surface* loadImage(const char fimeName[]);
	SDL_Surface* screen;
	SDL_Surface* background;
	SDL_Surface* bullet[5];
	SDL_Surface* tank[5][5];

public:
	Surface(Surface&) = delete;
	Surface(Surface&&) = delete;
	static Surface& getInstance()
	{
		static Surface instance;
		return instance;
	}
	bool init();
	void close();
	void draw(const list<Tank>& tanks, const list<Bullet>& bullets);
};

#endif