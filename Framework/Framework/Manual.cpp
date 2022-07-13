#include "Manual.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"

Manual::Manual()
{
}

Manual::~Manual()
{
}

void Manual::Initialize()
{
}

void Manual::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ESCAPE)
		SceneManager::GetInstance()->SetScene(LOGO);
}

void Manual::Render()
{
	CursorManager::GetInstance()->WriteBuffer(1.0f, 16.0f, (char*)
		"==================================================================================================================================================================================\n");

	CursorManager::GetInstance()->WriteBuffer(78.0f, 20.0f, (char*)"�� : Ű���� ���� ����Ű");
	CursorManager::GetInstance()->WriteBuffer(78.0f, 21.0f, (char*)"�� : Ű���� �Ʒ��� ����Ű");
	CursorManager::GetInstance()->WriteBuffer(78.0f, 22.0f, (char*)"�� : Ű���� ���� ����Ű");
	CursorManager::GetInstance()->WriteBuffer(78.0f, 23.0f, (char*)"�� : Ű���� ������ ����Ű");
	CursorManager::GetInstance()->WriteBuffer(78.0f, 24.0f, (char*)"SPACE BAR : �Ѿ� �߻�");
	CursorManager::GetInstance()->WriteBuffer(78.0f, 25.0f, (char*)"ENTER : ȭ�� ��ȯ");
	CursorManager::GetInstance()->WriteBuffer(78.0f, 26.0f, (char*)"ESC : ���ư���");

	CursorManager::GetInstance()->WriteBuffer(1.0f, 30.0f, (char*)
		"==================================================================================================================================================================================\n");
}

void Manual::Release()
{
}