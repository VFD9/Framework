// 2022.07.05 Framework Ver 10.1 ( ObjectPool)
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

// ��µǴ°� �������� GetTickCount64()�� �� ����ϱ⵵ ���� �ʱ�ȭ�Ǽ� ȭ���� ���� �����Ÿ���.
// �̸� �ذ��ϱ� ���ؼ��� ���۸� �߰��� ������ְ� ������Ʈ�� ��� ���ۿ� ����� ����ϴ� ���۷� �����Ѵ�.

int main(void)
{
	system("title ������ - flight Shooting Game");

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
			Main.Render(); 
		}
	}
	
	return 0;
}
