#ifndef CBASESCENE_H_INCLUDED
#define CBASESCENE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#include "../GSDL2.h"
#include "GSceneComponents.h"

class CBaseScene {
public:
    CBaseScene() {}
    void Init();

    //GETTERS
    //data
    std::string GetDescription() { return description; }
    int GetCode() { return code; }
    SLine GetLine(int id) { return lineList[id]; }
    SText GetText(int id) { return textList[id]; }
    SSquare GetSquare(int id) { return squareList[id]; }
    SButton GetButton(int id) { return buttonList[id]; }
    SButton* GetButtonPointer(int id) { return &buttonList[id]; }
    STableBox GetTableBox(int id) { return tableBoxList[id]; }
    STableButtonBox GetTableButtonBox(int id) { return tableButtonBoxList[id]; }
    STexture GetTexture(int id) { return textureList[id]; }

    //sizes
    int GetLineSize( ) { return lineList.size(); }
    int GetTextSize( ) { return textList.size(); }
    int GetSquareSize( ) { return squareList.size(); }
    int GetButtonSize( ) { return buttonList.size(); }
    int GetTableBoxSize( ) { return tableBoxList.size(); }
    int GetTableButtonBoxSize() { return tableButtonBoxList.size(); }
    int GetTextureSize() { return textureList.size(); }

    //boolean
    bool isLineEmpty() {}
    bool isTextEmpty() {}
    bool isSquareEmpty() {}
    bool isButtonEmpty() { if(buttonList.size() == 0) { return true; } else { return false; } }
    bool isTBBXEmpty() { if(tableButtonBoxList.size() == 0) return true; else return false; }
    bool isTextureEmpty() {}

    //SETTERS
    void SetDescription(std::string description) { this->description = description; }
    void SetCode(int code) { this->code = code; }
    void SetLine(SLine val,int id) { lineList[id] = val; }
    void SetText(SText val,int id) { textList[id] = val; }
    void SetSquare(SSquare val,int id) { squareList[id] = val; }
    void SetButton(SButton val,int id) { buttonList[id] = val; }
    void SetTableBox(STableBox val,int id) { tableBoxList[id] = val; }
    void SetTableButtonBox(STableButtonBox val,int id) { tableButtonBoxList[id] = val; }
    void SetTexture(STexture val,int id) { textureList[id] = val; }

    //LEVERAGE
    void AddLine(SLine val) { lineList.push_back(val); }
    void AddText(SText val) { textList.push_back(val); }
    void AddSquare(SSquare val) { squareList.push_back(val); }
    void AddButton(SButton val) { buttonList.push_back(val); }
    void AddTableBox(STableBox val) { tableBoxList.push_back(val); }
    void AddTableButtonBox(STableButtonBox val) { tableButtonBoxList.push_back(val); }
    void AddTexture(STexture val) { textureList.push_back(val); }

protected:
    std::string description;
    int code; // ESceneCode
    vector<SLine> lineList;
    vector<SText> textList;
    vector<SSquare> squareList;
    vector<SButton> buttonList;
    vector<STableBox> tableBoxList;
    vector<STableButtonBox> tableButtonBoxList;
    vector<STexture> textureList;
};

#endif // CBASESCENE_H_INCLUDED
