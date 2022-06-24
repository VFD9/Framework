#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h" // Scene.h ������ �߻�Ŭ������ ���� �߰��ص� �� �� ������ �Ļ� Ŭ�������� ��� ������ �߰��Ѵ�.

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) {} // ������ ����Ǹ� �ʱ�ȭ�� �ݵ�� ���־�� �Ѵ�

SceneManager::~SceneManager() { Release(); }

void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr)
		::Safe_Delete(SceneState); // �ƹ��͵� ���� ::(���ӽ����̽�)�� ���� ��� inline �Լ���� ���� �˸��� �ǹ��̴�.

	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;
		break;

	case EXIT:
		exit(NULL);
		break;
	}

	SceneState->Initialize();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState); // �����ؾ��� �� �ִٸ� ���������� ���� Release�Լ��� �ְ� �Ҹ��ڿ� �� Release�Լ��� �־��ָ� �ȴ�.
}