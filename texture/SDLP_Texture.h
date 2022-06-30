#ifndef SDLP_TEXTURE_H
#define SDLP_TEXTURE_H
#include <SDL.h>
#include <stdio.h>
#include "../surface/SDLP_Surface.h"
namespace SDLP {
    class Texture {
    public:
        Texture();
        Texture(SDLP::Surface * surface,SDL_Renderer* render,int w,int h) { this->Init(surface,render,w,h); }
        ~Texture();
        void Init(SDLP::Surface * surface,SDL_Renderer* render,int w,int h);
        //setters
        void SetId(int val) { id = val; }
        //getters
        SDL_Rect* GetRect() { return &rect; }
        SDL_Texture* GetObj() { return object; }
        SDL_Texture** GetEternalObject() { return eternalObject; }
        bool isDestroyable() { return destroyable; }
    protected:
        int id;
        SDL_Rect rect;
        SDL_Texture* object;
        SDL_Texture** eternalObject;
        bool destroyable;
    };
}

#endif // SDLP_TEXTURE_H
