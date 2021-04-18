#ifndef SDLP_TILE_H_INCLUDED
#define SDLP_TILE_H_INCLUDED

namespace SDLP {
    class Tile {
    public:
        Tile() {}
        void Init();
        //setters
        void SetX(int val) { x = val; }
        void SetY(int val) { y = val; }
        void SetZ(int val) { z = val; }
        //getters
        int GetX() { return x; }
        int GetY() { return y; }
        int GetZ() { return z; }
    protected:
        int x,y,z;

    };
}

#endif // SDLP_TILE_H_INCLUDED
