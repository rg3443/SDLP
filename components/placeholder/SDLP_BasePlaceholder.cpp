#include "SDLP_BasePlaceholder.h"

using namespace SDLP::Components;

PlaceHolder::PlaceHolder()
{
	this->__SetObjectName("PlaceHolder");
	this->__SetClonable(true);
	this->__SetLogable(true);
	this->_SetInput(false);
	this->_SetType(SDLP::Components::Types::PLACEHOLDER);
	selftype = DEFFAULT;
}

void PlaceHolder::AddComponent(SDLP::Components::BaseComponent* component)
{
	componentList.push_back(component);
}

SDLP::Components::BaseComponent* PlaceHolder::GetComponent(int id)
{
	if (id >= 0 || id < componentList.size()) {
		return componentList[id];
	}
}
