#pragma once // ������� �ߺ� �����뵵(cpp���Ͽ��� �������� �ʴ´�)

class MainUpdate
{
private:
	int SceneState;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};