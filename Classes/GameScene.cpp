#include "MainScene.h"
#include "GameScene.h"

using namespace cocos2d;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	auto layer2 = TimerScene::create();
	scene->addChild(layer);
	scene->addChild(layer2, 1);

	return scene;
}
bool TimerScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//////////////////////////////
	Sprite* header = Sprite::create("gamescene/header.png");
	header->setAnchorPoint(Vec2(0.5, 0.5));
	header->setPosition(Vec2(160, 440.5));
	this->addChild(header);

	timer = Sprite::create("gamescene/timer.png");
	this->gameTimer();

	pMenuItem3 = MenuItemImage::create(
		"gamescene/btn-pause.png",
		"gamescene/btn-pause-down.png",
		CC_CALLBACK_1(TimerScene::onPressPause, this));

	auto pMenu = Menu::create(pMenuItem3, nullptr);

	pMenu->setPosition(Vec2(18, 462));
	this->addChild(pMenu, 2);
}


bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	/////////////////////////////
	Sprite* background = Sprite::create("mainscene/background.png");
	background->setAnchorPoint(Vec2::ZERO);
	this->addChild(background, 0);

	setupBoard();
	onUpdate(1);

	return true;
	
}

void TimerScene::gameTimer()
{
	auto to1 = ProgressFromTo::create(30, 100, 0);
	auto left = ProgressTimer::create(timer);
	left->setType(ProgressTimer::Type::BAR);
	// Setup for a bar starting from the left since the midpoint is 0 for the x
	left->setMidpoint(Vec2(0, 0));
	// Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
	left->setBarChangeRate(Vec2(1, 0));
	left->setPosition(Vec2(161, 424));
	left->runAction(Repeat::create((to1),1));
	this->addChild(left);
}

void TimerScene::onPressPause(Ref* pSender)
{
	auto pScene = MainScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void GameScene::setupBoard()
{
	gBoard = new int[kNumTotalGems];
	for (int i = 0; i < kNumTotalGems; i++)
	{
		gBoard[i] = -1;
	}
	gNumGemsInColumn = new int[kBoardWidth];
	gTimeSinceAddInColumn = new float[kBoardWidth];

	int x;
	for (x = 0; x < kBoardWidth; x++)
	{
		gNumGemsInColumn[x] = 0;
		gTimeSinceAddInColumn[x] = 0;
	}

	//// Setup falling pieces
	
	gFallingGems = new Gems[kBoardWidth];

	gBoardChangedSinceEvaluation = true;
	gPossibleMove = -1;
}

void GameScene::onUpdate(float dt)
{
	int x;
	if (!gIsGameOver)
	{
		//removeMarkedGems();

		


		// Add falling gems
		for (x = 0; x < kBoardWidth; x++)
		{
			log("11");
			if (1)
			{
				log("22");
				// A gem should be added to this column!
				int gemType = rand() % 5;
				char str[100] = { 0 };

				gem2 = SpriteFrameCache::getInstance();
				gem2->addSpriteFramesWithFile("mainscene/crystals.plist");

				sprintf(str, "crystals/%d.png", gemType);
				auto gemSprite = Sprite::createWithSpriteFrameName(str);
				gemSprite->setPosition(Vec2(x * kGemSize, kBoardHeight * kGemSize));
				gemSprite->setAnchorPoint(Vec2(0, 0));

				
				gem.gemType = gemType;
				gem.gemSprite = gemSprite;
				gem.yPos = kBoardHeight;
				gem.ySpeed = 0;

				gFallingGems[x].push_back(gem);

				this->addChild(gemSprite);

				gTimeSinceAddInColumn[x] = 0;
			}

			gTimeSinceAddInColumn[x]++;
		}
	}

	// Move falling gems
	bool gemLanded = false;
	for (x = 0; x < kBoardWidth; x++)
	{
		Gems &column = gFallingGems[x];
		int numFallingGems = gFallingGems[x].size();
		for (int i = numFallingGems - 1; i >= 0; i--)
		{
			Gem &gem = column[i];

			gem.ySpeed += 0.06;
			gem.ySpeed *= 0.99;
			gem.yPos -= gem.ySpeed;

			if (gem.yPos <= gNumGemsInColumn[x])
			{
				// The gem hit the ground or a fixed gem
				//if (!gemLanded)
				//{
				//	SimpleAudioEngine::getInstance()->playEffect(String::createWithFormat("sounds/tap-%d.wav",
				//		(rand() % 4))->getCString());
				//	gemLanded = true;
				//}

				// Insert into board
				int y = gNumGemsInColumn[x];

				if (gBoard[x + y*kBoardWidth] != -1)
				{
					log(String::createWithFormat("Warning! Overwriting board idx: %d type: %d", x + y*kBoardWidth,
						gBoard[x + y*kBoardWidth])->getCString());
				}

				gBoard[x + y*kBoardWidth] = gem.gemType;

				gBoardSprites.pushBack(gem.gemSprite);
					
				// Update fixed position
				gem.gemSprite->setPosition(x*kGemSize, y*kGemSize);
				gNumGemsInColumn[x] ++;

				gBoardChangedSinceEvaluation = true;
				column.erase(column.begin() + i);
			}
			else
			{
				// Update the falling gems position
				gem.gemSprite->setPosition(x*kGemSize, gem.yPos*kGemSize);
			}
		}
	}
}