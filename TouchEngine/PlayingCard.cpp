//
//  PlayingCard.cpp
//  TouchEngine
//
//  Created by geminileft on 7/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "PlayingCard.h"
	
PlayingCard::PlayingCard(FaceValue faceValue, Suit suit) {
    mFaceValue = faceValue;
    mSuit = suit;
}
	
FaceValue PlayingCard::getFaceValue() const {
    return mFaceValue;
}
	
Suit PlayingCard::getSuit() const {
    return mSuit;
}
	
std::string PlayingCard::getCardName() const {
    std::string Value;
    
    switch(mSuit) {
        case Spade:
            Value = "Spade";
            break;
        case Club:
            Value = "Club";
            break;
        case Diamond:
            Value = "Diamond";
            break;
        case Heart:
            Value = "Heart";
            break;
        default:
            Value = "";
            break;
    }
    
    switch(mFaceValue) {
        case Ace:
            Value = Value + "Ace";
            break;
        case Two:
            Value = Value + "Two";
            break;
        case Three:
            Value = Value + "Three";
            break;
        case Four:
            Value = Value + "Four";
            break;
        case Five:
            Value = Value + "Five";
            break;
        case Six:
            Value = Value + "Six";
            break;
        case Seven:
            Value = Value + "Seven";
            break;
        case Eight:
            Value = Value + "Eight";
            break;
        case Nine:
            Value = Value + "Nine";
            break;
        case Ten:
            Value = Value + "Ten";
            break;
        case Jack:
            Value = Value + "Jack";
            break;
        case Queen:
            Value = Value + "Queen";
            break;
        case King:
            Value = Value + "King";
            break;
        default:
            Value = Value + "";
    }
    
    //return Value;
	return "SpadeAce";
}

bool PlayingCard::canStack(PlayingCard* stackCard) const {
    Suit suit = getSuit();
    SuitColor suitColor = PlayingCard::getSuitColor(suit);
    SuitColor stackSuitColor = PlayingCard::getSuitColor(stackCard->getSuit());
    return ((suitColor != stackSuitColor) && ((getFaceValue() - 1) == stackCard->getFaceValue()));		
}

SuitColor PlayingCard::getSuitColor(Suit suit) {
    return (suit < 2) ? Black : Red;
}

