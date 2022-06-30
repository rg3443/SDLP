#ifndef SDLP_MENURENDER_H
#define SDLP_MENURENDER_H

#include "../ph.h"
#include "SDLP_BaseMenu.h"

namespace SDLP {
    class MenuRender : public BaseObject {
    public:
        MenuRender();

        void Init(Render * render, Window * window);
        void RenderMenu(BaseMenu * menu);

    protected:
        Render * render;
        Window * window;

    };

}

#endif // SDLP_MENURENDER_H
