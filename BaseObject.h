#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "logs/cLog.h"
#include "../pch.h"

namespace SDLP {
    class BaseObject {
    public:
        BaseObject();

        void __SetClonable(bool clonable);
        void __SetObjectName(std::string name);
        void __SetLogable(bool logable);

        std::string __GetObjectName() { return name; }
        bool __IsClonable() { return clonable; }
        bool __IsLogable() { return logable; }

        void __LogObject();
    protected:
        bool clonable,logable;
        std::string name,creationTime;
    };
}

#endif // BASEOBJECT_H_INCLUDED
