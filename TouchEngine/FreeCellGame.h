#ifndef FREECELLGAME
#define FREECELLGAME

#include "TEEngine.h"

class FreeCellGameObjectFactory;
class PlayingCard;
class TEEventListenerBase;

#define START_X 28
#define X_GAP 2

class FreeCellGame : public TEEngine {
private:
	FreeCellGameObjectFactory* mFactory;

public:
    FreeCellGame(int width, int height);	
    virtual void start();
    void addTableStack(int startX, FreeCellGameObjectFactory* factory, PlayingCard* cards[][7], TEEventListenerBase* listener);
	TEEventListenerBase* addHUDMoves();
};

#endif