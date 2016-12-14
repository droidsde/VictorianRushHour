//
//  GameLayer.cpp
//  Victorian
//
//  Created by Hildequias Silas dos Santos Junior on 08/12/16.
//
//

#include "GameLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

GameLayer::~GameLayer() {
    
    CC_SAFE_RELEASE(_jamMove);
    CC_SAFE_RELEASE(_jamAnimate);
}


Scene* GameLayer::scene()
{
    auto scene = Scene::create();
    
    auto layer = GameLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() ) {
        return false;
    }
    
    //get screen size
    _screenSize = Director::getInstance()->getWinSize();
    
    createGameScreen();
    
    resetGame();
    
    //listen for touches
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    //create main loop
    this->scheduleUpdate();
    
    return true;
}

void GameLayer::resetGame () {
    
    _score = 0;
    _speedIncreaseInterval = 15;
    _speedIncreaseTimer = 0;
    _scoreDisplay->setString ( String::createWithFormat("%i", (int)_score)->getCString() );
    _scoreDisplay->setAnchorPoint(Vec2(1,0));
    _scoreDisplay->setPosition(Vec2(_screenSize.width * 0.95f, _screenSize.height * 0.88f));
    
    _state = kGameIntro;
    
    _intro->setVisible(true);
    _mainMenu->setVisible(true);
    
    _jam->setPosition(Vec2(_screenSize.width * 0.19f, _screenSize.height * 0.47f));
    _jam->setVisible(true);
    _jam->runAction(_jamAnimate);
    
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    SimpleAudioEngine::getInstance()->playBackgroundMusic("background3.mp3", true);
    _running = true;
}


void GameLayer::update(float dt) {
    
    if (!_running) return;
    
    if(_player->getVector().x > 0) {
        _background->setPositionX(_background->getPosition().x - _player->getVector().x * -.25f);
    }
    
}

bool GameLayer::onTouchBegan(Touch * touch, Event* event) {
    
    if (touch) {
        
        
    }
    return true;
    
}

void GameLayer::onTouchEnded(Touch* touch, Event* event) {
    
    if (_state == kGamePlay) {
        
    }
    
}

void GameLayer::createGameScreen () {
    
    
}

