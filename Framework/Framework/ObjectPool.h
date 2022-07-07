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
	static map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	static map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisableList() { return &DisableList; }
	void Update();
	void CatchObject(Object* _Object);
private:
	ObjectPool();
public:
	~ObjectPool();
};

