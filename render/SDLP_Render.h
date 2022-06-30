#ifndef SDLP_RENDER_H
#define SDLP_RENDER_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <typeinfo>
#include <string>
//Base
#include "../window/SDLP_Window.h"
#include "../texture/SDLP_Texture.h"
//Components
#include "../components/SDLP_BaseComponent.h"
#include "../components/SDLP_ComponentTypes.h"

namespace SDLP {
    class Font;
    namespace Components {}
    class Render {
    public:
        Render();
        Render(SDLP::Window * window) { this->Init(window); }
        void Init(SDLP::Window * window);

        //methods
        void DrawTexture(SDLP::Texture texture,SDL_Rect distRect);
        void DrawComponent(SDLP::Components::BaseComponent * component);//todo1:
        void DrawTextW(SDL_Rect position, std::string text, SDL_Color clr);
        void DrawLine(int x1,int y1, int x2,int y2, SDL_Color clr);
        void DrawFillRect(SDL_Rect rect, SDL_Color clr);
        void DrawOutlineRect(SDL_Rect rect, SDL_Color clr);

        //setters

        //getters
        SDL_Renderer* GetObj() { return object; }
        SDL_Renderer** GetEternalObject() { return eternalObject; }

    protected:
        SDL_Renderer* object;
        SDL_Renderer** eternalObject;
        SDL_Window** chainedWindow;
        SDLP::Window * window;
        TTF_Font * defaultFont;
    };
}

#endif // SDLP_RENDER_H
