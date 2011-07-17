#ifndef TEENGINE
#define TEENGINE

#include <vector>
#include "TEManager.h"
#include "TEManagerRender.h"

using namespace std;

class TEEngine {

private:
	vector<TEManager*> mManagers;
    
public:
    TEEngine();

    virtual void start() = 0;
    
    void run();
    
};

#endif