#include "CScreenSaver.h"

void CScreenSaver::setwh(cords wh)
{
     screenw = wh.x;
     screenh = wh.y;
     this->open("logs/SCREENSAVE.txt");
     this->clear();
     stringstream ss1,ss2;
     ss1 << screenw;
     ss2 << screenh;
     string buf = ss1.str() + " : SCREEN_W" + "\n" + ss2.str() + " : SCREEN_H";
     this->write(buf.c_str());
}

void CScreenSaver::setetwh(cords wh)
{
     screenw = wh.x;
     screenh = wh.y;
     this->open("logs/eternalscreen.txt");
     this->clear();
     stringstream ss1,ss2;
     ss1 << screenw;
     ss2 << screenh;
     string buf = ss1.str() + " : SCREEN_W" + "\n" + ss2.str() + " : SCREEN_H";
     this->write(buf.c_str()); 
}

void CScreenSaver::setmasht(fcords masht)
{
     mashtw = masht.x;
     mashth = masht.y;
     this->open("logs/mashtdata.txt");
     this->clear();
     stringstream ss1,ss2;
     ss1 << mashtw;
     ss2 << mashth;
     string buf = ss1.str() + " : SCREEN_mash_W" + "\n" + ss2.str() + " : SCREEN_mash_H";
     this->write(buf.c_str());
}

int CScreenSaver::getw()
{
    this->open("logs/SCREENSAVE.txt");
    string data = this->read(1);
    stringstream ss;
    ss << data;
    ss >> screenw;
    return screenw;    
}

int CScreenSaver::geth() 
{
    this->open("logs/SCREENSAVE.txt");
    string data = this->read(2);
    stringstream ss;
    ss << data;
    ss >> screenh;
    return screenh;     
}

int CScreenSaver::getetw()
{
    this->open("logs/eternalscreen.txt");
    string data = this->read(1);
    stringstream ss;
    ss << data;
    ss >> screenw;
    return screenw;     
     
}

int CScreenSaver::geteth()
{
    this->open("logs/eternalscreen.txt");
    string data = this->read(2);
    stringstream ss;
    ss << data;
    ss >> screenh;
    return screenh;     
     
}

float CScreenSaver::getmashtx()
{
    this->open("logs/mashtdata.txt");
    string data = this->read(1);
    stringstream ss;
    ss << data;
    ss >> mashtw;
    return mashtw;         
}

float CScreenSaver::getmashty()
{
    this->open("logs/mashtdata.txt");
    string data = this->read(2);
    stringstream ss;
    ss << data;
    ss >> mashth;
    return mashth;         
}
