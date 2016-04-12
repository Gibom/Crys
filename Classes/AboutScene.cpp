#include "MainScene.h"
#include "AboutScene.h"

using namespace cocos2d;

Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);

	return scene;
}

bool AboutScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 0)))
	{
		return false;
	}

	/////////////////////////////

}

void AboutScene::doClose(Ref* pSender)
{
	// Director::getInstace()->popScene();
	auto pScene = MainScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}