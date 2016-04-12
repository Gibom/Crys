#ifndef __SceneTran1_AboutScene__
#define __SceneTran1_AboutScene__

#include "cocos2d.h"
#include "MainScene.h"

using namespace cocos2d;

class AboutScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(AboutScene);

	cocos2d::MenuItemImage* pMenuItem3;

	void doClose(Ref* pSender);

	

};

#endif //__SceneTran1_AboutScene__
