#include "Table.h"

using namespace SDLP::Components;

Table::Table()
{
    this->_SetType(TABLE);
    this->_SetInput(true);
}

void Table::InsertColumn(std::string name)
{
    //todo: razmer shrifta
    columnList.push_back(name);
    columnWList.push_back(name.size()*20); // col-vo sym * razmer shrifta v pix
    //printf("colsize %d\n", columnWList[columnWList.size() - 1]);
}

void Table::InsertRow(SDLP::Row row)
{
    int dopSize = columnList.size() - row.GetSize();
    //todo: sdelat' bistree cherez setsize vnutri row
    for (int i = 0; i < dopSize; i++) {
        row.InsertData(" ");
    }
    rowList.push_back(row);
}

void Table::Complete()
{
    //calc w
    for(int col=0;col<columnList.size();col++)
    {
        w += columnWList[col];
    }
    rowW = w;
    //calc h
    h = showableRowAmmount * rowH;
}

void Table::SetShowableRowAmmount(int ammount)
{
    showableRowAmmount = ammount;
}

void Table::SetFirstId(int id)
{
    firstId = id;
}

void Table::SetData(std::string data, int x,int y)
{
    if(CheckId(x,y)){
        rowList[y].SetData(data,x);
    }
}

void Table::SetSize(int w,int h)
{
    this->w = w;
    this->h = h;
}

void Table::SetRowW(int rowW)
{
    this->rowW = rowW;
}
void Table::SetRowH(int rowH)
{
    this->rowH = rowH;
}

void Table::SetBackgroundColor(SDL_Color clr)
{
    backgroundColor = clr;
}
void Table::SetTextColor(SDL_Color clr)
{
    textColor = clr;
}
void Table::SetEdgeColor(SDL_Color clr)
{
    edgeColor = clr;
}

std::string Table::GetData(int x,int y)
{
    if(CheckId(x,y)){
        return rowList[y].GetData(x);
    }
}

bool Table::CheckId(int x, int y)
{
    try {
        if(x > -1 || x < columnList.size()+1){
            if(y > -1 || y < rowList.size()+1) {
                return true;
            }
        } else {
            throw "ERROR: data id is wrong\n";
        }
    }
    catch(const char* err) { printf(err); return false; }
}


