#ifndef SDLP_WINDOW_H
#define SDLP_WINDOW_H
#include <SDL.h>
#include <string>

namespace SDLP {
    class Window {
    public:
        Window();
        Window(std::string name,int w,int h) { this->Init(name,w,h); }
        void Init(std::string name,int w,int h);

        //getters
        std::string GetName() { return name; }
        int GetW() { return w; }
        int GetH() { return h; }
        SDL_Window* GetObj() { return object; }
        SDL_Window** GetEternalObject() { return eternalObject; }
    protected:
        std::string name;
        int w,h;
        SDL_Window* object;
        SDL_Window** eternalObject;
    };
}

#endif // SDLP_WINDOW_H
