#include "SDLP_TextureList.h"
#include "../surface/SDLP_Surface.h"
using namespace SDLP;

TextureList::TextureList()
{
    render = nullptr;
}

void TextureList::Init(SDL_Renderer* render)
{
    this->render = render;
    //test texture
    Surface surf("misc\\icons\\clanFlags\\hardbass.png",0,0,100,100,PNG);
        this->CreateTexture(surf,700,700);
    std::cout << "Test texture with id " << 0 << " was created." << std::endl;
}

int TextureList::CreateTexture(SDLP::Surface surface,int w,int h)
{
    int id = list_.size();
    list_.push_back(Texture(surface,render,w,h));
    list_[id].SetId(id);
    return id;
}

void TextureList::PostInit()
{

}
