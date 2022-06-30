#ifndef CSCREENSAVER_H_INCLUDED
#define CSCREENSAVER_H_INCLUDED

#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
#include "../cLog.h"
#include "../../pcgGlobal.h"
class CScreenSaver : public SDLP::Logys {
public:
    CScreenSaver() {}
    void setwh(cords wh);
    void setetwh(cords wh);
    void setmasht(fcords masht);
    int getw();
    int geth();
    int getetw();
    int geteth();
    float getmashtx();
    float getmashty();
protected:
    int screenw,screenh;
    float mashtw,mashth;
};

#endif
