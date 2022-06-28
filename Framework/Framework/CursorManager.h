#pragma once
#include "Headers.h"

class CursorManager
{
public:
	static void SetCursorPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y }; // COORD ����ü
		SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), Pos); // ǥ�� �ܼ�â�� �ִ� ��(GetStdHandle(STD_OUTPUT_HANDLE))�� Ŀ���� ��ġ�� �ٲ��ִ� �Լ�
	}

	static void Draw(float _x, float _y, string _str)
	{
		SetCursorPosition(_x, _y);
		cout << _str;
	}
};

