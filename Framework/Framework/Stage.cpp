#include "Stage.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"

Stage::Stage() : pPlayer(nullptr) {}

Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	// 1. ��ȯ���°� Object* �̰ų� && list<Object*>
	// 2. Key �� ���޵Ǿ�� ��.
	//list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	//
	//if(pPlayerList != nullptr)
	//	pPlayer = pPlayerList->front();
	Object* pEnemyProto = new Enemy;
	pEnemyProto->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1))); // 8����Ʈ�� 4����Ʈ�� ĳ��Ʈ�ؼ� �ߴ� ���

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(118.0f, float(rand() % 30));

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Update()
{	// l ����, r ����
	ObjectManager::GetInstance()->Update();

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("��");

	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin(); iter != pBulletList->end();)
		{
			if ((*iter)->GetPosition().x >= 120.0f)
				iter = pBulletList->erase(iter); // 120.0f �� ��ġ�� �ִ°� ����� ���ʿ� �ִ°� �ٿ��� ����
			else
				++iter; // �̸� iter�� ������Ű�� 120.0f�� �Ѵ��� Ȯ���� ����� ����.
		}
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}