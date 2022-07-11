#include "Bullet.h"
#include "Bridge.h"

Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { Release(); }


Object* Bullet::Initialize(string _Key)
{
	strKey = _Key;

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(float(strlen(Buffer[0])), (float)MAX_SIZE);

	TransInfo.Direction = Vector3(0.0f, 0.0f);

	if (pBridge)
		pBridge->Initialize();

	return this;
}

int Bullet::Update()
{
	// Target�� ��ǥ - ���� ��ǥ => ���� Ÿ�� ������ ����
	// 1���� �۾����� ������ �ٲ�� ������ ���ϴ�(��Ÿ����� ����)

	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Bullet::Render()
{
	//for (int i = 0; i < MAX_SIZE; ++i)
	//{
	//	CursorManager::GetInstance()->WriteBuffer(
	//		TransInfo.Position.x + (TransInfo.Scale.x + 16.0f),
	//		TransInfo.Position.y + i,
	//		Buffer[i], Color);
	//}

	if (pBridge)
		pBridge->Render();
}

void Bullet::Release()
{
	delete pBridge;
	pBridge = nullptr;
}

