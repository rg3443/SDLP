#ifndef CLOG_H_INCLUDED
#define CLOG_H_INCLUDED

#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
//логирование
//берет любую инфу и запис. в файл

namespace SDLP {
class Logys {
public:
                Logys() {}
                Logys(Logys * new_ob) {}

                void open(const char * path);
                string read(int line); //todo:
                void write(const char * text);
                void clear();
                int sizes();


                void open(const char * path,int specialcode);
                void close() { special_fout.close(); }
                void fast_write(const char * text);
                //void show(); void show(int line);
protected:
                const char * cc_text;
                string s_text;
                string f_path;
                ofstream special_fout;
    //ifstream fin;
};
}


#endif // CLOG_H_INCLUDED
