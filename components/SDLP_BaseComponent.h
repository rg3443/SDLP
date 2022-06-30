#ifndef SDLP_BASECOMPONENT_H
#define SDLP_BASECOMPONENT_H

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "../BaseObject.h"
#include "../../pch.h"

namespace SDLP {
    namespace Components {
        class BaseComponent : public SDLP::BaseObject {
        public:
            BaseComponent();
            BaseComponent(int id) { this->_SetId(id); }
            virtual ~BaseComponent() {}

            void _SetId(int val) { id = val; }
            void _SetPosition(int x,int y) { positionX = x; positionY = y; }
            void _SetType(int val) { type = val; }
            void _SetInput(bool val) { input = val; }
            void _SetSize(int w, int h) { this->w = w; this->h = h; }

            int _GetId() { return id; }
            int _GetPositionX() { return positionX; }
            int _GetPositionY() { return positionY; }
            int _GetW() { return w; }
            int _GetH() { return h; }
            int _GetType() { return type; }
            bool _hasInput() { return input; }
            virtual void _Move() {}
        protected:
            int id;
            int w, h;
            int positionX,positionY;
            int type;
            bool input; //if true, cmponent must have w,h fields
        };
    }
}

#endif // SDLP_BASECOMPONENT_H
