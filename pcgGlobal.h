#ifndef PCGGLOBAL_H_INCLUDED
#define PCGGLOBAL_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
//#include <thread>
//#include <mutex>
#include <string.h>
using namespace std;
#include "Windows.h"
//#include "SDL_ttf.h"
 //int SCREEN_H = 150;
// int SCREEN_W = 300;
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
struct cords {
       int x,y;
       cords() {}
       //cords(const cords & crd) { x = crd.x; y = crd.y; }
       cords(int nx,int ny) { x = nx; y = ny; }
       void setcord(int nx, int ny) { x = nx; y = ny; }
};

struct fcords {
       float x,y;
       fcords() {}
       fcords(float nx, float ny) { x = nx; y = ny; }
       void setcord(float nx,float ny) { x = nx; y = ny; }
};

inline bool operator==(const cords & crd1,const cords & crd2)
{
    if(crd1.x == crd2.x && crd1.y == crd2.y)
        return true;
    else
        return false;
}

enum Enemys_id {
     BOMJ

};
/*
enum SRCH_TYPES {
    NOTHING=0,
    NEAR=1,
    EAT=2
};
*/
enum Directions {
    UP=1,DOWN=2,LEFT=3,RIGHT=4,
    CHILL=5
};

inline int opositdir(int direction)
{
    switch(direction)
    {
   	case UP:
	     return DOWN;
    break;
	case DOWN:
	     return UP;
    break;
	case LEFT:
	     return RIGHT;
    break;
	case RIGHT:
	     return LEFT;
    break;
    }
}

enum EButton_types { //OLD AS FUCK DELETE OR REWORK | CURRENT STRUCTURE IS INT GSCENECOMPONENTS_H
	REDBUTT,
	YELLOWBUTT,
	GHOSTBUTT
};

enum ESceneCode { //SCENE CODE WILL GIVE INFO ABOUT WHAT SCENE TO DRAW AND WHAT INPUT TO HANDLE
    TEST_SCENE = 0,
    MAIN_SCENE = 1,
    PERSONSHOW_SCENE = 2,
    GAME_SCENE = 3,
    PAUSE_SCENE = 4,
    SETTINGS_SCENE = 5
};

enum EActionCode {
    // PERSONSHOW_SCENE
    PAGEUP_ACTION,PAGEDOWN_ACTION,

    // TEST_SCENE

    // MAIN_SCENE

    // GAME_SCENE
    MOVEUP_ACTION,MOVEDOWN_ACTION,MOVELEFT_ACTION,MOVERIGHT_ACTION,

    // SETTINGS_SCENE
    SS_BACK,SS_FONTSIZEUP,SS_FONTSIZEDOWN,SS_SOUNDVOLUMEUP,SS_SOUNDVOLUMEDOWN,SS_APPLY
};


inline void inccords(int x, int y, cords * crd) { crd->x = x; crd->y = y; }

inline cords is_in(cords p1, cords p2, cords p3)
{
    if(p3.x > p1.x && p3.x < p2.x && p3.y > p1.y && p3.y < p2.y) return p3;
    else { cords negative(-1,-1); return negative; }
}

inline void printmemory()
{
   MEMORYSTATUS ms;
   GlobalMemoryStatus(&ms);
//   cout << "START MEMORY: " << (ms.dwTotalPhys / 1024 / 1024) << " mb" << endl;
//   cout << "LEFT MEMORY: " << (ms.dwAvailPhys / 1024 / 1024) << " mb" << endl;
}

template<typename T>
inline string to_string(T value)
{
    stringstream ss;
    ss << value;
    string buf = ss.str();
    return buf;
}

template<typename T>
inline int to_int(T value)
{
    stringstream ss;
    ss << value;
    int buf;
    ss >> buf;
    return buf;
}

template<typename T>
inline float to_float(T value)
{
    stringstream ss;
    ss << value;
    float buf;
    ss >> buf;
    return buf;
}

template<typename T>
inline void mnojim(T * value, float proc)
{
     stringstream ss;
     ss << *(value);
     float rez;
     ss >> rez;
     rez = rez / proc;
     stringstream afterpart;
     afterpart << rez;
     afterpart >> *(value);
}

inline int mnojim(int value, float proc)
{
//       printf("\t PROCENT IS %f\nDO %d \t", proc, value);
    stringstream ss;
    ss << value;
    float buf;
    ss >> buf;
    int rez = to_int( to_float(value) * proc );
//    printf("POSLE %d \n", rez);
    return rez;
}

inline int to_negative(int val)
{
    return val-val-val;
}

template<class T>
void copyvector(vector<T> * vec_new, vector<T> vec_to_copy)
{
    vec_new->swap(vec_to_copy);
}

template<class T>
void addtovector(vector<T> * vec, T* object_to_add)
{
    T copy_of_object = *(object_to_add);
    vec->push_back(copy_of_object);
}

#endif // PCGGLOBAL_H_INCLUDED
