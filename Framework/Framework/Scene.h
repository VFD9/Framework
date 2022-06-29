#pragma once
#include "Headers.h"

class Scene
{
public:
	virtual void Initialize()PURE; // PURE�� ���� ���� �Լ��� �ǹ��ϴ� = 0 �� �ǹ��Ѵ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};