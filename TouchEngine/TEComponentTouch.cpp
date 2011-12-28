#include "TEComponentTouch.h"
#include "TEGameObject.h"
#include "TEInputTouch.h"

bool TEComponentTouch::containsPoint(TEPoint point) {
    bool returnValue = false;
    TEPoint position = mParent->position;
    TESize size  = mParent->size;
    float left = (float)position.x - ((float)size.width / 2);
    float right = (float)position.x + ((float)size.width / 2);
    float bottom = (float)position.y - ((float)size.height / 2);
    float top = (float)position.y + ((float)size.height / 2);
    if ((point.x >= left) && (point.x <= right) && (point.y >= bottom) && (point.y <= top)) {
        returnValue = true;
    }
    return returnValue;
}
