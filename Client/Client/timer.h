#ifndef _TIMER_H_
#define _TIMER_H_

#include <SDL.h>

class Timer
{
private:
	int		s_ticks;
	int		p_ticks;
	bool	started;
	bool	paused;

public:
	Timer();
	void	start();
	void	pause();
	void	unpause();
	int		getTicks();
	bool	isStarted();
	bool	isPaused();
};

#endif