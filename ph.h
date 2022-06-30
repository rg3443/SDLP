#ifndef PH_H_INCLUDED
#define PH_H_INCLUDED

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "render/SDLP_Render.h"
#include "window/SDLP_Window.h"
#include "texture/SDLP_Texture.h"
#include "texture/SDLP_TextureList.h"

#ifndef _CRT_SECURE_NO_WARNINGS
    #define _CRT_SECURE_NO_WARNINGS
#endif
namespace SDLP {
template<typename T>
inline std::string to_string(T value)
{
    std::stringstream ss;
    ss << value;
    std::string buf = ss.str();
    return buf;
}

inline void printfrect(SDL_Rect rct) {
    printf("rect data:\nx%d,y%d\nw%d,h%d\n",rct.x,rct.y,rct.w,rct.h);
}


}
#include <ctime>
int getMonth()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int Month = 1 + newtime.tm_mon;
    return Month;
}
#endif // PH_H_INCLUDED
