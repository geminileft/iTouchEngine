#ifndef TEENGINE
#define TEENGINE

#include <vector>
#include "TEManager.h"
#include "TEGameObject.h"

using namespace std;

class TEEngine {

private:
	vector<TEManager*> mManagers;
    vector<TEGameObject*> mGameObjects;

public:
    TEEngine();

    virtual void start() = 0;
    
    void run();
    void addGameObject(TEGameObject* gameObject);
    void initGraphics();
};

#endif