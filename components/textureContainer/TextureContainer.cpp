#include "TextureContainer.h"

using namespace SDLP::Components;

TextureContainer::TextureContainer()
{
	this->__SetClonable(true);
	this->__SetLogable(false);
	this->_SetType(SDLP::Components::Types::TEXTURE_CONTAINER);
}

void TextureContainer::Init(SDLP::Texture* texture, int x, int y)
{
	this->w = texture->GetRect()->w;
	this->h = texture->GetRect()->h;
	this->x = x;
	this->y = y;
	this->texture = texture;
}
