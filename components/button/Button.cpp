#include "Button.h"

using namespace SDLP::Components;

Button::Button()
{
	this->__SetObjectName("Button");
	this->__SetClonable(false);
	this->__SetLogable(false);
	this->_SetType(SDLP::Components::Types::BUTTON);
	this->_SetInput(true);
}

void Button::Init(std::string txt, int type, int action, int x, int y, int w, int h, SDL_Color backColor)
{
	dataText = txt;
	actionType = type;
	actionVal = action;
	this->_SetPosition(x, y);
	this->_SetSize(w, h);
	backgroundColor = backColor;
}