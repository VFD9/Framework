// 2022.06.23 Framework Ver 1.2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

// Ŭ���� ���ο��� �Լ��� �����ϸ� �ζ��� �Լ�ó�� ���ȴ�.

// 11. ������ (����) & ĸ��ȭ
// ĸ��ȭ - ���(�Լ�)�� �����͸� ������� ����

// [������]
/*
	1. * : ������, & : �ּҹ�ȯ ������
	2. �����ͺ������ [�����Ҵ�] - Ȯ���� ���ٸ� �����Ҵ���� �ϴ����� ����.
	3. Ŭ������ ����ü�� [.](��) �ƴϸ� [->](ȭ��ǥ)�� ����
	4. [�����Ҵ�] �ߴٸ� �ݵ�� [�Ҵ�����] => ���� ������ �޸� ������ �߻��Ѵ�.
*/

// inline �Լ� - ���� �����ų �� �ֵ��� �����ִ� �����
// const - ���ȭ Ű����, �� ������ ���� ����� �ǹ��̱⵵ �ϴ�.
// & ��� �ñ�
/*
	�� 2�� ������ ���
	1. &�� ��Ʈ�������� ������ �ϰԵȴ�.
	2. &&�� ���� �������� and�� ������ �ϰ� �ȴ�.

	�� ������ ���
	1. �׸� ���ʿ� ���� ��� �ּ� ��ȯ �����ڰ� �ȴ�.
	2. ���۷��� ������ - Call by Reference���� �Ļ��� �ǹ�
	���� �����ϴ� ���� �ƴ� �� ��ü�� �����ͼ� ����ϴ� ���̴�.
*/

// GetTickCount �뷫 49��
// GetTickCount64 �뷫 5���

// Singleton
/*
	�����Ͱ� �� ������ �ְ� ��𿡼��� ����� �� �־�� �ϴ� ��
	������ó�� ����Ѵ�. �׷��� �ϳ��� ����� �����ڸ� private���� �����
*/

/*
class Singleton
{
private:
	static Singleton* Instance; // �����͸� ������ ������ ���
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;

		return Instance;
	}
private:
	int Number;
public:
	int GetNumber() const { return Number; }
	void SetNumber(const int& _Number) { Number = _Number; }
private:
	Singleton() : Number(0) {}
public:
	~Singleton() {}
};

Singleton* Singleton::Instance = nullptr;
*/

int main(void)
{
	/*
	Singleton::GetInstance()->SetNumber(10);
	cout << Singleton::GetInstance()->GetNumber() << endl;
	*/


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