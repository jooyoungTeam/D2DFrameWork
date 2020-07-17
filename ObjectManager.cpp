#include "stdafx.h"
#include "ObjectManager.h"
#include "GameObject.h"
ObjectManager::ObjectManager()
{
	for (int i = 0; i < (int)ObjectType::End; i++)
	{
		mObjectContainer.insert(make_pair((ObjectType)i, vector<GameObject*>()));
	}
}
ObjectManager::~ObjectManager()
{
}
void ObjectManager::Release()
{
}

void ObjectManager::Update()
{
	ObjectContainerIter iter = mObjectContainer.begin();
	for (; iter != mObjectContainer.end(); ++iter)
	{
		vector<GameObject*>& objectList = iter->second;

		for (int i = 0; i < objectList.size(); i++)
		{
			if (objectList[i]->GetActive())
			{
				objectList[i]->Update();
			}
		}
	}
}

void ObjectManager::Render()
{
	ObjectContainerIter iter = mObjectContainer.begin();
	for (; iter != mObjectContainer.end(); ++iter)
	{
		vector<GameObject*>& objectList = iter->second;

		for (int i = 0; i < objectList.size(); i++)
		{
			if (objectList[i]->GetActive())
			{
				objectList[i]->Render();
			}
		}
	}
}

void ObjectManager::AddObject(ObjectType objectType, GameObject * newObject)
{
	// 맵, 언올더드맵을 배열 접근할때는 조심해야 하는 점이 있다.
	// 만약에 해당 키값의 데이터가 없으면 새로 생성한다
	// 사실은 find랑 똑같이 되어있다 내부는--> 배열 접근이라 느림
	mObjectContainer[objectType].push_back(newObject); //맵은 배열접근 가능
}

void ObjectManager::RemoveObject(ObjectType objectType, GameObject * deleteObject)
{
	vector<GameObject*> &objectList = mObjectContainer[objectType];
	for (int i = 0; i < objectList.size(); i++)
	{
		if (objectList[i] == deleteObject)
		{
			objectList[i]->Release();
			SAFE_DELETE(objectList[i]);
			objectList.erase(objectList.begin() + i);
			return;
		}
	}
}

GameObject * ObjectManager::FindObject(ObjectType objectType, string objectName)
{
	vector<GameObject*>& objectList = mObjectContainer[objectType];
	for (int i = 0; i < objectList.size(); i++)
	{
		if (objectList[i]->GetName() == objectName)
		{
			return objectList[i];
		}
	}

	return nullptr;
}

vector<class GameObject*> ObjectManager::FindObjects(ObjectType objectType, string objectName) // 숙제
{

	vector<GameObject*> objectList = mObjectContainer[objectType];
	vector<GameObject*> result;

	for (int i = 0; i < objectList.size(); i++)
	{
		if (objectList[i]->GetName() == objectName)
		{
			result.push_back(objectList[i]);
		}
	} 
	
	return result;

}