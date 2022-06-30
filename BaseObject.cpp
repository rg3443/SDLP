#include "BaseObject.h"
#include "ph.h"
#include "../pch.h"
//using namespace SDLP;

SDLP::BaseObject::BaseObject()
{
    clonable = false;
    logable = false;
    name = "";
}

void SDLP::BaseObject::__SetClonable(bool clonable)
{
    this->clonable = clonable;
}

void SDLP::BaseObject::__SetObjectName(std::string name)
{
    this->name = name;
}

void SDLP::BaseObject::__SetLogable(bool logable)
{
    this->logable = logable;
}

void SDLP::BaseObject::__LogObject()
{
    Logys logwrt;
    logwrt.open("CreatedObjects.txt");
    std::string objectData = name + "|" + to_string(logable) + "|" + to_string(clonable) + "|" + to_string(getMonth()) + "\n";
    logwrt.write(objectData.c_str());
    logwrt.close();
}
