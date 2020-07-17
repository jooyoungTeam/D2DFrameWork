#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	void Init()override;
	void Release()override;
	void Update()override;
	void Render()override;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float angle, float speed);
};

