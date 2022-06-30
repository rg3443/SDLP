#include "SDLP_Timer.h"

using namespace SDLP;

Timer::Timer()
{
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::Start()
{
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
	pausedTicks = 0;
}

void Timer::Stop()
{
	started = false;
	paused = false;
	startTicks = 0;
	pausedTicks = 0;
}

void Timer::Pause()
{
	if (started && !paused) {
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
		startTicks = 0;
	}
}

void Timer::Unpause()
{
	if (started && paused) {
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}

int Timer::GetTicks()
{
	int time = 0;
	if (started) {
		if (paused) {
			time = pausedTicks;
		} else {
			time = SDL_GetTicks() - startTicks;
		}
	}
	return time;
}

bool Timer::IsStarted()
{
	return started;
}

bool Timer::IsPaused()
{
	return paused && started;
}


