#include "SDLP_Font.h"

using namespace SDLP;

Font::Font()
{
    this->__SetObjectName("Font");
    this->__SetClonable(true);
    this->__SetLogable(true);
    this->__LogObject();
}

Font::~Font()
{

}

void Font::Open(std::string fontPath,int fontSize,SDL_Color fontColor)
{
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    //object = TTF_OpenFont(fontPath.c_str(),fontSize);//
    //defaultSize = fontSize;
}

void Font::Close()
{
    TTF_CloseFont(object);
}
