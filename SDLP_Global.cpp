#include "SDLP_Global.h"
using namespace SDLP;
#define SHITTEST
#ifdef SHITTEST
#endif // SHITTEST

void Global::Init(std::string windowName,int windowW,int windowH)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    //if(IMG_Init(IMG_INIT_PNG) < 0) {
     //   printf( "SDL_image could not initialize! SDL_Error: %s\n", SDL_GetError() );
    //}
    if(TTF_Init() < 0) {
        printf( "SDL_ttf could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    window.Init(windowName.c_str(),windowW,windowH);
    render.Init(&window);
    textureList.Init(render.GetObj());
}

void Global::TestRun()
{
   
}


void Global::DrawText(std::string textString, int x, int y, int w, int h)
{
    SDLP::Surface surf;

}
