#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include <math.h>
#include "GameScene.h"
#include "AboutScene.h"


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
	srand((int)time(nullptr));
	Sprite* background = Sprite::create("mainscene/background.png");
	background->setAnchorPoint(Vec2::ZERO);
	this->addChild(background,0);
	this->showParticle();
	this->schedule(schedule_selector(MainScene::showGem),1.0f);
	this->schedule(schedule_selector(MainScene::delGem),1.2f);
	Sprite* logo = Sprite::create("mainscene/logo.png");
	logo->setPosition(Vec2(160, 360));
	this->addChild(logo,1);


	pMenuItem1 = MenuItemImage::create(
		"mainscene/btn-play.png",
		"mainscene/btn-play-down.png",
		CC_CALLBACK_1(MainScene::onPressPlay,this));
	

	pMenuItem2 = MenuItemImage::create(
		"mainscene/btn-about.png",
		"mainscene/btn-about-down.png",
		CC_CALLBACK_1(MainScene::onPressAbout, this));
	
	pMenuItem1->setPosition(Vec2(160, 200));
	pMenuItem1->setScale(0.6f);
	pMenuItem1->setTag(1);
	pMenuItem2->setPosition(Vec2(160, 100));
	pMenuItem2->setScale(0.6f);
	pMenuItem1->setTag(2);
	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, nullptr);
	pMenu->setPosition(Vec2::ZERO);

	this->addChild(pMenu,1);

	
	return true;
}

void MainScene::onPressPlay(Ref* pSender)
{
	
	auto pScene = GameScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
void MainScene::onPressAbout(Ref* pSender)
{
	auto pScene = AboutScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void MainScene::showParticle()
{
	
	const char* stars = "mainscene/bg-stars.plist";

	ParticleSystem* particleTest = ParticleSystemQuad::create(stars);

	this->addChild(particleTest);

}
void MainScene::showGem(float dt)
{	
	
	Size size = Director::getInstance()->getWinSize();
	int type = rand() % 5;
	gem = SpriteFrameCache::getInstance();
	gem->addSpriteFramesWithFile("mainscene/crystals.plist");
	
	sprintf(str, "crystals/%d.png", type);
	sprt = Sprite::createWithSpriteFrameName(str);
	
	int x = sprt->getContentSize().width * type;
	int y = sprt->getContentSize().height + 40 / 2;
	float scale = 0.2 + 0.8 * (rand()%10);
	
	sprt->setPosition(ccp(RANDOM_INT(0, (int)size.width), size.height));
	sprt->setAnchorPoint(Vec2(0.5, 0.5));
	sprt->setScale(0.5f);
	
	auto move = MoveBy::create(2.f, ccp(0, -size.height));
	sprt->runAction(move);
	//sprt->setPosition(Vec2(300, 100));

	//cmp = sprt->convertToNodeSpace(sprt->getPosition());
	//log("%d", cmp.y);
	//if ( cmp.y <= 0)
	//{
	//	log("%d", sprt->getPosition().y);
	//	removeChild(sprt, false);
	//	
	//}
	
	this->addChild(sprt);	
}
void MainScene::delGem(float dt)
{
	removeChild(sprt, true);
}
