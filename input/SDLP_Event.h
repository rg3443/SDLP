#ifndef SDLP_EVENT_H
#define SDLP_EVENT_H

#include "../ph.h"

namespace SDLP {
	class Event {
	public:
		Event();
		Event(int id, int eventFunctionCode) { this->Init(id, eventFunctionCode); }
		void Init(int id, int eventFunctionCode);

		//geters
		int GetId() { return id; }
		int GetEventCode() { return eventFunctionCode; }
	protected:
		int id;
		int eventFunctionCode;
	};
}

#endif
