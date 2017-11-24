#include "BoxCollider.h"
/*
//void BoxCollider::SetDebugMode(bool mode)
//{
//	debug_mode = mode;
//}
//
//void BoxCollider::SetupVertexBuffer(LPDIRECT3DDEVICE9 device)
//{
//	device->CreateVertexBuffer(5 * sizeof(Customvertex), 0, D3DFVF_DIFFUSE | D3DFVF_XYZRHW, D3DPOOL_DEFAULT, &buffer, NULL);
//
//	VOID* pVertices;
//
//	buffer->Lock(0, sizeof(Customvertex), (void**)&pVertices, 0);
//
//	memcpy(pVertices, box.point, sizeof(box.point));
//
//	buffer->Unlock();
//	
//}
//
//void BoxCollider::DrawCollider(LPDIRECT3DDEVICE9 device)
//{
//	if (debug_mode = true)
//	{
//		device->SetStreamSource(0, buffer, 0, sizeof(Customvertex));
//		device->SetFVF(D3DFVF_DIFFUSE | D3DFVF_XYZRHW);
//		device->DrawPrimitive(D3DPT_LINESTRIP, 0, 4);
//	}
//}
//
//void BoxCollider::Update()
//{
//	SetPosition(object->GetPosition().x, object->GetPosition().y);
//}
//
//bool BoxCollider::IsTrigger()
//{
//	return Trigger;
//}
*/
vector <BoxCollider*> BoxCollider::_listBox;

void BoxCollider::SetBox(int x, int y, int width, int height)
{
	Box.top = y;
	Box.left = x;
	Box.right = x + width;
	Box.bottom = y + height;
}

void BoxCollider::SetPosition(int x, int y)
{
	int width = Box.right - Box.left;
	int height = Box.bottom - Box.top;
	Box.left = x;
	Box.top = y;
	Box.right = x + width;
	Box.bottom = y + height;
	gameobject->SetPosition(Box.left, Box.top, 0);
	gameobject->width = width;
	gameobject->height = height;
}

void BoxCollider::SetSize(int width, int height)
{
	Box.right = Box.left + width;
	Box.bottom = Box.top + height;
}

void BoxCollider::AttachObject(GameObject *igameobject)
{
	gameobject = igameobject;
}

bool BoxCollider::IsTrigger()
{
	return Trigger;
}

void BoxCollider::SetTrigger(bool trigger)
{
	Trigger = trigger;
}

RECT BoxCollider::GetBoundingBox()
{
	return Box;
}

//int BoxCollider::GetListSize()
//{
//	if (!_listBox.empty())
//		return _listBox.size();
//	return 0;
//}
//
//void BoxCollider::RemoveTop()
//{
//	_listBox.pop_back();
//}

void BoxCollider::Update()
{
	if (gameobject != NULL)
	{
		this->SetPosition(gameobject->GetPosition().x, gameobject->GetPosition().y);
	}
}

GameObject* BoxCollider::GetAttachObject()
{
	return gameobject;
}

//template <class ClassType>
//void BoxCollider::OnTriggerBoxBeginOverlap<ClassType>(ClassType func)
//{
//	(*func)();
//}

//template <class T> void BoxCollider::OnTriggerBoxBeginOverlap(T func)
//{
//	func();
//}


void BoxCollider::OnTriggerBoxEndOverlap(Func func)
{
	(*func)();
}

std::map<GameObject*, BoxCollider::fun> BoxCollider::action;

void BoxCollider::OnBoxCollider(GameObject* object,fun func)
{
	//(object->*func)();
	action[object] = func;
	//(object->*action[object])();
}