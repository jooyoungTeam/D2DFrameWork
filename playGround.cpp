#include "stdafx.h"
#include "playGround.h"
#include "Obstacle.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);
	CAMERA_M->settingCamera(0, 0, WINSIZEX, WINSIZEY, 0, 0,2016 - WINSIZEX, 672 - WINSIZEY);
	ImageManager::GetInstance()->AddImage("destTest", L"deskTest.png");

	ImageManager::GetInstance()->AddImage("TrapObject", L"TrapObject.png");
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	return S_OK;
}

//메모리 해제
void playGround::release()
{
	OBJECTMANAGER->Release();
}

//연산
void playGround::update()
{
	gameNode::update();
	
	CAMERA_M->setX(_x);
	CAMERA_M->setY(_y);

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x ++;
	}
}

//그리기 전용
void playGround::render()
{
	// 백버퍼 초기화
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::Black);
	{
		Image* backImg = ImageManager::GetInstance()->FindImage("destTest");
		CAMERA_M->render(backImg, 0, 0);

		RECT rc = RectMakeCenter(_x, _y, 100, 100);

		CAMERA_M->rectangle(FloatRect(rc), D2D1::ColorF::Blue, 1.f);

	}
	// 백버퍼에 그린 내용들을 화면에 뿌려라.
	D2DRenderer::GetInstance()->EndRender();
}
