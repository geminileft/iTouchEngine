
#include "TEInputTouch.h"

TEInputTouch::TEInputTouch(int hash, float x, float y) {
    mStartPoint.x = x;
    mStartPoint.y = y;
    mEndPoint.x = x;
    mEndPoint.y = y;
    mBegan = true;
    mEnd = false;
}
    
TEInputTouch::TEInputTouch(bool began, bool ended, TEPoint startPoint, TEPoint endPoint, int hash) {
    mBegan = began;
    mEnd = ended;
    mStartPoint = startPoint;
    mEndPoint = endPoint;
    mHash = hash;	
}
	
bool TEInputTouch::began() const {
    return mBegan;
}
	
bool TEInputTouch::ended() const {
    return mEnd;
}
	
TEPoint TEInputTouch::getStartPoint() const {
    return mStartPoint;
}
	
TEPoint TEInputTouch::getEndPoint() const {
    return mEndPoint;
}
	
int TEInputTouch::getPointerId() const {
    return mHash;
}
	
void TEInputTouch::endTouch(TEPoint point) {
    mEndPoint.x = point.x;
    mEndPoint.y = point.y;
    mEnd = true;
}
    
TEInputTouch* TEInputTouch::copy() const {
    TEInputTouch* touch = new TEInputTouch(mBegan, mEnd,  mStartPoint, mEndPoint, mHash);
    return touch;
}
	
void TEInputTouch::reset() {
    mBegan = false;
    mEnd = false;
    mStartPoint.x = mEndPoint.x;
    mStartPoint.y = mEndPoint.y;
}