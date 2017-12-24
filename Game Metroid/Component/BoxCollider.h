#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "..\GameObject\GameObject.h"
#include <vector>
#include <map>

using namespace std;

enum eType
{
	Dynamic,
	Static
};

enum eDirection
{
	Top,
	Bottom,
	Right,
	Left
};

struct BoundingBox
{
	float left;
	float top;
	float right;
	float bottom;
};

class BoxCollider
{
private:
	BoundingBox Box;
	GameObject* gameobject;

	bool Trigger = false;

public:
	static vector <BoxCollider*> _listBox;

	eType Type;
	eDirection Direction;

	BoxCollider() { _listBox.push_back(this); }

	void SetBox(int x, int y, int width, int height);
	void SetPosition(int x, int y);
	void SetSize(float width, float height);
	void AttachObject(GameObject *igameobject);
	GameObject* GetAttachObject();

	BoundingBox GetBoundingBox();

	bool IsTrigger();
	void SetTrigger(bool trigger);

	void Update();


};