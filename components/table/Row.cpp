#include "Row.h"

using namespace SDLP;

Row::Row()
{

}

void Row::InsertData(std::string data)
{
    this->data.push_back(data);
}

void Row::SetData(std::string data, int id)
{
    try {
        if(id < 0 || id > data.size()) {
            throw "ERROR: row data id is wrong\n";
        } else {
            this->data[id] = data;
        }
    }
    catch(const char* err) { printf(err); }
}

std::string Row::GetData(int id)
{
    try {
        if(id < 0 || id > data.size()) {
            throw "ERROR: row data id is wrong\n";
        } else {
            return data[id];
        }
    }
    catch(const char* err) { printf(err); }
}
