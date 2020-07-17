#include "stdafx.h"
#include "playGround.h"
#include "Obstacle.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);
	CAMERA_M->settingCamera(0, 0, WINSIZEX, WINSIZEY, 0, 0,2016 - WINSIZEX, 672 - WINSIZEY);
	ImageManager::GetInstance()->AddImage("destTest", L"deskTest.png");

	ImageManager::GetInstance()->AddImage("TrapObject", L"TrapObject.png");
	_player = new player;
	_player->init();



	return S_OK;
}

//�޸� ����
void playGround::release()
{
	OBJECTMANAGER->Release();
}

//����
void playGround::update()
{
	gameNode::update();


	_player->update();
}

//�׸��� ����
void playGround::render()
{
	// ����� �ʱ�ȭ
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::Black);
	{
		Image* backImg = ImageManager::GetInstance()->FindImage("destTest");
		CAMERA_M->render(backImg, 0, 0);

		//RECT rc = RectMakeCenter(_x, _y, 100, 100);
		//
		//CAMERA_M->rectangle(FloatRect(rc), D2D1::ColorF::Blue, 1.f);

		_player->render();

	}
	// ����ۿ� �׸� ������� ȭ�鿡 �ѷ���.
	D2DRenderer::GetInstance()->EndRender();
}
