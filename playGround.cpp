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
	

}

//�׸��� ����
void playGround::render()
{
	// ����� �ʱ�ȭ
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::Black);
	{

	}
	// ����ۿ� �׸� ������� ȭ�鿡 �ѷ���.
	D2DRenderer::GetInstance()->EndRender();
}
