#pragma once
#include "gameNode.h"

class UI : public gameNode
{
private:
	Image* _test;

public:
	UI() {}
	~UI() {}


	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void realase();
};

