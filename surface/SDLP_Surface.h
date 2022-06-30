#ifndef SDLP_SURFACE_H_INCLUDED
#define SDLP_SURFACE_H_INCLUDED
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>

namespace SDLP {
    class Font;
    inline SDL_Rect CreateRect(int x,int y,int w,int h)
    {
        SDL_Rect newRect = { x,y,w,h };
        return newRect;
    }
    inline SDL_Color CreateColor(int r,int g,int b)
    {
        SDL_Color newColor = { r,g,b };
        return newColor;
    }
    inline void SetRectSize(SDL_Rect* rect, int x,int y,int w,int h)
    {
        rect->x = x;
        rect->y = y;
        rect->h = h;
        rect->w = w;
    }
    enum SurfaceType {
        PNG,BMP,TXT
    };
    class Surface {
    public:
        Surface();
        Surface(std::string imgPath,  int x,int y,int w, int h, int type) { this->Init(imgPath,x,y,w,h,type); }
        Surface(TTF_Font * font,std::string text,SDL_Rect rect,SDL_Color clr) { this->InitAsText(font,text,rect,clr); }
        ~Surface();//todo:
        void Free();
        void Init(std::string imgPath,  int x,int y,int w, int h,int type);
        void InitAsText(TTF_Font * font,std::string text,SDL_Rect rect,SDL_Color clr);
        void CheckCreation();
        //getters
        int GetType() { return type; }
        SDL_Surface* GetObj() { return object; }
        SDL_Surface** GetEternalObject() { return eternalObject; }
        SDL_Rect* GetRect() { return &rect; }
    private:
        //methods
        void _loadBMP(std::string imgPath);
        void _loadPNG(std::string imhPath);
        void _loadTXT(std::string text, TTF_Font* font,SDL_Color clr);

        void _reload();

    protected:
        int type;
        SDL_Rect rect;
        SDL_Surface* object;
        SDL_Surface** eternalObject;

    };
}

#endif // SDLP_SURFACE_H_INCLUDED
