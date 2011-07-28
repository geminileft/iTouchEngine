#ifndef TETYPES
#define TETYPES

class TEComponent;

#include <list>

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
