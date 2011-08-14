#ifndef FREECELLGAMEOBJECTFACTORY
#define FREECELLGAMEOBJECTFACTORY

class TEEngine;

#include "TEGameObject.h"
#include <string>
#include <map>

#define CARD_SIZE_WIDTH 36//48
#define CARD_SIZE_HEIGHT 48//64

class TEGameObject;
class PlayingCard;

class FreeCellGameObjectFactory {
private:
    std::map<std::string, const char*> mCardMap;
	TEEngine* mGame;
public:
    FreeCellGameObjectFactory(TEEngine* game);
    TEGameObject* createBackground();
    TEGameObject* createFreeCell(TEPoint position);
    TEGameObject* createAceCellStack(TEPoint position);
	TEGameObject* createTableCellStack(TEPoint position);
    TEGameObject* createPlayingCard(PlayingCard* card);
	TEGameObject* createHUDTimer();
	TEGameObject* createMenu();
};

#endif
