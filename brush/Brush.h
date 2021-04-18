#ifndef BRUSH_H_INCLUDED
#define BRUSH_H_INCLUDED

#include <SDL.h>
#include <vector>
#include <string>

namespace SDLP {
    class Brush {
    public:
        Brush() {}
        void Init(SDL_Renderer* render, SDL_Window* window);
    protected:
        SDL_Renderer* render;
        SDL_Window* window;
    };
}

#endif // BRUSH_H_INCLUDED
