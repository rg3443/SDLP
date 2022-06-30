#include "SDLP_BaseMenu.h"

using namespace SDLP;

BaseMenu::BaseMenu()
{
    this->__SetClonable(true);
    this->__SetLogable(true);
}

void BaseMenu::AddComponent(Components::BaseComponent* component)
{
    componentList.push_back(component);
}

void BaseMenu::DestroyAllComponents()
{
    for (int i = 0; i < componentList.size(); i++) {
        delete componentList[i];
    }
}

Components::BaseComponent* BaseMenu::GetComponent(int id)
{
    try {
        if(id < 0 || id > componentList.size()) {
                throw "ERROR: wrong menu id\n";
        } else {
            return componentList[id];
        }
    }
    catch(const char* er) { printf(er); }
}
