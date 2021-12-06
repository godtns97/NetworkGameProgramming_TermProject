#include "timer.h"

void Timer::start()
{
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}
void Timer::stop()
{
	started = paused = false;
}
void Timer::pause()
{
	if ((true == started) && (false == paused))
	{
		paused = true;
		paused = SDL_GetTicks() - startTicks;
	}
}
void Timer::unpause()
{
	if (true == paused)
	{
		paused = false;
		startTicks = SDL_GetTicks() - pauseTicks;
		pauseTicks = 0;
	}
}
bool Timer::isStarted() const
{
	return started;
}
bool Timer::isPaused() const
{
	return paused;
}