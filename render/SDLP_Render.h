#ifndef SDLP_RENDER_H
#define SDLP_RENDER_H

#include <SDL.h>
#include "../window/SDLP_Window.h"
#include "../texture/SDLP_Texture.h"

namespace SDLP {
    class Render {
    public:
        Render();
        Render(SDLP::Window window) { this->Init(window); }
        void Init(SDLP::Window window);

        //methods
        void DrawTexture(SDLP::Texture texture,SDL_Rect distRect);


        //setters

        //getters
        SDL_Renderer* GetObj() { return object; }
        SDL_Renderer** GetEternalObject() { return eternalObject; }

    protected:
        SDL_Renderer* object;
        SDL_Renderer** eternalObject;
        SDL_Window** chainedWindow;
        SDLP::Window window;
    };
}

#endif // SDLP_RENDER_H
