#ifndef SDLP_MENUHANDLER_H
#define SDLP_MENUHANDLER_H

#include "../ph.h"
#include "../input/SDLP_Input.h"
#include "../input/SDLP_Event.h"
#include "../framerate/SDLP_Framerate.h"
#include "SDLP_MenuRender.h"
#include "SDLP_BaseMenu.h"

namespace SDLP {
	class MenuHandler {
	public:
		MenuHandler();
		~MenuHandler();

		void Init(
			SDLP::Render* render, 
			SDLP::Window* window, 
			bool SDL_Inited
		);//nullprt for default working\self initialization

		void AddMenu(SDLP::BaseMenu newMenu);
		void DeleteMenus();
		//todo:void AddEvent(void* eventFunction);
		void Run();
		void HandleInput(SDLP::InputRes inputResult);

		//geters
		SDLP::Input* GetInput() { return &input; }
		SDLP::InputRes GetLastInput() { return lastInput; }
		SDLP::Components::BaseComponent* GetLastPressedComponent() { return input.GetLastPressedComponent(); }
		SDLP::Framerate::FramerateCounter* GetFpsCounter() { return &fpsCounter; }
		bool IsUpdate() { return update; }
	protected:
		SDLP::Render* render;
		SDLP::Window* window;
		vector<SDLP::BaseMenu> menuList;
		//todo: vector<SDLP::Event> eventList;
		SDLP::MenuRender menuRender;
		SDLP::Input input;
		int activeMenuId,menuCounter;
		SDLP::InputRes lastInput;
		Framerate::FramerateCounter fpsCounter;
		bool quit,update;
	};
}

#endif
