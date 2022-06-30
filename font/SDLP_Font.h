#ifndef SDLP_FONT_H
#define SDLP_FONT_H

//#include "../ph.h"

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "../BaseObject.h"

namespace SDLP {
    class Font : public BaseObject {
    public:
        Font();
        ~Font();

        void Open(std::string fontPath,int fontSize,SDL_Color fontColor);
        void Close();
        TTF_Font* GetObj() { return object; }

        //seters
        void SetDeafaultColor(SDL_Color color) { defaultColor = color; }
        //geters
        SDL_Color GetDefaultColor() { return defaultColor; }
        int GetDefaultSize() { return defaultSize; }

    protected:
        TTF_Font * object;
        SDL_Color defaultColor;
        int defaultSize;

    };
}

#endif // SDLP_FONT_H
