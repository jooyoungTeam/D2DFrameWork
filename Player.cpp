#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	_idle = new idleState();
	_move = new moveState();
	_jump = new jumpState();

	_state = _idle;
	//ImageManager::GetInstance()->AddImage("PLAYER_IDLE", L"KakaoTalk_20200717_151452472.bmp");
	//_img = ImageManager::GetInstance()->FindImage("PLAYER_IDLE");

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2 + 100;
	_playerX = _x;
	_playerY = _y - 110;
	//int rightIdle[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_IDLE", "PLAYER_IDLE", rightIdle, 12, 10, true);
	//int leftIdle[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_LEFT_IDLE", "PLAYER_IDLE", leftIdle, 12, 10, true);
	//int rightRun[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_RUN", "PLAYER_WALK", rightRun, 12, 10, true);
	//int leftRun[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_LEFT_RUN", "PLAYER_WALK", leftRun, 12, 10, true);
	//int rightJump[] = { 2 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_JUMP", "PLAYER_JUMP", rightJump, 3, 3, true);
	//int leftJump[] = { 3 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_LEFT_JUMP", "PLAYER_JUMP", leftJump, 3, 3, true);
	//int rightFall[] = { 1 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_JUMP", "PLAYER_JUMP", rightFall, 3, 3, true);
	//int leftFall[] = { 4 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_JUMP", "PLAYER_JUMP", leftFall, 3, 3, true);
	//int rightLanding[] = { 0 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_JUMP", "PLAYER_JUMP", rightLanding, 3, 3, true);
	//int leftLanding[] = { 5 };
	//KEYANIMANAGER->addArrayFrameAnimation("P_RIGHT_JUMP", "PLAYER_JUMP", leftLanding, 3, 3, true);
	//_jumpPower = _gravity = 0;
	_rc = RectMakeCenter(_x, _y, 80, 30);
	_player = RectMakeCenter(_playerX, _playerY, 100, 200);
	//_playerMotion = KEYANIMANAGER->findAnimation("P_RIGHT_IDLE");
	//_playerMotion->start();

	_isJumping = false;


	_probeBottom = _rc.bottom;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	//KEYANIMANAGER->update();
	_probeBottom = _rc.bottom;
	_playerX = _x;


	CAMERA_M->setX(_x);
	CAMERA_M->setY(_y);



	//_playerY = _y - 110;
	_state->update(*this);
	//for (int i = _probeBottom - 10; i < _probeBottom; ++i)
	//{
		COLORREF color = GetPixel(ImageManager::GetInstance()->FindImage("pixel1")., (_rc.right + _rc.left) / 2, i);

	//	int r = GetRValue(color);
	//	int g = GetGValue(color);
	//	int b = GetBValue(color);

	//	if (r == 255 && g == 0 && b == 255)
	//	{
	//		//cout << "ต้" << endl;
	//		_isMove = true;
	//		_rc.bottom += 10;
	//		_rc.top += 10;
	//	}
	//	else
	//	{
	//		//cout << "ต้" << endl;
	//		_isMove = false;
	//	}


	//}
	if (!_isMove)
	{
		_y += 3;

	}
	if (!_isJumping)
	{
		_playerY = _y - 110;
	}



	_rc = RectMakeCenter(_x, _y, 80, 30);
	_player = RectMakeCenter(_playerX, _playerY, 100,200);


	cout << _isJumping << endl;
}

void player::render()
{
	//Rectangle(getMemDC(), (_rc.right + _rc.left) / 2 - 10, _probeBottom, _rc.right + _rc.left / 2, _probeBottom + 10);

	CAMERA_M->rectangle(_player, D2D1::ColorF::Black, 1.f);

	CAMERA_M->rectangle(_rc, D2D1::ColorF::Black, 1.f);


	//_img->aniRender(getMemDC(), _player.left, _player.top, _playerMotion);

}