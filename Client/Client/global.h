#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <list>
using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;			// bits-per-pixel
const int SCREEN_FPS = 30;

SDL_Window* gWindow = NULL;						//The window we'll be rendering to
SDL_Surface* gScreenSurface = NULL;				//The surface contained by the window

const int TANK_SIZE = 40;

const int BULLET_SIZE = 4;

#endif