#include "timer.h"

Timer::Timer()
{
	s_ticks = p_ticks = 0;
	started = paused = false;
}

void Timer::start()
{
	started = true;
	paused = false;
	s_ticks = SDL_GetTicks();
}

void Timer::pause()
{
	if ((true == started) && (false == paused))
	{
		paused = true;
		p_ticks = SDL_GetTicks() - s_ticks;
	}
}

void Timer::unpause()
{
	if (true == paused)
	{
		paused = false;
		s_ticks = SDL_GetTicks() - p_ticks;
		p_ticks = 0;
	}
}

int Timer::getTicks()
{
	if (true == started)
	{
		if (true == paused) return p_ticks;
		else return SDL_GetTicks() - s_ticks;
	}
	else return 0;
}

bool Timer::isStarted()
{
	return started;
}

bool Timer::isPaused()
{
	return paused;
}