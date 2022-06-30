#ifndef SDLP_BASEPLACEHOLDER_H
#define SDLP_BASEPLACEHOLDER_H

#include <stdio.h>
#include <vector>
#include <string>
#include "../SDLP_Components.h"
#include "../SDLP_ComponentTypes.h"
#include "../../BaseObject.h"
#include "../../../pch.h"

namespace SDLP {
	namespace Components {
		enum PlaceholderTypes {
			DEFFAULT,
			QUAD
		};
		class PlaceHolder : public BaseComponent {
		public:
			PlaceHolder();
			void AddComponent(SDLP::Components::BaseComponent* component);
			//getters
			SDLP::Components::BaseComponent* GetComponent(int id);
			int GetComponentAmmount() { return componentList.size(); }
			int GetSelfType() { return selftype; }
		protected:
			int selftype;
			vector<SDLP::Components::BaseComponent*> componentList;
		};
	}
}

#endif
