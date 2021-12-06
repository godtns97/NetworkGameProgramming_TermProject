#ifndef _TIMER_H
#define _TIMER_H

#include "global.h"

class Timer
{
private:
	int startTicks;
	int pauseTicks;
	bool started;
	bool paused;

public:
	Timer() : startTicks(0), pauseTicks(0), started(false), paused(false) {}
	void start();
	void stop();
	void pause();
	void unpause();
	int getTicks() const;
	bool isStarted() const;
	bool isPaused() const;
};

#endif