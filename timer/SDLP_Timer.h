#ifndef SDLP_TIMER_H
#define SDLP_TIMER_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <typeinfo>
#include <string>
//Base
#include "../window/SDLP_Window.h"

namespace SDLP {
	class Timer {
	public:
		Timer();
		void Start();
		void Stop();
		void Pause();
		void Unpause();

		int GetTicks();
		bool IsStarted();
		bool IsPaused();

	protected:
		int startTicks;
		int pausedTicks;

		bool paused;
		bool started;
	};
}

#endif 