#ifndef TECOMPONENTCONTAINER
#define TECOMPONENTCONTAINER

class TEComponent;

#include <list>
#include "TEComponent.h"

using namespace std;

class TEComponentContainer : public list<TEComponent*> {
};

#endif
