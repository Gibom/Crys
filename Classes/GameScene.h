#ifndef __SceneTran1_GameScene__
#define __SceneTran1_GameScene__

#include "cocos2d.h"
#include "MainScene.h"

using namespace cocos2d;

class GameScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

	
	void setupBoard();
	void onUpdate(float dt);
	
	void doClose(Ref* pSender);
	cocos2d::SpriteFrameCache* gem2;
	typedef struct Gem
	{
		int gemType;
		cocos2d::Sprite *gemSprite;
		float yPos;
		float ySpeed;

	}Gem;
	//------------------------------------------------------------------------------------
	int kGemSize = 40;
	int kBoardWidth = 8;
	int kBoardHeight = 10;
	int kNumTotalGems = kBoardWidth * kBoardHeight;
	int kTimeBetweenGemAdds = 8;
	int kTotalGameTime = 1000 * 60;
	int kIntroTime = 1800;
	int kNumRemovalFrames = 8;
	int kDelayBeforeHint = 3000;
	int kMaxTimeBetweenConsecutiveMoves = 1000;

	double kGameOverGemSpeed = 0.1;
	double kGameOverGemAcceleration = 0.005;

	int kBoardTypeGem0 = 0;
	int kBoardTypeGem1 = 1;
	int kBoardTypeGem2 = 2;
	int kBoardTypeGem3 = 3;
	int kBoardTypeGem4 = 4;
	int kBoardTypePup0 = 5;

	typedef std::vector<Gem> Gems;
	Gems* gFallingGems;

	int* gBoard;

	bool gBoardChangedSinceEvaluation;
	int gPossibleMove;

	Vector<Sprite*> gBoardSprites;
	int* gNumGemsInColumn;
	float* gTimeSinceAddInColumn;

	
	//var gLastTakenGemTime;
	//var gNumConsecutiveGems;
	//var gIsPowerPlay;
	//var gPowerPlayParticles;
	//var gPowerPlayLayer;

	//var gGameLayer;
	//var gParticleLayer;
	//var gHintLayer;
	//var gShimmerLayer;
	//var gEffectsLayer;

	//var gTimer;

	//var gStartTime;
	//var gLastMoveTime;
	bool gIsDisplayingHint;



	bool gIsGameOver = false;
	//var gGameOverGems;
	//var gScoreLabel;
	//var gEndTimerStarted;


};

class TimerScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TimerScene);

	cocos2d::Sprite* timer;
	cocos2d::MenuItemImage* pMenuItem3;

	void gameTimer();
	void onPressPause(Ref* pSender);
};
#endif //__SceneTran1_GameScene__
