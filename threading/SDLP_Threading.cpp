#include "SDLP_Threading.h"

using namespace SDLP;

template<typename DataType>
void Thread<DataType>::Create(void (*threadFunction),std::string threadName,DataType functionData)
{
    object = SDL_CreateThread(threadFunction,threadName.c_str(),(void*)functionData);
}

template<typename DataType>
void  Thread<DataType>::Wait()
{
    SDL_WaitThread(object,NULL);
}
