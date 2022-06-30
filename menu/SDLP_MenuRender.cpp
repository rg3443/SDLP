#include "SDLP_MenuRender.h"

using namespace SDLP;

MenuRender::MenuRender()
{
    render = nullptr;
    window = nullptr;
    this->__SetObjectName("MenuRender");
    this->__SetClonable(false);
    this->__SetLogable(true);
}

void MenuRender::Init(Render * render, Window * window)
{
    this->render = render;
    this->window= window;
}

void MenuRender::RenderMenu(BaseMenu * menu)
{
    //for(int )//todo1:
    for (int i = 0; i < menu->GetComponentSize(); i++) {
        render->DrawComponent(menu->GetComponent(i));
    }
}
