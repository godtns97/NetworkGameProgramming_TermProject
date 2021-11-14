#include "surface.h"

SDL_Surface* gScreenSurface = NULL;

inline void applySurface(SDL_Surface* src, SDL_Surface* dst, short x, short y)
{
	SDL_Rect offset = { x,y };
	SDL_BlitSurface(src, nullptr, dst, &offset);
}

SDL_Surface* Surface::loadImage(const char fileName[])
{
	SDL_Surface* loadedimage = nullptr;
	SDL_Surface* optimizedImage = nullptr;

	loadedimage = SDL_LoadBMP(fileName);
	if (loadedimage)
	{
		optimizedImage = SDL_ConvertSurface(loadedimage, gScreenSurface->format, 0);;
		SDL_FreeSurface(loadedimage);
	}

	return optimizedImage;
}

void Surface::init()
{
	
}

void Surface::quit()
{

}