#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Main : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(Main);


	//Menu
	cocos2d::Sprite* pMenuItem1;
	cocos2d::Sprite* pMenuItem2;


	//Sound
	unsigned int m_nSoundId;
	void doSoundAction(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
