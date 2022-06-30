#ifndef SDLP_GLOBAL_H
#define SDLP_GLOBAL_H
#include "ph.h"


namespace SDLP {
    class Global {
    public:
        Global(){}
        void Init(std::string windowName,int windowW,int windowH);
        void TestRun();

        //draw methods
        void DrawImg(std::string imgPath,int x,int y,int w, int h);
        void DrawText(std::string textString, int x, int y, int w, int h);

        //creating menus
        void CreateMenu();
        void AddMenuComponent();



    protected:
        Render render;
        Window window;
        TextureList textureList;
        //MenuList menuList;
    };
}

#endif // SDLP_GLOBAL_H
