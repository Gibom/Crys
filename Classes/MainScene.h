#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(MainScene);


	//Menu
	cocos2d::MenuItemImage* pMenuItem1;
	cocos2d::MenuItemImage* pMenuItem2;
	void selectMenu(Ref* pSender);

	//Sound
	unsigned int m_nSoundId;
	void doSoundAction(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
