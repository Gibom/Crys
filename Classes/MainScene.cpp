#include "MainScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

//android effect only support ogg
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE		"Sounds/effect2.ogg"
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE		"Sounds/effect1.raw"
#else
#define EFFECT_FILE		"Sounds/effect1.wav"
#endif // CC_PLATFORM_ANDROID

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE		"Sounds/music.mid"
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE		"Sounds/background.ogg"
#else
#define MUSIC_FILE		"Sounds/background.mp3"
#endif // CC_PLATFORM_WIN32

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);

	return scene;
}

bool MainScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	/////////////////////////////
	
	pMenuItem1 = MenuItemImage::create(
		"mainscene/btn-play.png",
		"mainscene/btn-play-down.png",
		CC_CALLBACK_1(MainScene::selectMenu,this));
	

	pMenuItem2 = MenuItemImage::create(
		"mainscene/btn-about.png",
		"mainscene/btn-about-down.png",
		CC_CALLBACK_1(MainScene::selectMenu, this));
	
	pMenuItem1->setPosition(Vec2(160, 220));
	pMenuItem1->setScale(0.5f);
	pMenuItem2->setPosition(Vec2(160, 180));
	pMenuItem2->setScale(0.5f);
	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, nullptr);
	pMenu->setPosition(Vec2::ZERO);

	this->addChild(pMenu);


	return true;
}

void MainScene::selectMenu(Ref* pSender)
{
	log("111");
}
