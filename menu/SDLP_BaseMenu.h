#ifndef SDLP_BASEMENU_H
#define SDLP_BASEMENU_H

#include "../ph.h"
#include "../components/SDLP_BaseComponent.h"

namespace SDLP {
    class BaseMenu : public BaseObject {
    public:
        BaseMenu();
        void AddComponent(Components::BaseComponent* component);
        void DestroyAllComponents();
        
        //seters
        void SetName(std::string name) { this->__SetObjectName(name); }
        void SetId(int val) { id = val; }

        //geters
        int GetId() { return id; }
        int GetComponentSize() { return componentList.size(); }
        Components::BaseComponent* GetComponent(int id);

    protected:
        int id;
        vector<Components::BaseComponent*> componentList;
    };
}

#endif // SDLP_BASEMENU_H
