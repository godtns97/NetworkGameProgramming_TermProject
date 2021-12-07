#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdlib.h>
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
const int TANK_VEL = 10;

const int BULLET_SIZE = 4;

#endif