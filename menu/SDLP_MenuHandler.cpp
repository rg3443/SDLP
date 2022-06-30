#include "SDLP_MenuHandler.h"

using namespace SDLP;

MenuHandler::MenuHandler()
{
	menuCounter = 0;
	activeMenuId = 0;
	render = nullptr;
	window = nullptr;
	update = false;
}

MenuHandler::~MenuHandler()
{
	for (int i = 0; i < menuList.size(); i++) {
		menuList[i].DestroyAllComponents();
	}
}

void MenuHandler::Init(SDLP::Render* render, SDLP::Window* window,bool SDL_Inited)
{
	// check does base sdl vars was inited and init not inited ones 
	if (!SDL_Inited) {
		SDL_Init(SDL_INIT_EVERYTHING);
		TTF_Init();
		IMG_Init(IMG_INIT_PNG);
	}
	if (window == nullptr) {
		window = new SDLP::Window;
		window->Init("default", 400, 400);
	}
	this->window = window;
	if (render == nullptr) {
		render = new SDLP::Render;
		render->Init(window);
	}
	this->render = render;
	// init menu render
	menuRender.Init(render, window);
	// init fps counter
	fpsCounter.Place();
	fpsCounter.SetFpsCap(60.f);
}

void MenuHandler::AddMenu(SDLP::BaseMenu newMenu)
{
	newMenu.SetId(menuCounter);
	menuList.push_back(newMenu);
}

void MenuHandler::DeleteMenus()
{
	menuList.resize(0);
}

void MenuHandler::Run()
{
		update = false;
		fpsCounter.StartCalculate();
		lastInput.Update();
		input.CheckInput(&menuList[activeMenuId],&fpsCounter);
		if (input.GetResult().type != -1) {
			this->HandleInput(input.GetResult());
			update = true;
		}
		SDL_SetRenderDrawColor(render->GetObj(), 0, 0, 0, 0);
		SDL_RenderClear(render->GetObj());
		menuRender.RenderMenu(&menuList[activeMenuId]);
		render->DrawTextW(CreateRect(0,0,50,50),std::to_string(fpsCounter.GetAvgFps()),CreateColor(255,0,0));
		SDL_RenderPresent(render->GetObj());
		fpsCounter.EndCalculate();
}

void MenuHandler::HandleInput(SDLP::InputRes inputResult)
{
	if (inputResult.type == SDLP::InputType::REDIRECTION) {
		activeMenuId = inputResult.action;
		printf("%d|%d\n", lastInput.type, lastInput.action);
	}
	else if (inputResult.type == SDLP::InputType::EVENT) {
		//todo:do event
		lastInput = inputResult;
	}
	else if (inputResult.type == SDLP::InputType::QUIT) {
		quit = true;
		lastInput = inputResult;
	}
}
