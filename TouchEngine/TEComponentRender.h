#ifndef TECOMPONENTRENDER
#define TECOMPONENTRENDER

#include "TEComponent.h"

class TEComponentRender : public TEComponent {
public:
	virtual void draw() = 0;
};

#endif