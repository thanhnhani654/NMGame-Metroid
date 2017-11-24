#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "..\GameObject\GameObject.h"
#include <vector>
#include <map>

//#include "..\CollisionWorld.h"
using namespace std;

/*
struct vector2
{
	float x;
	float y;
};

struct vertex
{
	float x;
	float y;
	float z;

	float r;
	float g;
	float b;
	float a;
};

struct Customvertex
{
	float x, y, z, rhw;
	DWORD color;
};

struct rectangle
{
	Customvertex point[5];
	DWORD color;

	rectangle() {}

	void Initialize(float x, float y, float width, float height)
	{
		point[0].x = x;
		point[0].y = y;
		point[0].z = 0;
		point[0].rhw = 1.0f;
		point[0].color = D3DCOLOR_ARGB(0, 255, 0, 0);

		point[1].x = x + width;
		point[1].y = y;
		point[1].z = 0;
		point[1].rhw = 1.0f;
		point[1].color = D3DCOLOR_ARGB(0, 255, 0, 0);

		point[2].x = x + width;
		point[2].y = y + height;
		point[2].z = 0;
		point[2].rhw = 1.0f;
		point[2].color = D3DCOLOR_ARGB(0, 255, 0, 0);

		point[3].x = x;
		point[3].y = y + height;
		point[3].z = 0;
		point[3].rhw = 1.0f;
		point[3].color = D3DCOLOR_ARGB(0, 255, 0, 0);

		point[4] = point[0];
	}

	void SetColor(DWORD icolor)
	{
		point[0].color = icolor;
		point[1].color = icolor;
		point[2].color = icolor;
		point[3].color = icolor;
		point[4].color = icolor;
	}
};

//class BoxCollider
//{
//private:
//	rectangle box;
//	vector2 position;
//	vector2 size;
//
//	GameObject* object;
//	RECT a;
//
//	bool Trigger;
//	
//	LPDIRECT3DVERTEXBUFFER9 buffer;
//
//	bool debug_mode = false;
//public:
//	BoxCollider(float x, float y, float width, float height)
//	{
//		box.Initialize(x, y, width, height);
//		position.x = x;
//		position.y = y;
//		size.x = width;
//		size.y = height;
//		buffer = NULL;
//
//
//	}
//	
//	BoxCollider()
//	{
//		if (buffer)
//			buffer->Release();
//	}
//
//	BoxCollider(GameObject* iobject)
//	{
//		object = iobject;
//	}
//
//	void SetPosition(float x, float y)
//	{
//		position.x = x;
//
//		position.y = y;
//
//		box.Initialize(position.x, position.y, size.x, size.y);
//
//		VOID* pVertices;
//
//		buffer->Lock(0, sizeof(Customvertex), (void**)&pVertices, 0);
//
//		memcpy(pVertices, box.point, sizeof(box.point));
//
//		buffer->Unlock();
//	}
//
//	vector2 GetPosition()
//	{
//		return position;
//	}
//
//	void SetDebugMode(bool mode);
//
//	void SetSize(float x, float y) { size.x = x; size.y = y; }
//	vector2 GetSize() { return size; }
//
//	void SetupVertexBuffer(LPDIRECT3DDEVICE9 device);
//
//	void DrawCollider(LPDIRECT3DDEVICE9 device);
//
//	bool IsTrigger();
//
//	void Update();
//};
*/

enum eType
{
	Dynamic,
	Static
};

class BoxCollider
{
private:
	RECT Box;
	GameObject* gameobject;

	bool Trigger = false;
	
public:
	static vector <BoxCollider*> _listBox;

	eType Type;

	BoxCollider() { _listBox.push_back(this); }

	void SetBox(int x, int y, int width, int height);
	void SetPosition(int x, int y);
	void SetSize(int width, int height);
	void AttachObject(GameObject *igameobject);
	GameObject* GetAttachObject();

	RECT GetBoundingBox();

	bool IsTrigger();
	void SetTrigger(bool trigger);

	//static int GetListSize();
	/*void RemoveTop();*/

	void Update();

	/*template <class ClassType>*/
	typedef void(*Func)();

	template <class T> void OnTriggerBoxBeginOverlap(T object,typedef int(T::*func)(int)) 
	{ object->*func(2); }
	//void OnTriggerBoxBeginOverlap(T func);
	void OnTriggerBoxBeginOverlap() {}

	/*template <class ClassType>*/
	void OnTriggerBoxEndOverlap(Func func);
	void OnTriggerBoxEndOverlap(){}

	/*template <class ClassType>*/
	typedef void(GameObject::*fun)();
	static void OnBoxCollider(GameObject* object,fun func);

	static vector<fun> h;
	//void OnBoxCollider(){}

	static map <GameObject*, fun> action;
};