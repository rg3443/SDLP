#ifndef CGSCENECOMPONENTS_H
#define CGSCENECOMPONENTS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "../../../pcgGlobal.h"
//special types
enum EComponentSpecialType {
    EMPTY,
    DEFAULT
};

//base
class CBaseComponent {
public:
    CBaseComponent() {}

    //methods
    void SetEmpty();
    void SetDefaultColor(bool val) { isDefCol = val; }
    void SetDefaultSize(bool val) { isDefSize = val; }
    void SetDefaultType(bool val) { isDefType = val; }

    //default checks
    bool isDefaultColor() { return isDefCol; }
    bool isDefaultSize() { return isDefSize; }
    bool isDefaultType() { return isDefType; }

protected:
    int type;
    bool isDefSize,isDefCol,isDefType;
};

struct SPoint {
    int x,y;
    SPoint() {}
    SPoint(int x_,int y_) {
        x = x_;
        y = y_;
    }
    void Set(int x_,int y_) {
        x = x_;
        y = y_;
    }
};

struct SRGB {
    int r,g,b;
    SRGB() {}
    SRGB(int r_,int g_, int b_) {
        r = r_;
        g = g_;
        b = b_;
    }
    void Set(int r_,int g_,int b_) {
        r = r_;
        g = g_;
        b = b_;
    }
    void SetEmpty() {
        r = g = b = EMPTY;
    }
    SDL_Color GetSDLColor() {
        SDL_Color clr = {r,g,b,255};
        return clr;
    }
    bool IsEmpty() {
        if(r == EMPTY || g == EMPTY || b == EMPTY) {
//            printf("LOG : rgb structure is empty");
            return true;
        } else {
            return false;

        }
    }
};

struct SFont {
    std::string filePath;
    TTF_Font* object;
    bool iop;//isOPen?
    int size_;

    //constr
    SFont(){}
    ~SFont() {
        this->Close();
    }
    SFont(std::string filePath_,int size__) {
        this->Open(filePath_,size__);
    }

    //methods
    bool isOpen() { return iop; }
    void Open(std::string filePath_,int size__) {
        object = TTF_OpenFont(filePath_.c_str(),size__);
        if( object == NULL )
        {
//            printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        iop = true;
        filePath = filePath_;
        size_ = size__;
    }
    void Close() {
        if(iop) {
            TTF_CloseFont(object);
            object = nullptr;
            iop = false;
        } else {
            SDL_Log("ERROR(CLOSE_ATTEMP) : Font isnt opened!");
        }
    }

};

//components?
//figures
struct SLine {
    SPoint p1,p2;
    SRGB color;
    SLine() {}
    SLine(SPoint p1_,SPoint p2_,SRGB color_) {
        p1 = p1_;
        p2 = p2_;
        color = color_;
    }
};

enum ESquareType {
    FILLED,
    OUTLINED
};

struct SSquare {
    SPoint ulPoint,drPoint;
    int type;
    SRGB inlineColor,outlineColor;
    //
    SSquare() {}
    SSquare(SPoint ulp,SPoint drp,int type_,SRGB inlineColor_,SRGB outlineColor_) {
        ulPoint = ulp;
        drPoint = drp;
        type = type_;
        outlineColor = outlineColor_;
        if(type == FILLED) {
            inlineColor = inlineColor_;
        } else {
            inlineColor.SetEmpty();
        }
    }

    //LEVERAGE
    void Move(int directionCode,int impact) {
        switch(directionCode)
        {
        case RIGHT:
            ulPoint.x += impact;
            drPoint.x += impact;
        break;
        case LEFT:
            ulPoint.x -= impact;
            drPoint.x -= impact;
        break;
        case UP:
            ulPoint.y -= impact;
            drPoint.y -= impact;
        break;
        case DOWN:
            ulPoint.y += impact;
            drPoint.y += impact;
        break;
        }
    }
    bool IsInside(SPoint point) {
        if(point.x > ulPoint.x && point.x < drPoint.x && point.y > ulPoint.y && point.y < drPoint.y) {
//            printf("point is inside\n");
            return true;
        } else {
//            printf("point is outside\n");
            return false;
        }
    }
};


//menu
struct SText {
    std::string text;
    SSquare textField;
    bool defaultFontSize,defaultColor;
    int fontSize;
    SRGB color;
    //
    SText() {}
    SText(std::string text_,int fsize,SRGB color_) { //part constructor
        text = text_;
        color = color_;
        fontSize = fsize;
        defaultFontSize = false;
        defaultColor = false;
    }
    SText(std::string text_,int fsize, SRGB color_,SSquare sqr) { //independent constructor
        text = text_;
        fontSize = fsize;
        color = color_;
        defaultFontSize = false;
        defaultColor = false;
        textField = sqr;
    }

    //SETTERS
    void SetField(SSquare textField_) { textField = textField_; }
    //GETTERS
    SDL_Rect GetSDLRect() {
        SDL_Rect rct;
        rct.x = textField.ulPoint.x;
        rct.y = textField.ulPoint.y;
        rct.w = textField.drPoint.x - textField.ulPoint.x;
        rct.h = textField.drPoint.y - textField.ulPoint.y;
        return rct;
    }

    bool isDefaultSize() { return defaultFontSize; }
    bool isDefaultColor() { return defaultColor; }
};

void PrintSSquare(SSquare sqr);

enum EButtonType {
    INVISIBLE
};
enum ERedirectionType {
    SCENE_DIRECTION,
    ACTION_DIRECTION
};
struct SButton {
    SSquare sqrFld; // square field
    int type; // ERedirectionType
    SText text;
    int directionCode; // ???

