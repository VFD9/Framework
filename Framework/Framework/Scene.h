#pragma once
#include "Headers.h"

class Scene
{
protected:
	string str;
public:
	virtual void Initialize()PURE; // PURE�� ���� ���� �Լ��� �ǹ��ϴ� = 0 �� �ǹ��Ѵ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Scene();
	Scene(string _str);
	~Scene();
};