#ifndef TABLE_H
#define TABLE_H

#include "../../ph.h"
#include "../SDLP_BaseComponent.h"
#include "Row.h"
#include "../SDLP_ComponentTypes.h"

namespace SDLP {
    namespace Components {
        class Table : public BaseComponent {
        public:
            Table();

            void InsertColumn(std::string name);
            void InsertRow(SDLP::Row row);
            void Complete(); // calculate sizes

            //seters
            void SetShowableRowAmmount(int ammount);
            void SetFirstId(int id);
            void SetData(std::string data, int x, int y);
            void SetSize(int w, int h);
            void SetRowW(int rowW);
            void SetRowH(int rowH);
            void SetBackgroundColor(SDL_Color clr);
            void SetTextColor(SDL_Color clr);
            void SetEdgeColor(SDL_Color clr);

            //geters
            int GetShowableRowAmmount() { return showableRowAmmount; }
            int GetFirstId() { return firstId; }
            std::string GetData(int x,int y);
            std::string GetColumnText(int i) { return columnList[i]; }
            SDLP::Row GetRow(int idy);
            int GetColW(int colID) { return columnWList[colID]; }
            int GetRowW() { return rowW; }
            int GetRowH() { return rowH; }
            int GetRowSize() { return rowList.size(); }
            int GetColumnSize() { return columnList.size(); }
            SDL_Color GetBackgroundColor() { return backgroundColor; }
            SDL_Color GetTextColor() { return textColor; }
            SDL_Color GetEdgeColor() { return edgeColor; }

            bool CheckId(int x, int y);

        protected:
            int showableRowAmmount;
            int firstId;
            int rowW,rowH;
            std::vector<int> columnWList;
            std::vector<std::string> columnList;
            std::vector<SDLP::Row> rowList;
            SDL_Color backgroundColor,textColor,edgeColor;
        };
    }
}

#endif // TABLE_H
