#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#define RANDOM_INT(MIN, MAX) ((MIN) + random() % ((MAX + 1) - (MIN)))
#include "cocos2d.h"
using namespace cocos2d;

class MainScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(MainScene);


	//Menu
	cocos2d::MenuItemImage* pMenuItem1;
	cocos2d::MenuItemImage* pMenuItem2;
	void onPressPlay(Ref* pSender);
	void onPressAbout(Ref* pSender);
	
	cocos2d::SpriteFrameCache* gem;
	char str[100] = { 0 };
	Vector<Sprite*> gem_;
	Sprite* sprt;
	Vec2 cmp;
	
	//Sound
	unsigned int m_nSoundId;
	void doSoundAction(Ref* pSender);
	void onUpdate();
	void showParticle();
	void showGem(float dt);
	void delGem(float dt);

	
	

};

#endif // __HELLOWORLD_SCENE_H__
