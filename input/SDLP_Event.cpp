#include "SDLP_Event.h"

using namespace SDLP;

void Event::Init(int id, int eventFunctionCode)
{
	this->id = id;
	this->eventFunctionCode = eventFunctionCode;
}
