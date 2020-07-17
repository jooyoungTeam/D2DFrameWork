#include "stdafx.h"
#include "playGround.h"
#include "Player.h"
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

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	ImageManager::GetInstance()->AddImage("TrapObject", L"TrapObject.png");
	ImageManager::GetInstance()->AddFrameImage("Bomb", L"Bomb.png", 3, 1);

	ImageManager::GetInstance()->AddImage("destTest", L"deskTest.png");

	GameObject* _Player = new Player();
	_Player->Init();
	OBJECTMANAGER->AddObject(ObjectType::Player,_Player);

	GameObject* _obstacle = new Obstacle;
	_obstacle->Init();
	OBJECTMANAGER->AddObject(ObjectType::TileObject,_obstacle);

	CAMERA_M->settingCamera(0,0,WINSIZEX,WINSIZEY,0,0,2016 - WINSIZEX, 672 - WINSIZEY);


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
	OBJECTMANAGER->Update();
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 5;
	}	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 5;
	}	
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 5;
	}	
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 5;
	}

	CAMERA_M->setX(_x);
	CAMERA_M->setY(_y);

}

//그리기 전용
void playGround::render()
{
	// 백버퍼 초기화
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::Black);
	{
		Image* backImg = ImageManager::GetInstance()->FindImage("destTest");
		CAMERA_M->render(backImg,0,0);
		Image* img = ImageManager::GetInstance()->FindImage("TrapObject");

		img->SetSize(Vector2(100, 100));
		img->SetAngle(_x);
		img->SetScale(1.5f);
		img->SetAlpha(0.7f);
		CAMERA_M->render(img, _x, _y);	
	}
	// 백버퍼에 그린 내용들을 화면에 뿌려라.
	D2DRenderer::GetInstance()->EndRender();
}
