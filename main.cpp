#include "SDLP_Global.h"
#include <iostream>
#include "factory/Factory.h"
#include "BaseObject.h"

void FactoryTest();

int main(int argc, char* args[])
{

    FactoryTest();
    SDLP::Global sdlGlobal;
    sdlGlobal.Init("test",1400,1400);
    sdlGlobal.TestRun();
}

class TestC {};

void FactoryTest()
{
    try {
        SDLP::PFactory<TestC> coolFactory;
    }
    catch(const char* er) { printf(er); }
}
