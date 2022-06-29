#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"


Stage::Stage() {}

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
		//pEnemy->SetPosition(118.0f, float(rand() % 30));
		pEnemy->SetPosition(float(rand() % 118), float(rand() % 30));

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Update()
{	// l ����, r ����
	ObjectManager::GetInstance()->Update();

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			iter != pBulletList->end();)
		{
			if ((*iter)->GetPosition().x >= 120.0f)
				iter = pBulletList->erase(iter); // 120.0f �� ��ġ�� �ִ°� ����� ���ʿ� �ִ°� �ٿ��� ����
			else
				++iter; // �̸� iter�� ������Ű�� 120.0f�� �Ѵ��� Ȯ���� ����� ����.
		}
	}

	if (pEnemyList != nullptr && pBulletList != nullptr)
	{
		for (list<Object*>::iterator Bulletiter = pBulletList->begin(); Bulletiter != pBulletList->end(); ++Bulletiter)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin(); Enemyiter != pEnemyList->end(); ++Enemyiter)
			{
				if (CollisionManager::Collision(*Bulletiter, *Enemyiter))
				{
					CursorManager::Draw(50.0f, 1.0f, "�浹�Դϴ�.");
				}
			}
		}
	}

	if (pPlayer != nullptr && pEnemyList != nullptr)
	{
		for (list<Object*>::iterator Enemyiter = pEnemyList->begin(); Enemyiter != pEnemyList->end(); ++Enemyiter)
		{
			if (CollisionManager::Collision(pPlayer, *Enemyiter))
			{
				CursorManager::Draw(50.0f, 1.0f, "�浹�Դϴ�.");
			}
		}
	
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	
}