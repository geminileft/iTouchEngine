#ifndef TEINPUTTOUCH
#define TEINPUTTOUCH

#include "TETypes.h"

class TEInputTouch {
private:
	bool mBegan;
	bool mEnd;
	TEPoint mStartPoint;
	TEPoint mEndPoint;
	unsigned int mHash;
public:
	TEInputTouch(unsigned int hash, float x, float y);
    TEInputTouch(bool began, bool ended, TEPoint startPoint, TEPoint endPoint, unsigned int hash);

    bool began() const;
    bool ended() const;
    TEPoint getStartPoint() const;	
    TEPoint getEndPoint() const;
    void setEndPoint(TEPoint point);
    unsigned int getPointerId()  const;
    void endTouch(TEPoint point);
    TEInputTouch* copy() const;
    void reset();
};

#endif