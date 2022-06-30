#ifndef BUTTON_H
#define BUTTON_H

#include "../../ph.h"
#include "../SDLP_BaseComponent.h"
#include "../SDLP_ComponentTypes.h"
#include "../../input/SDLP_InputGlobals.h"
#include "../../../pch.h"

namespace SDLP {
	namespace Components {
		class Button : public BaseComponent {
		public:
			Button();

			void Init(std::string txt, int type,int action,int x,int y,int w,int h,SDL_Color backColor);
			//geters
			std::string GetData() { return dataText; }
			int GetActionType() { return actionType; }
			int GetActionValue() { return actionVal; }
			SDL_Color GetBackgroundColor() { return backgroundColor; }

		protected:
			std::string dataText;
			int actionType,actionVal;
			SDL_Color backgroundColor;
		};
	}
}

#endif
