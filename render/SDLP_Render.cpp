#include "SDLP_Render.h"
using namespace SDLP;

#include "../components/table/Table.h"
#include "../components/textureContainer/TextureContainer.h"
#include "../components/button/Button.h"
#include "../components/placeholder/SDLP_BasePlaceholder.h"
#include "../components/placeholder/quad_placeholder/SDLP_QuadPlaceholder.h"
#include "../font/SDLP_Font.h"

Render::Render()
{
    object = nullptr;
    eternalObject = nullptr;
    chainedWindow = nullptr;
}

void Render::Init(SDLP::Window * window)
{
    this->window = window;
    object = SDL_CreateRenderer(window->GetObj(),-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    eternalObject = &object;
    defaultFont = TTF_OpenFont("C:\\c++\\programs\\rogameSDL(VS2019)\\misc\\fonts\\BullpenItalic.ttf", 22);
    //this->chainedWindow = window;
}


void Render::DrawComponent(SDLP::Components::BaseComponent * component)
{
    //possible types
    Components::Table* table;
    Components::TextureContainer* texCont;
    Components::Button* button;
    Components::PlaceHolder* basePlaceholder;
    Components::QuadPlaceholder* quadPlaceholder;
    //base var
    int componentW, componentH, startPosX, startPosY;
    //table car
    vector<vector<SDL_Rect>> tableMatrix;
    vector<vector<SDL_Rect>> tableTextMatrix;
    int accumulatedColW = 0;
    //render
    switch(component->_GetType())
    {
    case Components::Types::TABLE:
        table = dynamic_cast<Components::Table*>(component);
        componentW = table->_GetW(); componentH = table->_GetH();
        startPosX = table->_GetPositionX(); startPosY = table->_GetPositionY();

        this->DrawFillRect(SDLP::CreateRect(startPosX,startPosY, componentW, componentH), table->GetBackgroundColor());
        tableMatrix.resize(table->GetShowableRowAmmount());
        tableTextMatrix.resize(table->GetShowableRowAmmount());
        for (int cy = 0; cy < table->GetShowableRowAmmount(); cy++) {
            tableMatrix[cy].resize(table->GetColumnSize());
            tableTextMatrix[cy].resize(table->GetColumnSize());
            accumulatedColW = 0;
            for (int cx = 0; cx < table->GetColumnSize(); cx++) {
                tableMatrix[cy][cx].x = startPosX + accumulatedColW;
                tableMatrix[cy][cx].y = startPosY + (cy*table->GetRowH());
                tableMatrix[cy][cx].w = table->GetColW(cx);
                tableMatrix[cy][cx].h = table->GetRowH();
                tableTextMatrix[cy][cx].x = tableMatrix[cy][cx].x + 2;
                tableTextMatrix[cy][cx].y = tableMatrix[cy][cx].y + 2;
                tableTextMatrix[cy][cx].w = tableMatrix[cy][cx].w - 6;
                tableTextMatrix[cy][cx].h = tableMatrix[cy][cx].h - 6;
                accumulatedColW += table->GetColW(cx);
            }
        }
        for (int cy = -1; cy < table->GetShowableRowAmmount()-1; cy++) {
            for (int cx = 0; cx < table->GetColumnSize(); cx++) {
                this->DrawFillRect(tableMatrix[cy+1][cx], table->GetBackgroundColor());
                this->DrawOutlineRect(tableMatrix[cy+1][cx], table->GetEdgeColor());
                if (cx == -1 || cy == -1) {
                    this->DrawTextW(tableTextMatrix[cy + 1][cx], table->GetColumnText(cx), table->GetTextColor());
                }
                else {
                    this->DrawTextW(tableTextMatrix[cy+1][cx], table->GetData(cx, (cy + table->GetFirstId())), table->GetTextColor());
                }
            }
        }
        /*
        for(int rowid=0;rowid<table->GetRowSize()+1;rowid++) {
            this->DrawLine(startPosX,startPosY,startPosX+componentW,startPosY,table->GetEdgeColor());
            startPosY+=table->GetRowH();
        }
        startPosX = table->_GetPositionX(); startPosY = table->_GetPositionY();
        for(int columnid=0;columnid<table->GetColumnSize()+1;columnid++) {
            this->DrawLine(startPosX,startPosY,startPosX,startPosY+componentH, table->GetEdgeColor());
            startPosX+=table->GetColW(columnid);
        }
        startPosX = table->_GetPositionX(); startPosY = table->_GetPositionY();
        printf("/////////////////////////////////");
        for (int dy = 0; dy < table->GetRowSize(); dy++) {
            for (int dx = 0; dx < table->GetColumnSize(); dx++) {
                SDL_Rect textTile;
                textTile.w = table->GetColW(dx);
                textTile.h = table->GetRowH();
                textTile.x = startPosX + (dx*(table->GetColW(dx)));
                textTile.y = startPosY + (dy* table->GetRowH());
                this->DrawTextW(textTile,table->GetData(dx,dy),table->GetTextColor());
                printf("txt id x%d|y%d | pos x%d|y%d\n",dx,dy, textTile.x, textTile.y);
            }
        }
        */
    break;
    case Components::Types::TEXTURE_CONTAINER:
        texCont = dynamic_cast<Components::TextureContainer*>(component);
        componentW = texCont->GetW();  componentH = texCont->GetH();
        startPosX = texCont->_GetPositionX(); startPosY = texCont->_GetPositionY();
        this->DrawTexture(*texCont->GetTexture(),SDLP::CreateRect(startPosX,startPosY,componentW,componentH));
    break;
    case Components::BUTTON:
        button = dynamic_cast<Components::Button*>(component);
        this->DrawFillRect(
            SDLP::CreateRect(
                button->_GetPositionX(),
                button->_GetPositionY(),
                button->_GetW(),
                button->_GetH()
            ),
            button->GetBackgroundColor()
        );
        this->DrawOutlineRect(
            SDLP::CreateRect(
                button->_GetPositionX(),
                button->_GetPositionY(),
                button->_GetW(),
                button->_GetH()
            ),
            SDLP::CreateColor(0,0,0)
        );
        this->DrawTextW(
            SDLP::CreateRect(
                button->_GetPositionX(),
                button->_GetPositionY(),
                button->_GetW(),
                button->_GetH()
            ),
            button->GetData(),
            SDLP::CreateColor(0,0,0)
        );
    break;
    case Components::PLACEHOLDER:
        basePlaceholder = dynamic_cast<Components::PlaceHolder*>(component);
        if (basePlaceholder->GetSelfType() == Components::PlaceholderTypes::QUAD) {
            quadPlaceholder = dynamic_cast<Components::QuadPlaceholder*>(basePlaceholder);
            for (int comid = 0; comid < quadPlaceholder->GetComponentAmmount(); comid++) {
                this->DrawComponent(quadPlaceholder->GetComponent(comid));
            }
        }
    break;
    }
}


void Render::DrawTexture(SDLP::Texture texture, SDL_Rect distRect)
{
    SDL_RenderCopy(this->object, texture.GetObj(), texture.GetRect(), &distRect);
}

void Render::DrawTextW(SDL_Rect position,std::string text,SDL_Color clr)
{
    SDLP::Surface surfaceMessage(defaultFont,text.c_str(),position,clr);
    SDLP::Texture textureMessage(&surfaceMessage,this->object,position.w,position.h);
    this->DrawTexture(textureMessage,position);
}

void Render::DrawLine(int x1,int y1, int x2,int y2, SDL_Color clr)
{
    SDL_SetRenderDrawColor(object,clr.r,clr.g,clr.b,clr.a);
    SDL_RenderDrawLine(object,x1,y1,x2,y2);
}

void Render::DrawFillRect(SDL_Rect rect,SDL_Color clr)
{
    SDL_SetRenderDrawColor(object, clr.r, clr.g, clr.b, clr.a);
    SDL_RenderFillRect(object, &rect);
}

void Render::DrawOutlineRect(SDL_Rect rect, SDL_Color clr)
{
    SDL_SetRenderDrawColor(object, clr.r, clr.g, clr.b, clr.a);
    SDL_RenderDrawRect(object, &rect);
}
