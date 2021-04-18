#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

#include "../BaseObject.h"
#include <vector>
using namespace std;

namespace SDLP {
    //class
    // maybe template?
    class Factory {
    public:
        Factory() {}
        Factory(BaseObject * istok) {
            this->istok = istok;
        }
        BaseObject* Clone() {
            BaseObject* obj = new BaseObject();
            *obj = *istok;
            childList.push_back(obj);
            return obj;
        }
        void CleanAll() {
            for(int i=0;i<childList.size();i++) {
                delete childList[i];
            }
        }
    protected:
        BaseObject* istok;
        vector<BaseObject*> childList;
    };
    template<typename T>
    class PFactory {
    public:
        PFactory() {
           istok = new T;
           fromScratch = true;
        }
        PFactory(T* istok) {
            this->istok = istok;
            fromScratch = false;
        }
        T* Clone() {
            T* obj = new T;
            *obj = *istok;
            childList.push_back(obj);
            return obj;
        }
        void CleanAll() {
            for(int i=0;i<childList.size();i++) {
                delete childList[i];
            }
            if(fromScratch) {
                delete istok;
            }
        }
    protected:
        bool fromScratch;
        T* istok;
        vector<T*> childList;
    };
}

#endif // FACTORY_H_INCLUDED
