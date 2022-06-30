#ifndef SDLP_INPUTGLOBALS_H
#define SDLP_INPUTGLOBALS_H

#include "../ph.h"

namespace SDLP {
	enum InputType {
		REDIRECTION, EVENT, QUIT
	};
	struct InputRes {
		InputRes() {
			this->Update();
		}
		InputRes(int type_, int action_) {
			type = type_;
			action = action_;
		}
		void Update() {
			type = -1;
			action = -1;
		}
		// if type is redirection - action is menu direction id
		// if type is event - action is event id
		int type, action;
	};
}

#endif
