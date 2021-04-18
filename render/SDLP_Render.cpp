#include "SDLP_Render.h"
using namespace SDLP;

Render::Render()
{
    object = nullptr;
    eternalObject = nullptr;
    chainedWindow = nullptr;
}

void Render::Init(SDLP::Window window)
{
    this->window = window;
    object = SDL_CreateRenderer(window.GetObj(),-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    eternalObject = &object;
    //this->chainedWindow = window;
}

void Render::DrawTexture(SDLP::Texture texture,SDL_Rect distRect)
{
    SDL_RenderCopy(this->object,texture.GetObj(),texture.GetRect(),&distRect);
}
