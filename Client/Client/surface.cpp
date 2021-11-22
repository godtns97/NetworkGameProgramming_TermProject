#define _CRT_SECURE_NO_WARNINGS
#include "surface.h"

SDL_Window* gWindow = NULL;

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
		optimizedImage = SDL_ConvertSurface(loadedimage, screen->format, 0);;
		SDL_FreeSurface(loadedimage);
	}

	return optimizedImage;
}

bool Surface::init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//Create window
	gWindow = SDL_CreateWindow("TANK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Get window surface
		screen = SDL_GetWindowSurface(gWindow);
	}

	char filePath[256];
	for (int i = 0; i < 1; ++i)
	{
		sprintf(filePath, "img/bullet/%d.bmp", i);
		bullet[i] = loadImage(filePath);
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; j++)
		{
			sprintf(filePath, "img/tank/%d-%d.bmp", i, j);
			tank[i][j] = loadImage(filePath);
		}		
	}

	return success;
}

void Surface::close()
{
	for (int i = 0; i < 1; ++i)
	{
		SDL_FreeSurface(bullet[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; j++)
		{
			SDL_FreeSurface(tank[i][j]);
		}
	}

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

void Surface::draw(const list<Tank>& tanks, const list<Bullet>& bullets)
{
	SDL_FillRect(screen, 0, 0U);

	for (auto& b : bullets) applySurface(bullet[b.getNum()], screen, b.getPosX(), b.getPosY());
	for (auto& t : tanks) applySurface(tank[t.getNum()][t.getDir()], screen, t.getPosX(), t.getPosY());

	SDL_UpdateWindowSurface(gWindow);
}