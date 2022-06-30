#ifndef ROW_H
#define ROW_H

#include "../../ph.h"

namespace SDLP {
    class Row {
    public:
        Row();

        void InsertData(std::string data);

        //seters
        void SetData(std::string data, int id);

        //geters
        std::string GetData(int id);
        int GetSize() { return data.size(); }

    protected:
        std::vector<std::string> data;
    };
}

#endif // ROW_H
