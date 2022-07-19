#include "BackGround.h"
#include "CursorManager.h"

BackGround::BackGround() : TextureList() {}
BackGround::BackGround(Transform _TransInfo) : Object(_TransInfo), TextureList() {}
BackGround::~BackGround() {}

Object* BackGround::Initialize(string _Key)
{
    strKey = "BackGround";

    TextureList[0] = (char*)
        "�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�";

    TextureList[1] = (char*)
        "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
    TransInfo.Position = Vector3(0.0f, 47.0f);
    TransInfo.Rotation = Vector3(0.0f, 0.0f);
    TransInfo.Scale = Vector3(0.0f, 6.0f);

    return this;
}

int BackGround::Update()
{
    return 0;
}

void BackGround::Render()
{
    //for (int i = 0; i < 6; ++i)
    //    CursorManager::GetInstance()->WriteBuffer(
    //        TransInfo.Position.x, 
    //        TransInfo.Position.y - (TransInfo.Scale.y * 0.5f) + i,
    //        TextureList[i]);

    CursorManager::GetInstance()->WriteBuffer(0.0f, 1.0f, TextureList[0]);
    CursorManager::GetInstance()->WriteBuffer(0.0f, 48.0f, TextureList[1]);
 
}

void BackGround::Release()
{
}
