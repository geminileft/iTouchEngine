//
//  PlayingCard.h
//  TouchEngine
//
//  Created by geminileft on 7/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef PLAYINGCARD
#define PLAYINGCARD

#include <string>

enum SuitColor {
    Red
    , Black
};

typedef enum SuitColor SuitColor;

enum FaceValue {
    Ace = 1
    , Two = 2
    , Three = 3
    , Four = 4
    , Five = 5
    , Six = 6
    , Seven = 7
    , Eight = 8
    , Nine = 9
    , Ten = 10
    , Jack = 11
    , Queen = 12
    , King = 13
};

typedef enum FaceValue FaceValue;

enum Suit {
    Spade
    , Club
    , Diamond
    , Heart
};

typedef enum Suit Suit;

class PlayingCard {
private:
    int mValue;
    FaceValue mFaceValue;
    Suit mSuit;

public:
    PlayingCard(FaceValue faceValue, Suit suit);
	FaceValue getFaceValue() const;
	Suit getSuit() const;
    std::string getCardName() const;
	bool canStack(PlayingCard* stackCard) const;
    static SuitColor getSuitColor(Suit suit);
};

#endif