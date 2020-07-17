//test boooooooooom
#include "stdafx.h"
#include "Player.h"
#include "Obstacle.h"

Player::Player()
{
	mName = "Player";
	mPosition = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	mSize = Vector2(50, 50);
	mRect = RectMakePivot(mPosition, mSize, Pivot::Center);
	mActive = true;
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Release()
{
}

void Player::Update()
{
	// 왼
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		Move(Vector2(-1.f, 0.f), 100.0f);
	}
	// 오
	else if (KEYMANAGER->isStayKeyDown('D'))
	{
		Move(Vector2(1.f, 0.f), 100.f);
	}
}

void Player::Render()
{
	D2DRenderer::GetInstance()->DrawRectangle(mRect, D2DRenderer::DefaultBrush::Red, 1.f);
}

void Player::Move(Vector2 moveDirection, float speed)
{
	// 예시 1
	mPosition.x += moveDirection.x * speed * TIMEMANAGER->getElapsedTime();
	mPosition.y += moveDirection.y * speed * TIMEMANAGER->getElapsedTime();
	mRect = RectMakePivot(mPosition, mSize, Pivot::Center);

	// 예시 2
	//mPosition += moveDirection * speed * TIMEMANAGER->getElapsedTime();
	//mRect = RectMakePivot(mPosition, mSize, Pivot::Center);
	GameObject* obstacle = OBJECTMANAGER->FindObject(ObjectType::TileObject,"Obstacle");
	if (obstacle != nullptr)
	{
		RECT temp;
		if (IntersectRect(&temp, &mRect.GetRect(), &obstacle->GetRect().GetRect()))
		{
			//Obstacle* castObstacle = (Obstacle*)obstacle;             // 이런식으로 형변환 ㄴㄴ(안정성 떨어짐) 캐스팅 방법이 많음
			Obstacle* castObstacle = dynamic_cast<Obstacle*>(obstacle); // 실패를하면 null값이 변환이 되어서 온다.
			if (castObstacle != nullptr)
			{	
				castObstacle->onCollsion();
			}

		
		}
	}


}

void Player::MoveAngle(float angle, float speed)
{
	mPosition.x += cosf(angle) * speed * TIMEMANAGER->getElapsedTime();
	mPosition.y -= sinf(angle) * speed * TIMEMANAGER->getElapsedTime();
	mRect.Update(mPosition,mSize,Pivot::Center);
}
