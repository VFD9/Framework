// Framework Ver 0.3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Parent/Parent.h"
#include "Parent/Child/Child.h"
#include "Parent/Child/Bullet.h"

using namespace std;

// Ŭ���� - �����̱⵵ �ϰ� ������� �� �� �ִ�.
// ������Ʈ - Ŭ������ ������� �ִ�.
// static�� ���������� ��Ÿ������ �ö󰣴�. ��Ÿ�� ���Ŀ��� ���ð� ���� �ö󰣴�.

// 1. �������� - ��ü������ ����, ��ü�� ���� ��ü���� ������ �����Ű�� �ʵ��� �ϴ� ���																										
/*
	������ �Ұ����ϰ� Ư�� ������ ����� ���� ���������̶�� �Ѵ�. / ���濡 ����ϴ� ����
	(����� ���ɼ��� �ִ� �͵��� ���ܼ� �Ժη� �������� ���ϰ� �Ѵ�)

	�� Ư¡
	1. ��ü ���� ��ü���� ���յ��� ��ȭ���� ����� ��ü�� ������ ������ ��.
	2. ������ Ÿ���� �ٸ� ���� ��ü���� ��ü�����ν� ���� ��� ������ ������.
	3. ������ ��ü���� ������ ���� ���¿����� (�������̽� ������) ��Ȯ�� ���� �ڵ��� ������ ������

	private : �ڱ� �ڽŸ� ��� ����.
	protected : ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�.
	public : ������ ����
*/

// 2. ĸ��ȭ
/*
	������(����)�� ���(�Լ�)�� �������� ����ϴ� ��.
	������ ����� ���θ� ����ϰ� �Ѵ�.
*/

// 3. �߻�ȭ - Ư������ �ʰ� �������̴�.(�������̰� �Ϲ�ȭ�� Ư¡���� ����)
/*
	�������� �ʴ� ���¸� �߻� Ŭ������� �Ѵ�.
	��) ���, �л�, ���� ���� ����� Ư������ �ʴ� ���(�߻����� ���)
	��) "ȫ�浿�� �л��̴�." ��� ȫ�浿�̶�� Ư�� ����� �����Ƿ�, �߻��� ���·� �� �� ����.
*/

// 4. ��� - �θ� ��ü�� ���� �� �ڽ� ��ü�� ����� �� �ִ�.
/*
	�ڽ� Ŭ������ �θ� Ŭ�������� ����� �� �ִ�.(�ڵ��� ������ ����)
	�ٸ� �ڽ� Ŭ������ ������ ���� ��� �ڽ� Ŭ������ �ִ� ������ ���ȴ�.
	�θ� Ŭ������ �ִ°� �ڽ� Ŭ�������� �� ����� �Ǽ��� ������ �� ������ ����.
*/

// 5. ������ - Ư�� ���ֿ��� ���°� �޶� �������.
/*
	�پ��� ���·� ������ �� �ִ�.
	�θ� Ÿ���� ������ �� �ϳ��� ���� �ڽĵ��� ����� ȣ���� �� �ִ� ��
*/

// 6. namespace - ������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��.
/*
namespace AAA
{
	void Output()
	{
		cout << "ȫ�浿" << endl;
	}
}

namespace BBB
{
	void Output()
	{
		cout << "�Ӳ���" << endl;
	}
}

using AAA::Output;
*/

// 7. ������ & �Ҹ��� & ���� ������

/*
struct tagInfo
{
	int Number;
};

class Object
{
private:
protected:
	tagInfo m_Info;
public:
	int Number;
	char* Name;
public:
	virtual Object* Clone() = 0;
public:
	// ����ڰ� ȣ������ �ʾƵ� ������ ȣ���.
	// Ŭ������ ������ ���� ȣ��
	Object()
	{
		cout << "������" << endl;
	};

	// ����ڰ� ȣ���ϴ� ������ ȣ���.
	// ���ް��� ������ �ڷ����� ���� ������(�ڵ�)���� ȣ���.
	Object(int _Number) : Number(_Number)
	{
		cout << "���� ������ : int" << endl;

		//Number = _Number;
	};
	Object(float _Number)
	{
		cout << "���� ������ : float" << endl;

		Number = (int)_Number;
	};

	Object(char* _Name)
	{
		Name = new char[strlen(_Name) + 1];
		strcpy(Name, _Name);
	};

	// Ŭ������ �����Ǳ� ����
	~Object()
	{
		cout << "�Ҹ���" << endl;

		delete Name;
		//Name = nullptr;
	};

	Object(Object* _obj)
	{
		Name = new char[strlen(_obj->Name) + 1];
		strcpy(Name, _obj->Name);
	};

	Object(tagInfo _Info) : m_Info(_Info)
	{

	}
};

class Player : public Object
{
public:
	virtual Object* Clone() override { return new Player(*this); }

	void Output() { cout << m_Info.Number << endl; }

public:
	Player() {};

	Player(tagInfo _Info) : Object(_Info) {};
	~Player() {};
};
*/

