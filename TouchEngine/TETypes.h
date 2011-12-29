#ifndef TETYPES
#define TETYPES

#include <list>
#include <string>

class TEComponent;

typedef std::string String;

typedef unsigned int uint;

enum TEComponentEvent {
	EVENT_TOUCH_STARTED
	, EVENT_TOUCH_REJECT
	, EVENT_TOUCH_ACCEPT
	, EVENT_TOUCH_ENDED
	, EVENT_MOVE_TO_TOP
	, EVENT_ACCEPT_MOVE
	, EVENT_REJECT_MOVE
	, EVENT_MOVE_TO_FOUNDATION
	, EVENT_PRE_MOVE_TO_FOUNDATION
};

typedef TEComponentEvent TEComponentEvent;

struct TESize {
    float width;
    float height;	
};

typedef TESize TESize;

inline TESize TESizeMake(float newWidth, float newHeight) {
	TESize size;
	size.width = newWidth;
	size.height = newHeight;
	return size;
}

struct TEPoint {
    float x;
    float y;	
};

typedef TEPoint TEPoint;

inline TEPoint TEPointMake(float newX, float newY) {
	TEPoint point;
	point.x = newX;
	point.y = newY;
	return point;
}

typedef std::list<TEComponent*> TEComponentContainer;

struct TERect {
	float left;
	float right;
	float top;
	float bottom;
	
	bool overlaps(TERect rect) {
		return
		(left <= rect.right)
		&& (right >= rect.left)
		&& (bottom <= rect.top)
		&& (top >= rect.bottom);
	}
};

typedef TERect TERect;

inline TERect TERectMake(TEPoint position, TESize size) {
	TERect rect;
	rect.left = position.x - ((float)size.width / 2);
	rect.right = rect.left + size.width;
	rect.bottom = position.y - ((float)size.height / 2);
	rect.top = rect.bottom + size.height;
	return rect;
}

struct TEVec3 {
    float x;
    float y;
    float z;
};

typedef struct TEVec3 TEVec3;


#endif
