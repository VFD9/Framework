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
	
	return &iter->second;
}

void ObjectManager::Update()
{	// ObjectManager�� ���� Enemy�� ����
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter) // map���� ���� ObjectList�� iter �ݺ��ڷ� ����
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end();) // map �ι�°�� Value�� iter2 �ݺ��ڸ� ����� iter�� �ι�°�� ����
		{
			int result = (*iter2)->Update(); // Update() �Լ��� Enemy�� ��ġ�� ��� �������� �̵��ϱ� ������ 0���ϰ� �Ǵ� ��찡 ����µ� �׶� ���� 1(BUFFER_OVER)�� ��ȯ�Ѵ�.

			if (result == BUFFER_OVER) // ��ȯ�� ���ڰ� 1(BUFFER_OVER)�� ��� ����Ǵ� ���� ���ǹ�
			{
				Object* Temp = *iter2; // iter2�� �ӽ� ������Ʈ Temp�� ����

				iter2 = iter->second.erase(iter2); // �ݺ��� iter2 ������ 1��° ����Ʈ�� �����ϰ� iter2�� ����

				delete Temp;
				Temp = nullptr; // �ӽ� ������Ʈ Temp�� ���� �� �ʱ�ȭ
			}
			else
				++iter2; // �ƴҰ�� iter2 ����
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
