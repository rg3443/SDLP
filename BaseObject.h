#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED

namespace SDLP {
    class BaseObject {
    public:
        BaseObject() {}
        BaseObject(bool clonable) {}
        bool __isClonable() { return clonable; }
        void __setClonable(bool clonable);

        virtual void __clone();
    protected:
        bool clonable;
    };
}

#endif // BASEOBJECT_H_INCLUDED
