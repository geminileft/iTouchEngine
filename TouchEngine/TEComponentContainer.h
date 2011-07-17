#ifndef TECOMPONENTCONTAINER
#define TECOMPONENTCONTAINER

#include <list>
#include "TEComponent.h"

using namespace std;

class TEComponentContainer : public list<TEComponent*> {
};

#endif
