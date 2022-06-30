#ifndef SDLP_FRAMERATE_H
#define SDLP_FRAMERATE_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_thread.h>
#include <typeinfo>
#include <string>
//Base
#include "../window/SDLP_Window.h"
//timer
#include "../timer/SDLP_Timer.h"

namespace SDLP {
	namespace Framerate {
		class FramerateCounter {
		public:
			FramerateCounter();
			void Place(); // start calculation
			void StartCalculate(); // process fps calculation( place inside render loop )
			void EndCalculate();
			void Unplace(); // end calcualtion
			void Pause();
			void Unpause();

			void SetFpsCap(float frameCap);

			float GetAvgFps(); // get average frames per second

		protected:
			SDLP::Timer timer,capTimer;
			int countedFrames;
			float averageFps,frameCap;

		};
	}
}

#endif // !SDLP_FRAMERATE_H
