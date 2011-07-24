#ifndef TEINPUTTOUCH
#define TEINPUTTOUCH

#include "TETypes.h"

class TEInputTouch {
private:
	bool mBegan;
	bool mEnd;
	TEPoint mStartPoint;
	TEPoint mEndPoint;
	int mHash;
public:
	TEInputTouch(int hash, float x, float y);
    TEInputTouch(bool began, bool ended, TEPoint startPoint, TEPoint endPoint, int hash);

    bool began() const;
    bool ended() const;
    TEPoint getStartPoint() const;	
    TEPoint getEndPoint() const;
    void setEndPoint(TEPoint point);
    int getPointerId()  const;
    void endTouch(TEPoint point);
    TEInputTouch* copy() const;
    void reset();
};

#endif