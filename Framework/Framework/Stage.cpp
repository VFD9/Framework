#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ScrollBox.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Stage::Stage() : Check(0) {}

Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;

	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();

	pUI = new ScrollBox;
	pUI->Initialize();

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
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
		Enable_UI();

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
			else if ((*iter)->GetPosition().x >= 59.5f && (*iter)->GetPosition().y >= 14.5f)
				iter = pBulletList->erase(iter);
			else
				++iter; // �̸� iter�� ������Ű�� 120.0f�� �Ѵ��� Ȯ���� ����� ����.
		}
	}

	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin(); Enemyiter != pEnemyList->end(); ++Enemyiter) // Enemyiter�� pEnemyList�� ����
			{
				if (CollisionManager::Collision(pPlayer, *Enemyiter)) // pPlayer�� Enemyiter�� �浹���� �˻�
				{
					//CursorManager::Draw(50.0f, 1.0f, "�浹�Դϴ�.");
				}

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin(); Bulletiter != pBulletList->end(); ++Bulletiter) // Bulletiter�� pBulletList�� ����
					{
						if (CollisionManager::Collision(*Bulletiter, *Enemyiter)) // pPlayer�� *Enemyiter�� �浹���� �˻�
						{
							//CursorManager::Draw(50.0f, 1.0f, "�浹�Դϴ�.");
						}
					}
				}
			}
		}
	}

	if (Check)
		pUI->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	if (Check)
		pUI->Render();
}

void Stage::Release()
{
	
}

void Stage::Enable_UI()
{
	Check = !Check;
}
