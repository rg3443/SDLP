#include "SDLP_Texture.h"
#include <iostream>
using namespace SDLP;

Texture::Texture()
{
    object = nullptr;
    eternalObject = nullptr;
    id = -1;
}

Texture::~Texture()
{
    if (destroyable) {
        SDL_DestroyTexture(object);
        eternalObject = nullptr;
    }
}

void Texture::Init(SDLP::Surface * surface,SDL_Renderer* render,int w,int h)
{
    if (surface->GetType() == SDLP::SurfaceType::TXT) destroyable = true;
    else destroyable = false;

    SDLP::SetRectSize(surface->GetRect(),0,0,w,h);
    this->rect = *(surface->GetRect());
    //if(surface.GetType() != SurfaceType::PNG)
    object = SDL_CreateTextureFromSurface(render,surface->GetObj());
   // else
        //object = SDL_Load
    if(object == nullptr || object == NULL) {
        printf( "Unable to create texture from surface! SDL Error: %s\n", SDL_GetError() );
    }
    eternalObject = &object;
}
