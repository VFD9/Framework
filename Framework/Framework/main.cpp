// 2022.06.24 Framework Ver 2.2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

// Input

// 00000001 = 1
// 00000010 = 2
// 00000100 = 4
// 00001000 = 8
// 00010000 = 16
// 00100000 = 32
// 01000000 = 64
// 10000000 = 128

// Singleton
/*
	�����Ͱ� �� ������ �ְ� ��𿡼��� ����� �� �־�� �ϴ� ��
	������ó�� ����Ѵ�. �׷��� �ϳ��� ����� �����ڸ� private���� �����
*/

int main(void)
{
	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64(); // 1 / 1000 

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	
	return 0;
}