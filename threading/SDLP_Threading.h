#ifndef SDLP_THREADING_H
#define SDLP_THREADING_H

#include "../ph.h"
#include "../BaseObject.h"
#include <SDL_thread.h>

namespace SDLP {
    template<typename DataType>
    class Thread : public BaseObject {
    public:
        Thread();

        void Create(void (*threadFunction),std::string threadName,DataType functionData);
        void Wait();
    protected:
        SDL_Thread* object;
    };
}

#endif // SDLP_THREADING_H
