//
//  FreeCellGameObjectFactory.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "FreeCellGameObjectFactory.h"
#include "TEEngine.h"
#include "TETypes.h"

#include "TEManagerStack.h"
#include "PlayingCard.h"

#include "RenderImage.h"
#include "TouchDrag.h"
#include "StackFreeCell.h"
#include "StackAceCell.h"
#include "SoundStart.h"

FreeCellGameObjectFactory::FreeCellGameObjectFactory(TEEngine* game) {
	mGame = game;
    mCardMap["SpadeAce"] = "spade_ace.png";
    mCardMap["SpadeTwo"] = "spade_two.png";
    mCardMap["SpadeThree"] = "spade_three.png";
    mCardMap["SpadeFour"] = "spade_four.png";
    mCardMap["SpadeFive"] = "spade_five.png";
    mCardMap["SpadeSix"] = "spade_six.png";
    mCardMap["SpadeSeven"] = "spade_seven.png";
    mCardMap["SpadeEight"] = "spade_eight.png";
    mCardMap["SpadeNine"] = "spade_nine.png";
    mCardMap["SpadeTen"] = "spade_ten.png";
    mCardMap["SpadeJack"] = "spade_jack.png";
    mCardMap["SpadeQueen"] = "spade_queen.png";
    mCardMap["SpadeKing"] = "spade_king.png";

    mCardMap["DiamondAce"] = "diamond_ace.png";
    mCardMap["DiamondTwo"] = "diamond_two.png";
    mCardMap["DiamondThree"] = "diamond_three.png";
    mCardMap["DiamondFour"] = "diamond_four.png";
    mCardMap["DiamondFive"] = "diamond_five.png";
    mCardMap["DiamondSix"] = "diamond_six.png";
    mCardMap["DiamondSeven"] = "diamond_seven.png";
    mCardMap["DiamondEight"] = "diamond_eight.png";
    mCardMap["DiamondNine"] = "diamond_nine.png";
    mCardMap["DiamondTen"] = "diamond_ten.png";
    mCardMap["DiamondJack"] = "diamond_jack.png";
    mCardMap["DiamondQueen"] = "diamond_queen.png";
    mCardMap["DiamondKing"] = "diamond_king.png";

    mCardMap["HeartAce"] = "heart_ace.png";
    mCardMap["HeartTwo"] = "heart_two.png";
    mCardMap["HeartThree"] = "heart_three.png";
    mCardMap["HeartFour"] = "heart_four.png";
    mCardMap["HeartFive"] = "heart_five.png";
    mCardMap["HeartSix"] = "heart_six.png";
    mCardMap["HeartSeven"] = "heart_seven.png";
    mCardMap["HeartEight"] = "heart_eight.png";
    mCardMap["HeartNine"] = "heart_nine.png";
    mCardMap["HeartTen"] = "heart_ten.png";
    mCardMap["HeartJack"] = "heart_jack.png";
    mCardMap["HeartQueen"] = "heart_queen.png";
    mCardMap["HeartKing"] = "heart_king.png";

    mCardMap["ClubAce"] = "club_ace.png";
    mCardMap["ClubTwo"] = "club_two.png";
    mCardMap["ClubThree"] = "club_three.png";
    mCardMap["ClubFour"] = "club_four.png";
    mCardMap["ClubFive"] = "club_five.png";
    mCardMap["ClubSix"] = "club_six.png";
    mCardMap["ClubSeven"] = "club_seven.png";
    mCardMap["ClubEight"] = "club_eight.png";
    mCardMap["ClubNine"] = "club_nine.png";
    mCardMap["ClubTen"] = "club_ten.png";
    mCardMap["ClubJack"] = "club_jack.png";
    mCardMap["ClubQueen"] = "club_queen.png";
    mCardMap["ClubKing"] = "club_king.png";
}

TEGameObject* FreeCellGameObjectFactory::createBackground() {
	TEGameObject* gameObject = new TEGameObject();
	TESize size = TESizeMake(mGame->mWidth, mGame->mHeight);
	gameObject->addComponent(new RenderImage(@"table_background.png", TEPointMake(0, 0), size));
	gameObject->addComponent(new SoundStart(@"shuffle", @"caf"));
	gameObject->position.x = size.width / 2;
	gameObject->position.y = size.height / 2;
	gameObject->size.width = size.width;
	gameObject->size.height = size.height;
	return gameObject;
}

