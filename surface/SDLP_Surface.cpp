#include "SDLP_Surface.h"
using namespace SDLP;
#include "../font/SDLP_Font.h"

Surface::Surface()
{
    object = nullptr;
    eternalObject = nullptr;
    type = -1;
}

Surface::~Surface()
{
    SDL_FreeSurface(object);
}

void Surface::Free()
{
    SDL_FreeSurface(object);
}

void Surface::Init(std::string imgPath, int x,int y, int w, int h,int type)
{
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;
    this->type = type;
    switch(type)
    {
    case SDLP::SurfaceType::BMP:
        this->_loadBMP(imgPath);
    break;
    case SDLP::SurfaceType::PNG:
        this->_loadPNG(imgPath);
    break;
    }
    eternalObject = &object;
}


void Surface::InitAsText(TTF_Font* font,std::string text,SDL_Rect rect,SDL_Color clr)
{
    this->type = SDLP::SurfaceType::TXT;
    this->rect = rect;
    this->_loadTXT(text,font,clr);
    eternalObject = &object;
}

void Surface::CheckCreation()
{
    if(object == nullptr || object == NULL) {
        printf( "Unable to create surface from image! SDL Error: %s\n", SDL_GetError() );
        system("PAUSE");
    }
}

void Surface::_loadBMP(std::string imgPath)
{
    object = SDL_LoadBMP(imgPath.c_str());
    this->CheckCreation();
    //this->_reload();
}
#include <SDL_image.h>
void Surface::_loadPNG(std::string imgPath)
{
    object = IMG_Load(imgPath.c_str());
    this->CheckCreation();
    //this->_reload();
}
void Surface::_loadTXT(std::string text, TTF_Font* font,SDL_Color clr)
{
    object = TTF_RenderText_Blended(font,text.c_str(),clr);
    this->CheckCreation();
}

void Surface::_reload()
{
    object->w = rect.w;
    object->h = rect.h;
}
