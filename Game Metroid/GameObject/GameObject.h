#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

class GameObject
{
protected:
	D3DXVECTOR3 position;
	
	
public:
	int id;
	float vx, vy;
	float width, height;
	GameObject()
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
		width = 0;
		height = 0;
	}

	GameObject(float x, float y, float iwidth, float iheight);
	
	D3DXVECTOR3 GetPosition() { return position; }

	void SetPosition(float x, float y, float z)
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

	void test() { MessageBox(NULL, L"123456", L"ABCDEF", MB_OK); }
};
