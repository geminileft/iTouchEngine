#ifndef TEENGINE
#define TEENGINE

#include <vector>

class TEManager;
class TEGameObject;

//#include "TEManager.h"
//#include "TEGameObject.h"

class TEEngine {

private:
    std::vector<TEManager*> mManagers;
    std::vector<TEGameObject*> mGameObjects;

public:
    TEEngine();

    virtual void start() = 0;
    
    void run();
    void addGameObject(TEGameObject* gameObject);
    void initGraphics(int width, int height);
};

#endif