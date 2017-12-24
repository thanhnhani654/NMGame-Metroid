#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
//#include "../CollisionWorld.h"

using namespace std;

class GameObject
{
protected:
	D3DXVECTOR3 position;
	
public:
	int id;
	int DebugName;
	float vx, vy;
	float width, height;
	bool IsUpdate;
	bool IsCollision;
	GameObject()
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
		width = 0;
		height = 0;
		IsUpdate = true;
		IsCollision = true;
	}

	GameObject(float x, float y, float iwidth, float iheight);
	
	D3DXVECTOR3 GetPosition() { return position; }

	virtual void SetPosition(float x, float y, float z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}

	void SetPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void SetPosition(D3DXVECTOR3 pos) { position = pos;}

	virtual void UpdateInput();
	virtual void Update();
	virtual void Draw(int vx, int vy);

	virtual void Destroy() { };

	virtual bool OnCollision(GameObject *object) { return true; };

	void test() { MessageBox(NULL, L"123456", L"ABCDEF", MB_OK); }
};
