#include "BoxCollider.h"
#include "../Utility.h"

vector <BoxCollider*> BoxCollider::_listBox;

void BoxCollider::SetBox(int x, int y, int width, int height)
{
	Box.top = y + height - 1;
	Box.left = x + 1;
	Box.right = x + width - 1;
	Box.bottom = y + 1;
}

void BoxCollider::SetPosition(int x, int y)
{
	int width = Box.right - Box.left;
	int height = Box.top - Box.bottom;
	Box.left = x;
	Box.bottom = y;
	Box.right = x + width;
	Box.top = y + height;

	//gameobject->SetPosition(Box.left, Box.top, 0);
	//gameobject->width = width;
	//gameobject->height = height;
}

void BoxCollider::SetSize(float width, float height)
{
	//Box.left = Box.left + (Box.right - Box.left - width / 2)  ;
	//Box.bottom = Box.bottom + (Box.top - Box.bottom - height / 2) + 50 ;
	Box.right = Box.left + width - 1;
	Box.top = Box.bottom + height - 1;
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

BoundingBox BoxCollider::GetBoundingBox()
{
	return Box;
}

void BoxCollider::Update()
{
	if (gameobject != NULL)
	{

		if (GetAttachObject()->id == 1)
			this->SetPosition(Box.left + gameobject->vx, Box.bottom + gameobject->vy);
		else
			this->SetPosition(GetAttachObject()->GetPosition().x - GetAttachObject()->width / 2, GetAttachObject()->GetPosition().y - GetAttachObject()->height / 2);
		//this->SetSize(gameobject->width, gameobject->height);
	}
}

GameObject* BoxCollider::GetAttachObject()
{
	return gameobject;
}