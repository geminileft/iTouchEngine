#ifndef TEENGINE
#define TEENGINE

#include "TETypes.h"
#include <vector>

class TEManager;
class TEGameObject;

@class TERunnable;

class TEEngine {

private:
    std::vector<TEManager*> mManagers;
    std::vector<TEGameObject*> mGameObjects;
    TERunnable* mRunnable;
    UIWindow* mWindow;

public:
	int mHeight;
	int mWidth;

    TEEngine(int width, int height);
    virtual void start() = 0;
    void run();
    void addGameObject(TEGameObject* gameObject);
    TESize getScreenSize() const;
    void initialize();
};

#endif