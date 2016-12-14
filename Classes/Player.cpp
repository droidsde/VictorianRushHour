//
//  Player.cpp
//  Victorian
//
//  Created by Hildequias Silas dos Santos Junior on 14/12/16.
//
//

#include "Player.h"
#include "SimpleAudioEngine.h"
#define P_ACCELERATION 0.05

using namespace CocosDenshion;

Player::~Player(){
    
    CC_SAFE_RELEASE(_rideAnimation);
    CC_SAFE_RELEASE(_floatAnimation);
}

Player::Player() {
    
    _screenSize = Director::getInstance()->getWinSize();
    
}

Player * Player::create () {
    
    auto player = new Player();
    
    if (player && player->initWithSpriteFrameName("player_1.png")) {
        player->autorelease();
        player->setSize();
        player->initPlayer();
        return player;
    }
    
    CC_SAFE_DELETE(player);
    return nullptr;
}

void Player::update (float dt) {
    
}

void Player::reset () {

}

void Player::setFloating (bool value) {
    
}

void Player::initPlayer () {
    
    
}
