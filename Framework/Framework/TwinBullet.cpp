#include "TwinBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

TwinBullet::TwinBullet() {}

TwinBullet::~TwinBullet() {}

void TwinBullet::Initialize()
{
    Speed = 1.35f;
    Color = 13;

    //Speed = 1.2f;
    //Color = 12;
}

int TwinBullet::Update(Transform& Info)
{
    Info.Direction = MathManager::GetDirection(
        Info.Position, Vector3(180.0f, Info.Position.y));

    Info.Position += Info.Direction * Speed;

    return 0;
}

void TwinBullet::Render()
{
    CursorManager::GetInstance()->WriteBuffer(
        pObject->GetPosition().x + (pObject->GetScale().x * 0.5f),
        pObject->GetPosition().y - (pObject->GetScale().y * 0.5f),
        (char*)"��",
        Color);
    
    CursorManager::GetInstance()->WriteBuffer(
        pObject->GetPosition().x + (pObject->GetScale().x * 0.5f),
        pObject->GetPosition().y + (pObject->GetScale().y * 0.25f),
        (char*)"��",
        14);

    //CursorManager::GetInstance()->WriteBuffer(
    //    pObject->GetPosition().x + (pObject->GetScale().x),
    //    pObject->GetPosition().y - pObject->GetScale().y * 0.33f,
    //    (char*)"��", Color);
}

void TwinBullet::Release()
{
}
