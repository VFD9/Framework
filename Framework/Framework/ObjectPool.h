#pragma once
#include "Headers.h"

class Object; // Ŭ���� ���漱��, ���� �ϰ� ���������� �ʾƼ� �����ͷ� �ٷ�� �Ѵ�.
class ObjectPool
{
private:
	static ObjectPool* Instance;
public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool();

		return Instance;
	}
private:
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	void AddObject(string _Key, list<Object*> _List);
	void AddObject(Object* _Object);
	void Update();
private:
	ObjectPool();
public:
	~ObjectPool();
};
