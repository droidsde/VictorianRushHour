//
//  GameSprite.cpp
//  Victorian
//
//  Created by Hildequias Silas dos Santos Junior on 09/12/16.
//
//

#include "GameSprite.h"

USING_NS_CC;

GameSprite::GameSprite(void)
:_vector(Vec2(0,0))
,_screenSize(Director::getInstance()->getWinSize())
{
}

GameSprite::~GameSprite(void){}