    SButton() {}
    SButton(SSquare sqrField_,int type_, SText text_,int directionSceneCode_) {
        sqrFld = sqrField_;
        type = type_;
        text = text_;
        directionCode = directionSceneCode_;
    }
};

struct STableBox {
    SPoint pos;
    vector<vector<SText>> tileMatrix;


    STableBox() {}
    STableBox(SPoint pos_,int columnSize, int rowSize,int tw,int th) {
        pos = pos_;
        int x = 0,y = 0;
        int tileSizeW = tw, tileSizeH=th;
        tileMatrix.resize(columnSize);
        for(int i=0;i<columnSize;i++) {
            tileMatrix[i].resize(rowSize);
            for(int j=0;j<rowSize;j++) {
                SText* tile = &tileMatrix[i][j];
                SSquare txtSqr = SSquare(
                                            SPoint(pos.x+x,pos.y+y),
                                            SPoint((pos.x+tileSizeW)+x,(pos.y+tileSizeH)+y),
                                            OUTLINED,
                                            SRGB(255,0,0),SRGB(255,0,0)
                                          );
                tileMatrix[i][j].textField = txtSqr;
                PrintSSquare(txtSqr);
                x += tileSizeW;
            }
            x = 0;
            y += tileSizeH;
        }
    }
    //GETTERS
    SText GetData(int column,int row) {
        return tileMatrix[row][column];
    }
    SText* GetDataPointer(int column,int row) {
        return &tileMatrix[row][column];
    }
    //SETTERS
    void SetData(int column,int row, SText data) {
        tileMatrix[row][column] = data;
    }


};

struct STableButtonBox {
    SPoint pos;
    vector<SText> columnNames;
    vector< vector<SButton> > buttonMatrix;
    int buttonW,buttonH;
    STableButtonBox() {}
    //todo: нелогично расположены параметры
    STableButtonBox(SPoint pos_,int columnSize,int rowSize,int buttonW_,int buttonH_) {
        pos = pos_;
        buttonW = buttonW_;
        buttonH = buttonH_;
        int xp=0,yp=0;
        columnNames.resize(columnSize);
        buttonMatrix.resize(rowSize);

        for(int j=0;j<columnSize;j++) {
            SSquare clmnsqr = SSquare(
                                      SPoint(pos.x+xp,pos.y+yp),SPoint(pos.x+xp+buttonW,pos.y+yp+buttonH),
                                      OUTLINED,
                                      SRGB(255,0,0),SRGB(255,0,0)
                                      );
            columnNames[j] = SText("",32,SRGB(0,255,255),clmnsqr);
            xp+=buttonW;
        }

        yp+=buttonH;

        for(int row=0;row<rowSize;row++) {
            buttonMatrix[row].resize(columnSize);
            xp = 0;
            for(int column=0;column<columnSize;column++) {
                SSquare sqr(
                                                 SPoint(pos.x+xp,pos.y+yp),
                                                 SPoint(pos.x+xp+buttonW,pos.y+yp+buttonH),
                                                 OUTLINED,
                                                 SRGB(255,0,0),SRGB(255,0,0)
                                                 );
                SButton newBut = SButton(
                                         sqr,
                                         SCENE_DIRECTION,
                                         SText("",32,SRGB(255,0,0),sqr),
                                         -1
                                         );
                buttonMatrix[row][column] = newBut;
                xp += buttonW;
//                //printf("table tile data\n");
                //PrintSSquare(buttonMatrix[row][column].sqrFld);
            }
            yp += buttonH;
        }
    }
    void SetButtonText(SText text,int row, int column) {
        buttonMatrix[row][column].text = text;
        buttonMatrix[row][column].text.textField = buttonMatrix[row][column].sqrFld;
    }
    void SetColumnName(int id, std::string text) {
        columnNames[id].text = text;
    }
    SText GetButtonText(int row, int column) {
        //printf("returning button text\n");
        //printf("text is: %s\n",buttonMatrix[row][column].text);
        return buttonMatrix[row][column].text;
    }
    void PrintData() {
//        printf("\tTABLE DATA\n");
        for(int y=0;y<buttonMatrix.size();y++) {
            for(int x=0;x<buttonMatrix[y].size();x++) {
//                printf("tile x=%d,y=%d has data = %s\n",x,y,buttonMatrix[y][x].text.text.c_str());
            }
        }
    }
};

#include "GTextureCodename.h"
struct STexture {
    int code; //ETextureCodeName
    std::string imgFilePath;
    SSquare imgField;
    SDL_Texture * object;

    STexture() {}
    STexture(int code,std::string imgFilePath_,SSquare imgField_) {
        imgFilePath = imgFilePath_;
        imgField = imgField_;
        //The final texture
        object = NULL;
    }
    SDL_Texture* CreateTexture(SDL_Renderer* render) {
            //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( imgFilePath.c_str() );
        object = SDL_CreateTextureFromSurface( render, loadedSurface );
        SDL_FreeSurface(loadedSurface);
    }
    SDL_Rect GetSDLRect() {
        SDL_Rect rct;
        rct.x = imgField.ulPoint.x;
        rct.y = imgField.ulPoint.y;
        rct.w = imgField.drPoint.x - imgField.ulPoint.x;
        rct.h = imgField.drPoint.y - imgField.ulPoint.y;
        return rct;
    }
};

//functions

inline void PrintSSquare(SSquare sqr)
{
    printf("SQUARE DATA\nX1=%d|Y1=%d\nX2=%d|Y2=%d\n",sqr.ulPoint.x,sqr.ulPoint.y,sqr.drPoint.x,sqr.drPoint.y);
}

#endif // CGSCENECOMPONENTS_H
