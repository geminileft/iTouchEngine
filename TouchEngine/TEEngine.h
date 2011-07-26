#ifndef TEENGINE
#define TEENGINE

#include "TETypes.h"
#include <vector>

class TEManager;
class TEGameObject;

class TEEngine {

private:
    std::vector<TEManager*> mManagers;
    std::vector<TEGameObject*> mGameObjects;
public:
	int mHeight;
	int mWidth;

    TEEngine(int width, int height);
    virtual void start() = 0;
    void run();
    void addGameObject(TEGameObject* gameObject);
    void initGraphics(int width, int height);
	void graphicsChange(int width, int height);
    TESize getScreenSize() const;
};

#endif