#ifndef SDLP_GLOBAL_H
#define SDLP_GLOBAL_H
#include <vector>
//#include <SDL.h>
//#include <SDL_image.h>
#include "ph.h"


namespace SDLP {
    class Global {
    public:
        Global(){}
        void Init(std::string windowName,int windowW,int windowH);
        void TestRun();
    protected:
        Render render;
        Window window;
        TextureList textureList;
    };
}

#endif // SDLP_GLOBAL_H
