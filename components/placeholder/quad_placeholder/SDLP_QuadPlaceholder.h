#ifndef SDLP_QUADPLACEHOLDER_H
#define SDLP_QUADPLACEHOLDER_H

#include "../SDLP_BasePlaceholder.h"
#include "../../../../pch.h"

namespace SDLP {
	namespace Components {
		class QuadPlaceholder : public SDLP::Components::PlaceHolder {
		public:
			QuadPlaceholder();
			void CalculatePositions();
			void SetInsideFields(int val) { insideFields = val; }
		protected:
			int insideFields;
		};
	}
}

#endif
