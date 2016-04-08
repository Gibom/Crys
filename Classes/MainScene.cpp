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

Scene* Main::createScene()
{
	auto scene = Scene::create();
	auto layer = Main::create();
	scene->addChild(layer);

	return scene;
}

bool Main::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	/////////////////////////////

	return true;
}