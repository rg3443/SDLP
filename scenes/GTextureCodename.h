#ifndef GTEXTURECODENAME_H_INCLUDED
#define GTEXTURECODENAME_H_INCLUDED


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

enum ETextureTypes {
    FIRST_LAYER,
    SECOND_LAYER
};
//TODO:
//сделать так чтобы ините сцен сопоставл€лись CTile и уже н.о. них генерились STexture типо если тип клетки камень то еткстура T_ROCK,
// если на клетке есть обьект, то вз€тьтип обьекта и передать исход€ из типа коднейм текстуре
// если зан€та, то ху€читс€ поверх всего этого существо которое занимает клетку,
// все финито
enum ETextureCodeName {

    //  INTERFACE TEXTURES \\
    //
    T_GAMBLECUBE,

    //  TILE TEXTURES \\
    //FIRST_LAYER
    T_STONE_TILE = 0,
    T_FOREST_TILE = 1,
    T_WATER_TILE = 2,
    //SECOND_LAYER IS OBJECTS
        //NATIVE
        T_TREE,
        T_ROCK,

        //HUMAN MADE
        T_WEAPON,
        T_CHEST,
        T_ARMOR,
        T_FOOD,

};

#endif // GTEXTURECODENAME_H_INCLUDED
