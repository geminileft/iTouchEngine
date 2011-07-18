#ifndef FREECELLGAMEOBJECTFACTORY
#define FREECELLGAMEOBJECTFACTORY

#include "TEGameObject.h"

class TEGameObject;

class FreeCellGameObjectFactory {

public:
    TEGameObject* createBackground();
    TEGameObject* createFreeCell(TEPoint position);

};
#endif
