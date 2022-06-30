#include "SDLP_QuadPlaceholder.h"

using namespace SDLP::Components;

QuadPlaceholder::QuadPlaceholder()
{
	this->selftype = QUAD;
}

void QuadPlaceholder::CalculatePositions()
{
	// вычисление высоты и ширины плейсхолдер
	int w = 0, h = 0;
	for (int i = 0; i < componentList.size(); i++) {
		w += componentList[i]->_GetW() + insideFields;
		h += componentList[i]->_GetH() + insideFields;
	}
	// разделение площади плейсхолдера на равные части (равное кол-ву компонентов)
	int
		x = this->_GetPositionX(),
		y = this->_GetPositionY();
	vector<vector<SDL_Rect>> squareMatrix;
	int rectPosX = 0; int rectPosY = 0;
	int componentCounter = 0;
	squareMatrix.resize(componentList.size()/2);
	for (int squareX = 0; squareX < componentList.size() / 2; squareX++) {
		squareMatrix[squareX].resize(componentList.size() / 2);
		for (int squareY = 0; squareY < componentList.size() / 2; squareY++) {
			SDL_Rect rect = squareMatrix[squareX][squareY];
			rect.x = rectPosX;
			rect.y = rectPosY;

			squareMatrix[squareX][squareY] = rect;
			componentCounter++;
			rectPosY += componentList[componentCounter]->_GetH() + insideFields;
		}
		rectPosX += componentList[componentCounter]->_GetW() + insideFields;
	}
	printf("squadmat size %d\n",squareMatrix.size());
	// раздача площадей компонентам
	componentCounter = 0;
	for (int squareX = 0; squareX < componentList.size() / 2; squareX++) {
		for (int squareY = 0; squareY < componentList.size() / 2; squareY++) {
			SDL_Rect rect = squareMatrix[squareX][squareY];
			componentList[componentCounter]->_SetPosition(rect.x,rect.y);
			componentCounter++;
		}
	}

}