//map<string, Object*> PrototypeObject;
//
//Object* GetObject(string _Key);

// 8. ���� ����, ���� ����
/*
	���� ����(Shallow Copy)�� '�ּ� ��'�� �����ϱ� ������ �����ϰ� �ִ� �������� ����.
	���� ����(Deep Copy)�� '���� ��'�� ���ο� �޸� ������ �����ϴ� ���̴�.
	�����Ҷ� �ּҸ� ����� ��쿡�� �ȿ� �ִ� ���� ���簡 �����ϵ��� ���Ӱ� �����Ҵ��� ���־���Ѵ�.
*/

// 9. �����ε� & �������̵� - ��� ȣ���� �������� �ٽ�
/*
	�����ε��� ��������ڿ� ���� ���·� ��밡���ϰ�, �Ű������� �ٸ� ��� �ٸ� ����� �Ѵ�.
	�̸��� ������ �ñ״�ó(�Ķ���� ��, Ÿ��)���� �ٸ� �޼��带 �ߺ� �����ϴ� ���� �ǹ��Ѵ�.

	�������̵��� ����� ������ ���ԵǸ�, �Ļ�Ŭ�������� ����� �����ϴ�. �׸��� �����ε��� ��ü�� �������̵��� �� �ִ�.
	�θ� Ŭ������ �޼����� ���� ����� �������Ͽ� ����ϴ� ���� �ǹ��Ѵ�.

	�� �����ε��� ���� Ÿ���� �����̵��� ������� �Ű������� Ÿ���� �޶�������� �������̵��� �����ؾ��Ѵ�. 
*/

/*
class Object
{
public:
	virtual void Output()
	{
		cout << "Object : " << endl;
	}

	void Output(string _str)
	{
		cout << "Object : " << _str << endl;
	}
};

class AAA : public Object
{
public:
	void Output() override
	{
		cout << "AAA : " << endl;
	}

	void Output(string _str)
	{
		cout << "AAA : " << _str << endl;
	}
};
*/

// 10. ������ �����ε� - �����ڿ� ���Ƿ� ������ ����� �����ϵ��� �ϴ� ��
struct tagInfo
{
	int Number;

	tagInfo() {};
	tagInfo(int _Number) : Number(_Number) {};
};

class Object
{
private:
	tagInfo Info;
public:
	Object& operator+=(const Object& _Obj)
	{
		Info.Number += _Obj.Info.Number;
		return *this;
	}

	Object& operator++()
	{
		Info.Number += 1;
		return *this;
	}

	Object& operator--()
	{
		Info.Number -= 1;
		return *this;
	}

	void Output()
	{
		cout << Info.Number << endl;
	}
public:
	Object() {}
	Object(tagInfo _Info) : Info(_Info) {}
	~Object() {}
};

// 11. ������ (����) & ĸ��ȭ

int main(void)
{
	/*
	Object o1((char*)"ȫ�浿");
	o1.Number = 10;
	Object o2(o1);
	o1.Name = (char*)"�Ӳ���";

	cout << o2.Number << endl;
	cout << o1.Name << endl;
	cout << o2.Name << endl;
	*/

	/*
	tagInfo Info;
	Info.Number = 10;

	AAA a[8];

	for (int i = 0; i < 8; ++i)
	{
		Info.Number = i;
		a[i] = AAA(Info);
	}

	for (int i = 0; i < 8; ++i)
		a[i].Output();
	*/

	/*
	tagInfo Info;

	Info.Number = 10;
	PrototypeObject["Player"] = new Player(); // Player�� �����Ҵ���

	Object* pProtoObj = GetObject("Player"); // ������Ʈ �����Ϳ� GetObject�� �������ش�.

	Object* pPlayer = nullptr;

	if (pProtoObj != nullptr)
		pPlayer = pProtoObj->Clone();
	*/

	Object o1(tagInfo(10));
	Object o2(o1);

	o2 += o1;
	++o2;
	o2.Output();

	return 0;
}
/*
Object* GetObject(string _Key)
{
	map<string, Object*>::iterator iter = PrototypeObject.find(_Key);

	if (iter == PrototypeObject.end())
		return nullptr;
	else
		return iter->second;
}
*/