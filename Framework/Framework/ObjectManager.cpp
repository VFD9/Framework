#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() {}

ObjectManager::~ObjectManager() {}

void ObjectManager::AddObject(Object* _Object)
{
	// ObjectList
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end()) // ObjectList�� �ƹ��͵� �������� �ʴ� ���
	{
		list<Object*> TempList; // Player, Enemy �� ��� �ӽ� ����(TempList) ����
		TempList.push_back(_Object); // TempList�� push_back���� �ִ´�
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object); // string�� �̹� ������ ��� list<Object*> �� _Object�� �ִ´�.
}

list<Object*>* ObjectManager::GetObjectList(string _strKey) // ������ ������ ���� �����ͷ� �������.
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_strKey);

	if (iter == ObjectList.end())
		return nullptr;
	else
		return &iter->second;
}

void ObjectManager::Update()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter) // ObjectManager�� ���� Enemy�� ����
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			int result = (*iter2)->Update();

			if (result == 1)
			{
				Object* Temp = *iter2;

				iter2 = iter->second.erase(iter2);

				delete Temp;
				Temp = nullptr;
			}
			else
				++iter2;
		}
	}
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
