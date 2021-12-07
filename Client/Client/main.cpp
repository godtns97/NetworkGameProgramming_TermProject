#include "global.h"
#include "surface.h"
#include "tank.h"
#include "timer.h"
#include "client.h"
#include "..\..\Server\Server\protocol.h"

list<Tank> tanks;
Client* client;

Surface& surface = Surface::getInstance();

int myID, cmd, clientNum;

//Starts up SDL and creates window
bool init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("TANK!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = true;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}

		surface.loadImage();
	}

	return success;
}

//Frees media and shuts down SDL
void close()
{
	surface.closeSurface();

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

void handleEvent(bool& quit)
{
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) quit = true;
			// If a key was pressed
			if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP: cmd = 1; break;
				case SDLK_DOWN: cmd = 2; break;
				case SDLK_LEFT: cmd = 3; break;
				case SDLK_RIGHT: cmd = 4; break;
				default: continue;
				}
				client->clientSend(myID, cmd);
			}
			// If a key was released
			else if (e.type == SDL_KEYUP && e.key.repeat == 0)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP: cmd = -1; break;
				case SDLK_DOWN: cmd = -2; break;
				case SDLK_LEFT: cmd = -3; break;
				case SDLK_RIGHT: cmd = -4; break;
				default: continue;
				}
				client->clientSend(myID, cmd);
			}
		}
	}
}

void draw(bool &quit)
{
	Timer timer;
	Timer fps;
	unsigned frame = 0;

	fps.start();
	while (!quit)
	{
		timer.start();
		surface.drawSurface(tanks);
		++frame;

		if (timer.getTicks() * SCREEN_FPS < 1000)
			SDL_Delay(1000 / SCREEN_FPS - timer.getTicks());
		if (fps.getTicks() >= 1000)
		{
			frame = 0;
			fps.start();
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		puts("usage: tank server ip");
		return -1;
	}

	puts("Connecting to server...");
	client = new Client(argv[1]);
	client->clientConnect();
	puts("Server Connected!");
	cout << "myID: " << myID << ", clientNum: " << clientNum << endl;

	if (!init()) cout << "Failed to initalize!\n";
	
	else
	{
		for (int i = 1; i <= clientNum; ++i) tanks.push_back(Tank(i, i - 1, i * 4, 24));

		bool quit = false;

		while (!quit)
		{
			handleEvent(quit);
			draw(quit);
		}
	}

	close();

	return 0;
}