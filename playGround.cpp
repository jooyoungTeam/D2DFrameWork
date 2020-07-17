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
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

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
	
	CAMERA_M->setX(_x);
	CAMERA_M->setY(_y);

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x ++;
	}
}

//�׸��� ����
void playGround::render()
{
	// ����� �ʱ�ȭ
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::Black);
	{
		Image* backImg = ImageManager::GetInstance()->FindImage("destTest");
		CAMERA_M->render(backImg, 0, 0);

		RECT rc = RectMakeCenter(_x, _y, 100, 100);

		CAMERA_M->rectangle(FloatRect(rc), D2D1::ColorF::Blue, 1.f);

	}
	// ����ۿ� �׸� ������� ȭ�鿡 �ѷ���.
	D2DRenderer::GetInstance()->EndRender();
}
