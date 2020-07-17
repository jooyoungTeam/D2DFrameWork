#pragma once
#include "gameNode.h"


class playGround : public gameNode
{
private:
	float _x, _y;
	int   _count;
	int   _frameX;
	int   _angleCount;
	//class GameObject* _Player;
	//vector<class Monster*> mMonsterList;
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	

};

