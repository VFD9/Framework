// 2022.07.04 Framework Ver 9.3-1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

int main(void)
{
	system("title ������ - �÷���");

	system("mode con cols=120 lines=30"); // ������ 120, 30 ������� �����ִ� ��

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
			Main.Render(); // ��µǴ°� �������� GetTickCount64()�� �� ����ϱ⵵ ���� �ʱ�ȭ�Ǽ� ȭ���� ���� �����Ÿ���.
						   // �̸� �ذ��ϱ� ���ؼ��� ���۸� �߰��� ������ְ� ������Ʈ�� ��� ���ۿ� ����� ����ϴ� ���۷� �����Ѵ�.
		}
	}
	
	return 0;
}