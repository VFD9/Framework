// 2022.06.30 Framework Ver 7.0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

/*
template <typename T1>
class Temp
{
public:
	template <typename T2>
	static T1* Func()
	{
		return new T1;
	}
	static T1* Func(int i)
	{
		return new T1(i);
	}
	static T1* Func(float f)
	{
		return new T1(f);
	}
};

class A
{
public:
	int Number;
};

class B
{
public:
	int Number;
};


int main(void)
{
	A* a = Temp<A>::Func<B>();
	a->Number = 10;
}
	// �Լ� �̸� ���� <���ø�>�� �ٿ��� ����Ѵ�.
	// �ڵ尡 ���������Ű������� ����� ��������. �������� ��������.
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