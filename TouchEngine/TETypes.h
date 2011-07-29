#ifndef TETYPES
#define TETYPES

class TEComponent;

#include <list>

enum TEComponentEvent {
	EVENT_TOUCH_STARTED
	, EVENT_TOUCH_REJECT
	, EVENT_TOUCH_ACCEPT
	, EVENT_TOUCH_ENDED
	, EVENT_MOVE_TO_TOP
	, EVENT_ACCEPT_MOVE
	, EVENT_REJECT_MOVE
	, EVENT_MOVE_TO_FOUNDATION
};

typedef TEComponentEvent TEComponentEvent;

struct TESize {
    float width;
    float height;
};

typedef TESize TESize;

struct TEPoint {
    float x;
    float y;
};

typedef TEPoint TEPoint;

typedef std::list<TEComponent*> TEComponentContainer;

#endif
