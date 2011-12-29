#ifndef FREECELLGAMEOBJECTFACTORY
#define FREECELLGAMEOBJECTFACTORY

#include <string>
#include <map>
#include "TETypes.h"

class TEEngine;
class TEGameObject;
class PlayingCard;

#define CARD_SIZE_WIDTH 36//48
#define CARD_SIZE_HEIGHT 48//64

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
