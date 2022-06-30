#include "SDLP_Window.h"
using namespace SDLP;
Window::Window()
{
    object = NULL;
    eternalObject = NULL;
}

void Window::Init(std::string name,int w,int h)
{
    this->name = name;
    object = SDL_CreateWindow(name.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if( object == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    eternalObject = &object;
}
