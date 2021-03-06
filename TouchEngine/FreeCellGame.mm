#include "FreeCellGame.h"
#include "TEGameObject.h"
#include "TEComponentStack.h"
#include "StackTableCell.h"
#include "StackCard.h"
#include "RenderImage.h"
#include "RenderHUD.h"
#include "TERandomizer.h"
#include "TEManagerTime.h"
#include "TEManagerStack.h"
#include "PlayingCard.h"
#include "FreeCellGameObjectFactory.h"

FreeCellGame::FreeCellGame(int width, int height) : TEEngine(width, height), mFactory(new FreeCellGameObjectFactory(this)){}

void FreeCellGame::start() {
    addGameObject(mFactory->createBackground());
    int x = START_X;
    int y = mHeight - 50;
    
    TEEventListenerBase* listener = addHUDMoves();
	addGameObject(mFactory->createHUDTimer());
    addGameObject(mFactory->createMenu());
    for (int i = 0;i < 4;++i) {
        TEPoint pt;
        pt.x = x;
        pt.y = y;
        addGameObject(mFactory->createFreeCell(pt));
        x += CARD_SIZE_WIDTH + X_GAP;
    }
    
    for (int i = 0;i < 4;++i) {
        TEPoint pt;
        pt.x = x;
        pt.y = y;
        addGameObject(mFactory->createAceCellStack(pt));
        x += CARD_SIZE_WIDTH + X_GAP;
    }
    
	const int stack1 = 8;
	const int stack2 = 7;
    PlayingCard* stacks[stack1][stack2];
	for (int i = 0; i < stack1; ++i) {
		for (int j = 0; j < stack2; ++j) {
			stacks[i][j] = NULL;
		}
	}
    PlayingCard* deck[52];
    deck[0] = new PlayingCard(Ace, Spade);
    deck[1] = new PlayingCard(Two, Spade);
    deck[2] = new PlayingCard(Three, Spade);
    deck[3] = new PlayingCard(Four, Spade);
    deck[4] = new PlayingCard(Five, Spade);
    deck[5] = new PlayingCard(Six, Spade);
    deck[6] = new PlayingCard(Seven, Spade);
    deck[7] = new PlayingCard(Eight, Spade);
    deck[8] = new PlayingCard(Nine, Spade);
    deck[9] = new PlayingCard(Ten, Spade);
    deck[10] = new PlayingCard(Jack, Spade);
    deck[11] = new PlayingCard(Queen, Spade);
    deck[12] = new PlayingCard(King, Spade);
    deck[13] = new PlayingCard(Ace, Club);
    deck[14] = new PlayingCard(Two, Club);
    deck[15] = new PlayingCard(Three, Club);
    deck[16] = new PlayingCard(Four, Club);
    deck[17] = new PlayingCard(Five, Club);
    deck[18] = new PlayingCard(Six, Club);
    deck[19] = new PlayingCard(Seven, Club);
    deck[20] = new PlayingCard(Eight, Club);
    deck[21] = new PlayingCard(Nine, Club);
    deck[22] = new PlayingCard(Ten, Club);
    deck[23] = new PlayingCard(Jack, Club);
    deck[24] = new PlayingCard(Queen, Club);
    deck[25] = new PlayingCard(King, Club);
    deck[26] = new PlayingCard(Ace, Heart);
    deck[27] = new PlayingCard(Two, Heart);
    deck[28] = new PlayingCard(Three, Heart);
    deck[29] = new PlayingCard(Four, Heart);
    deck[30] = new PlayingCard(Five, Heart);
    deck[31] = new PlayingCard(Six, Heart);
    deck[32] = new PlayingCard(Seven, Heart);
    deck[33] = new PlayingCard(Eight, Heart);
    deck[34] = new PlayingCard(Nine, Heart);
    deck[35] = new PlayingCard(Ten, Heart);
    deck[36] = new PlayingCard(Jack, Heart);
    deck[37] = new PlayingCard(Queen, Heart);
    deck[38] = new PlayingCard(King, Heart);
    deck[39] = new PlayingCard(Ace, Diamond);
    deck[40] = new PlayingCard(Two, Diamond);
    deck[41] = new PlayingCard(Three, Diamond);
    deck[42] = new PlayingCard(Four, Diamond);
    deck[43] = new PlayingCard(Five, Diamond);
    deck[44] = new PlayingCard(Six, Diamond);
    deck[45] = new PlayingCard(Seven, Diamond);
    deck[46] = new PlayingCard(Eight, Diamond);
    deck[47] = new PlayingCard(Nine, Diamond);
    deck[48] = new PlayingCard(Ten, Diamond);
    deck[49] = new PlayingCard(Jack, Diamond);
    deck[50] = new PlayingCard(Queen, Diamond);
    deck[51] = new PlayingCard(King, Diamond);
    
	TERandomizer* rand = new TERandomizer(TEManagerTime::currentTime());
    int wLeft = 52;
    for (int i = 0;i < 52;++i) {
		unsigned int next  = rand->next();
        int j = abs(next) % wLeft;
        stacks[(i % 8)][i / 8] = deck[j];
        deck[j] = deck[--wLeft];
    }
    addTableStack(START_X, mFactory, stacks, listener);
    TEComponentStack::setOpenFreeCellCount(4);
    TEComponentStack::setOpenTableCellCount(0);
}

