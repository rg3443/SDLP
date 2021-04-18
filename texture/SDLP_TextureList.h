#ifndef SDLP_TEXTURELIST_H_INCLUDED
#define SDLP_TEXTURELIST_H_INCLUDED

#include <iostream>
#include "SDLP_Texture.h"
#include <SDL.h>
#include <vector>
#include <string>

namespace SDLP {
    class TextureList {
    public:
        TextureList();
        void Init(SDL_Renderer* render);
        //methods
        int CreateTexture(SDLP::Surface surface,int w,int h);// returns created texture id

        //getters
        Texture* GetTexture(int lid) { return &list_[lid]; }
        Texture* GetTextureByGid(int gid);

        //user block
        void PostInit();
    protected:
        SDL_Renderer* render;
        std::vector<Texture> list_;
    };
}

#endif // SDLP_TEXTURELIST_H_INCLUDED
