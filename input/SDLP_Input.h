#ifndef SDLP_INPUT_H
#define SDLP_INPUT_H

#include "../ph.h"
#include "SDLP_InputGlobals.h"
#include "../menu/SDLP_BaseMenu.h"
#include "../components/SDLP_Components.h"
#include "../framerate/SDLP_Framerate.h"

namespace SDLP {
	class Input {
	public:
		Input();
		void CheckInput(SDLP::BaseMenu * menu,SDLP::Framerate::FramerateCounter * fpsCounter);
		bool MouseOnComponent(SDLP::Components::BaseComponent* component);

		InputRes GetResult() { return result; }
		SDLP::Components::BaseComponent* GetLastPressedComponent();
		void GetMouse(int * x, int * y);
	protected:
		SDL_Event input;
		InputRes result;
		SDLP::Components::BaseComponent* lastPressedComponent;
		int clickPosX, clickPosY;
	};

}

#endif
