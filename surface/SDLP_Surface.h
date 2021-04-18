#ifndef SDLP_SURFACE_H_INCLUDED
#define SDLP_SURFACE_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <string>
namespace SDLP {
    inline SDL_Rect CreateRect(int x,int y,int w,int h)
    {
        SDL_Rect newRect = { x,y,w,h };
        return newRect;
    }
    inline void SetRectSize(SDL_Rect* rect, int x,int y,int w,int h)
    {
        rect->x = x;
        rect->y = y;
        rect->h = h;
        rect->w = w;
    }
    enum SurfaceType {
        PNG,BMP
    };
    class Surface {
    public:
        Surface();
        Surface(std::string imgPath,  int x,int y,int w, int h, int type) { this->Init(imgPath,x,y,w,h,type); }
        void Init(std::string imgPath,  int x,int y,int w, int h,int type);
        //getters
        int GetType() { return type; }
        SDL_Surface* GetObj() { return object; }
        SDL_Surface** GetEternalObject() { return eternalObject; }
        SDL_Rect* GetRect() { return &rect; }
    private:
        //methods
        void _loadBMP(std::string imgPath);
        void _loadPNG(std::string imhPath);

        void _reload();

    protected:
        int type;
        SDL_Rect rect;
        SDL_Surface* object;
        SDL_Surface** eternalObject;

    };
}

#endif // SDLP_SURFACE_H_INCLUDED
