#pragma once
#include "gameNode.h"

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

class playerState;
class idleState;
class moveState;
class jumpState;

class player : public gameNode
{
private:
	playerState* _state;
	Image* _img;
	FloatRect _rc;
	FloatRect _player;

	int _probeBottom;
	bool _isMove;
	bool _isJumping;

	float _x, _y;
	float _frameX, _frameY;
	float _playerX, _playerY;

	bool _direction;		//left = 0, right = 1

	float _jumpPower, _gravity;


	animation* _playerMotion;


	playerState* _idle;
	playerState* _move;
	playerState* _jump;

public:
	player() {}
	virtual ~player() {}

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setState(playerState* state)
	{
		this->_state = state;
	}
	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setPlayerX(float playerX) { _playerX = playerX; }
	void setPlayerY(float playerY) { _playerY = playerY; }
	float getPlayerX() { return _playerX; }
	float getPlayerY() { return _playerY; }
	void setAni(animation* ani, Image* img) { _img = img;  _playerMotion = ani; _playerMotion->start(); }
	bool getDirection() { return _direction; }
	void setDirection(bool direction) { _direction = direction; }
	bool getIsMove() { return _isMove; }
	float getJumpPower() { return _jumpPower; }
	float getGravity() { return _gravity; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }
	void setGravity(float gravity) { _gravity = gravity; }
	bool getIsJumping() { return _isJumping; }
	void setIsJumping(bool jumping) { _isJumping = jumping; }
	playerState* getIdleState() { return _idle; }
	playerState* getMoveState() { return _move; }
	playerState* getJumpState() { return _jump; }
};


class playerState
{
public:
	virtual ~playerState() {}
	virtual void update(player& player) {}
public:
	static idleState* idle;
	static moveState* move;
	static jumpState* jump;
};

class idleState : public playerState
{
public:
	virtual void update(player& player) override;
};

class moveState : public playerState
{
public:
	virtual void update(player& player) override;
};

class jumpState : public playerState
{
public:
	virtual void update(player& player) override;
};


