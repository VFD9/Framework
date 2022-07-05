#pragma once
#include "Headers.h"

class Scene
{
protected:
	int Score;
public:
	virtual void Initialize()PURE; // PURE�� ���� ���� �Լ��� �ǹ��ϴ� = 0 �� �ǹ��Ѵ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetScore(int _Score) { Score = _Score; }
	int GetScore() const { return Score; }
public:
	Scene();
	virtual ~Scene();
};