void FreeCellGame::addTableStack(int startX, FreeCellGameObjectFactory* factory, PlayingCard* cards[][7], TEEventListenerBase* listener) {
	TEManagerStack* stackManager = TEManagerStack::sharedManager();
	TEEventListenerBase* touchAcceptedListener = stackManager->getTouchAcceptListener();
	
    int x = startX;
    int y = mHeight - 120;
    for (int j = 0; j < 8;++j) {
        TEGameObject* gameObject = factory->createTableCellStack(TEPointMake(x, y));
        StackTableCell* tableStack = new StackTableCell(TableCell);
		stackManager->addTableStack(tableStack);
        gameObject->addComponent(tableStack);
        addGameObject(gameObject);
        TEComponentStack* stack = tableStack;
        for (int i = 0;i < 7;++i) {
            PlayingCard* card = cards[j][i];
            if (card != NULL) {
                StackCard* cardStack;
                gameObject = factory->createPlayingCard(card);
                cardStack = new StackCard(card);
                gameObject->addComponent(cardStack);
                stack->pushStack(cardStack);
                gameObject->addEventSubscription(EVENT_ACCEPT_MOVE, listener);
                gameObject->addEventSubscription(EVENT_ACCEPT_MOVE, touchAcceptedListener);
                addGameObject(gameObject);				
                stack = cardStack;
            }
        }
        x += CARD_SIZE_WIDTH + X_GAP;
    }
}

TEEventListenerBase* FreeCellGame::addHUDMoves() {
	const int y = 45;
	const int xOffset = 10;
	TEEventListenerBase* eventListener;
	const int x = 60;
	TESize size;
	size.width = 118;
	size.height = 26;
	TEPoint offset;
	offset.x = 0;
	offset.y = 0;
	RenderImage* image = new RenderImage(@"moves.png", offset, size);
	TEGameObject* gameObject = new TEGameObject();
	gameObject->addComponent(image);
	gameObject->position.x = x;
	gameObject->position.y = y;
	addGameObject(gameObject);
	gameObject = new TEGameObject();
	size.width = 0;
	size.height = 0;
	RenderHUD* text = new RenderHUD(@"numbers.png", offset, size);
	eventListener = text->getTouchAcceptListener();
	gameObject->addComponent(text);
	gameObject->position.x = x + size.width / 2 + xOffset;
	gameObject->position.y = y;
	addGameObject(gameObject);
	return eventListener;
}
