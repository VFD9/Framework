#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;

		return Instance;
	}
private:
	DWORD Key;
	bool Pressed;
public:
	DWORD GetKey() const { return Key; } // const�� ���� �ǵ帮�� ����� �ǹ�, ������ �Ұ����ؼ� ������ �Ұ���
public:
	void InputKey();
private:
	InputManager();
public:
	~InputManager();
};