/*
TEGameObject* FreeCellGameObjectFactory::createBackground() {
    TEGameObject* gameObject = new TEGameObject();
    TESize size;
    size.width = mGame->mWidth;
    size.height = mGame->mHeight;
    TEPoint position;
    position.x = 0;
    position.y = 0;
    gameObject->addComponent(new RenderImage(@"table_background.png", position, size));
    gameObject->addComponent(new SoundStart(@"shuffle", @"caf"));
    gameObject->position.x = size.width / 2;
    gameObject->position.y = size.height / 2;
    gameObject->size = size;
    return gameObject;
}
*/

TEGameObject* FreeCellGameObjectFactory::createPlayingCard(PlayingCard* card) {
    TEGameObject* gameObject = new TEGameObject();
    TESize size;
    size.width = CARD_SIZE_WIDTH;
    size.height = CARD_SIZE_HEIGHT;
    std::string key = card->getCardName();
    NSString* resourceId;
    std::map<std::string, const char * >::iterator iterator = mCardMap.find(key);
    if (iterator == mCardMap.end()) {
        resourceId = @"spade_ace.png";
    } else {
        resourceId = [NSString stringWithUTF8String:iterator->second];
    }
    RenderImage* image = new RenderImage(resourceId, TEPointMake(0, 0), size);
    gameObject->addComponent(image);
    gameObject->addComponent(new TouchDrag());
    gameObject->size = size;
    TEManagerStack* stackManager = TEManagerStack::sharedManager();
    gameObject->addEventSubscription(EVENT_MOVE_TO_FOUNDATION, stackManager->getMoveToAceStackListener());
    return gameObject;
}

TEGameObject* FreeCellGameObjectFactory::createFreeCell(TEPoint position) {
    TEGameObject* gameObject = new TEGameObject();
    TESize size;
    size.width = CARD_SIZE_WIDTH;
    size.height = CARD_SIZE_HEIGHT;
    TEPoint offset;
    offset.x = 0;
    offset.y = 0;
    gameObject->addComponent(new RenderImage(@"free_cell.png", offset, size));
    gameObject->addComponent(new StackFreeCell());
    gameObject->position = position;
    gameObject->size = size;
    return gameObject;
}

TEGameObject* FreeCellGameObjectFactory::createAceCellStack(TEPoint position) {
    TEManagerStack* stackManager = TEManagerStack::sharedManager();
    TEGameObject* gameObject = new TEGameObject();
    StackAceCell* aceCell = new StackAceCell();
    TESize size;
    size.width = CARD_SIZE_WIDTH;
    size.height = CARD_SIZE_HEIGHT;
    TEPoint offset;
    offset.x = 0;
    offset.y = 0;
    gameObject->addComponent(new RenderImage(@"ace_cell.png", offset, size));
    gameObject->addComponent(aceCell);
    gameObject->position = position;
    gameObject->size = size;
    stackManager->addAceStack(aceCell);
    return gameObject;
}

TEGameObject* FreeCellGameObjectFactory::createTableCellStack(TEPoint position) {
    TEGameObject* gameObject = new TEGameObject();
    TESize size;
    size.width = CARD_SIZE_WIDTH;
    size.height = CARD_SIZE_HEIGHT;
    TEPoint offset;
    offset.x = 0;
    offset.y = 0;
    gameObject->addComponent(new RenderImage(@"free_cell.png", offset, size));
    gameObject->position = position;
    gameObject->size = size;
    return gameObject;
}

TEGameObject* FreeCellGameObjectFactory::createHUDTimer() {
	const int height = 15;
	const int x = 105;
	TESize size;
	size.width = 46;
	size.height = 14;
	TEPoint offset;
	offset.x = 0;
	offset.y = 0;
	RenderImage* image = new RenderImage(@"time.png", offset, size);
	TEGameObject* gameObject = new TEGameObject();
	gameObject->addComponent(image);
	gameObject->position.x = x;
	gameObject->position.y = height;
	return gameObject;
}

TEGameObject* FreeCellGameObjectFactory::createMenu() {
	TESize size;
	size.width = 64;
	size.height = 16;
	TEPoint offset;
	offset.x = 0;
	offset.y = 0;
	RenderImage* image = new RenderImage(@"menu.png", offset, size);
	TEGameObject* gameObject = new TEGameObject();
	gameObject->addComponent(image);
	TESize screenSize = mGame->getScreenSize();
	gameObject->position.x = screenSize.width - (size.width / 2);
	gameObject->position.y = 15;
	return gameObject;
}

