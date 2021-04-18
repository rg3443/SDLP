#include "SDLP_Surface.h"
using namespace SDLP;

Surface::Surface()
{
    object = nullptr;
    eternalObject = nullptr;
    type = -1;
}

void Surface::Init(std::string imgPath, int x,int y, int w, int h,int type)
{
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;
    switch(type)
    {
    case BMP:
        this->_loadBMP(imgPath);
    break;
    case PNG:
        this->_loadPNG(imgPath);
    break;
    }
    eternalObject = &object;
}

void Surface::_loadBMP(std::string imgPath)
{
    object = SDL_LoadBMP(imgPath.c_str());
    if(object == nullptr || object == NULL) {
        printf( "Unable to create surface from image! SDL Error: %s\n", SDL_GetError() );
    }
    //this->_reload();
}

void Surface::_loadPNG(std::string imgPath)
{
    object = IMG_Load(imgPath.c_str());
    if(object == nullptr || object == NULL) {
        printf( "Unable to create surface from image! SDL Error: %s\n", SDL_GetError() );
    }
    //this->_reload();
}

void Surface::_reload()
{
    object->w = rect.w;
    object->h = rect.h;
}
