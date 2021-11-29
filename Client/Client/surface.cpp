#include "surface.h"

SDL_Surface* Surface::loadSurface(string path)
{
	SDL_Surface* optimizedSurface = NULL;						//The final optimized image
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());		//Load image at specified path

	if (loadedSurface == NULL)
	{
		cout << "Unable to load image: " << path.c_str() << "! SDL_Error: " << SDL_GetError() << endl;
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			cout << "Unable to optimize image: " << path.c_str() << "! SDL_Error: " << SDL_GetError() << endl;
		}

		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}
void Surface::loadImage()
{
	char path[256];

	for (int i = 0; i < 1; ++i)
	{
		sprintf(path, "image/bullet/%d.bmp", i);
		bulletSurface[i] = loadSurface("path");
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			sprintf(path, "image/tank/%d-%d.bmp", i, j);
			tankSurface[i][j] = loadSurface("path");
		}
	}
}
inline void applySurface(SDL_Surface* src, SDL_Surface* dst, int x, int y)
{
	// src: the SDL_Surface structure to be copied from
	// dst: the SDL_Surface structure that is the blit target
	SDL_Rect offset = { x, y };
	SDL_BlitSurface(src, NULL, dst, &offset);
}
void Surface::closeSurface()
{
	for (int i = 0; i < 1; ++i)
	{
		SDL_FreeSurface(bulletSurface[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			SDL_FreeSurface(tankSurface[i][j]);
		}
	}
}
void Surface::drawSurface(const list<Tank>& tanks)
{
	for (auto& t : tanks)
	{
		applySurface(tankSurface[t.getImg()][t.getDir()], gScreenSurface, t.getPosX(), t.getPosY());
	}

	SDL_UpdateWindowSurface(gWindow);
}