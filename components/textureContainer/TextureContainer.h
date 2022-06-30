#ifndef TEXTURE_CONTAINER_H
#define TEXTURE_CONTAINER_H

#include "../../ph.h"
#include "../SDLP_BaseComponent.h"
#include "../SDLP_ComponentTypes.h"
#include "../../texture/SDLP_Texture.h"

namespace SDLP {
	namespace Components {
		class TextureContainer : public BaseComponent {
		public:
			TextureContainer();
			TextureContainer(SDLP::Texture* texture, int x, int y) { this->Init(texture, x, y); }
			void Init(SDLP::Texture * texture,int x,int y);

			SDLP::Texture* GetTexture() { return texture; }
			int GetW() { return w; }
			int GetH() { return h; }

		protected:
			SDLP::Texture * texture; //object to render
			int x, y, w, h; //position
		};
	}
}

#endif
