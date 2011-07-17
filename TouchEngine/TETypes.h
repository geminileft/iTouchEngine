#ifndef TETYPES
#define TETYPES

class TEComponent;

#include <list>

using namespace std;

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

typedef list<TEComponent*> TEComponentContainer;
#endif
