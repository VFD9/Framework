#pragma once
#include "Object.h"

class BackGround : public Object
{
private:
	char* TextureList[8];
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new BackGround(*this); }
public:
	BackGround();
	BackGround(Transform _TransInfo);
	virtual ~BackGround();
};

