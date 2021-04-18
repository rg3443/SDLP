#include "SDLP_Global.h"
using namespace SDLP;

void Global::Init(std::string windowName,int windowW,int windowH)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    if(IMG_Init(IMG_INIT_PNG) < 0) {
        printf( "SDL_image could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    if(TTF_Init() < 0) {
        printf( "SDL_ttf could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    window.Init(windowName.c_str(),windowW,windowH);
    render.Init(window);
    textureList.Init(render.GetObj());
}

void Global::TestRun()
{
    textureList.GetTexture(0)->GetRect()->x = 0;
    textureList.GetTexture(0)->GetRect()->y = 0;
    bool quit = false;
    SDL_Event e;
    while(!quit)
    {
        if(SDL_PollEvent(&e) != 0) {
                printf("i feel input...\n");
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(render.GetObj(),20,20,100,0);
        SDL_RenderClear(render.GetObj());

        for(int y=0;y<200;y++) {
            for(int x=0;x<200;x++) {
                render.DrawTexture(*textureList.GetTexture(0),SDLP::CreateRect(x*10,y*10,10,10));
            }
        }

        //render.DrawTexture(*textureList.GetTexture(0),SDLP::CreateRect(0,0,100,100));
        SDL_RenderPresent(render.GetObj());
    }
}
