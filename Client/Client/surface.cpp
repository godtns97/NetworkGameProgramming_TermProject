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