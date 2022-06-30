#include "SDLP_Input.h"

using namespace SDLP;

Input::Input()
{

}

void Input::CheckInput(SDLP::BaseMenu * menu,SDLP::Framerate::FramerateCounter * fpsCounter)
{
	result.action = -1;
	result.type = -1;
	if(SDL_PollEvent(&input) != 0) {
		if (input.type == SDL_QUIT) {
			result = InputRes(SDLP::InputType::QUIT,-1);
		} else if (input.type == SDL_MOUSEBUTTONDOWN) {
			SDL_GetMouseState(&clickPosX,&clickPosY);
			if(menu != nullptr)
			for (int i = 0; i < menu->GetComponentSize(); i++) {
				SDLP::Components::BaseComponent* component = menu->GetComponent(i);
				if (component->_hasInput()) {
					if (this->MouseOnComponent(component)) {
						lastPressedComponent = component;
						printf("component data\n");
						printf("\tx=%d|y=%d\n", lastPressedComponent->_GetPositionX(), lastPressedComponent->_GetPositionY());

						if (component->_GetType() == SDLP::Components::Types::BUTTON) {
							SDLP::Components::Button* button = dynamic_cast<SDLP::Components::Button*>(component);
							result.type = button->GetActionType();
							result.action = button->GetActionValue();
						}
						else if (component->_GetType() == SDLP::Components::Types::TABLE) {
							SDLP::Components::Table* table = dynamic_cast<SDLP::Components::Table*>(component);
						}
					}
				}
			}
		}
		else if (input.type == SDL_MOUSEWHEEL) {
			SDL_GetMouseState(&clickPosX, &clickPosY);
			if (menu != nullptr)
				for (int i = 0; i < menu->GetComponentSize(); i++) {
					SDLP::Components::BaseComponent* component = menu->GetComponent(i);
					if (component->_hasInput()) {
						if (this->MouseOnComponent(component)) {
							if (component->_GetType() == SDLP::Components::Types::BUTTON) {
								SDLP::Components::Button* button = dynamic_cast<SDLP::Components::Button*>(component);
							}
							else if (component->_GetType() == SDLP::Components::Types::TABLE) {
								SDLP::Components::Table* table = dynamic_cast<SDLP::Components::Table*>(component);
								if (input.wheel.y > 0) {
									if(table->GetFirstId() != 0)
									table->SetFirstId(table->GetFirstId() - 1);
								}
								else if (input.wheel.y < 0) {
									if(table->GetFirstId() != (table->GetRowSize()-(table->GetShowableRowAmmount()-1)))
									table->SetFirstId(table->GetFirstId() + 1);
								}
							}
						}
					}
				}
		}
	}
	fpsCounter->Unpause();
}

bool Input::MouseOnComponent(SDLP::Components::BaseComponent* component)
{
	if (clickPosX > component->_GetPositionX() && clickPosX < (component->_GetPositionX() + component->_GetW())) {
		if (clickPosY > component->_GetPositionY() && clickPosY < (component->_GetPositionY() + component->_GetH())) {
			return true;
		}
		else return false;
	}
	else return false;
}

SDLP::Components::BaseComponent* Input::GetLastPressedComponent() 
{
	return lastPressedComponent; 
}

void Input::GetMouse(int* x, int* y)
{
	*x = clickPosX;
	*y = clickPosY;
}
