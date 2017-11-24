#include "CollisionWorld.h"
#include <sstream>
#include <iostream>

QuadTree* CollisionWorld::CreateQuadTree()
{
	RECT temp;
	temp.left = 0;
	temp.top = 0;
	temp.bottom = 600;
	temp.right = 800;

	QuadTree* quadtree = new QuadTree(1, new RECT(temp));

	vector <BoxCollider*>* object_list = &BoxCollider::_listBox;

	for (auto i = object_list->begin(); i != object_list->end(); i++)
	{
		quadtree->Insert(*i);
	}
	
	return quadtree;
}

void CollisionWorld::DetectCollision(HWND hwnd)
{
	QuadTree* quadtree = CreateQuadTree();
	vector <BoxCollider*>* return_object_list = new vector <BoxCollider*>();
	vector <BoxCollider*>* object_list = &BoxCollider::_listBox;

	for (vector <BoxCollider*>::iterator i = object_list->begin(); i != object_list->end(); i++)
	{
		
		quadtree->Retrieve(return_object_list, *i);

		for (auto x = return_object_list->begin(); x != return_object_list->end(); x++)
		{
			
			if (*i == *x)
				continue;
			float normalx, normaly;
			float CollisionTime = 2.0f;
			if ((*i)->Type == eType::Dynamic && (*x)->Type == eType::Static)
				CollisionTime = IsColliderDAS(*i, *x, normalx, normaly);
			else
			{
				CollisionTime = IsColliderDAD(*i, *x, normalx, normaly);
			}
			if (CollisionTime < 1.0f)
			{ 
				if ((*i)->IsTrigger())
				{
					//Event Trigger OnComponent Begin OverLap, OnComponent Exit Overlap
				}
				else
				{
					if (!BoxCollider::action.empty() && &BoxCollider::action[(*i)->GetAttachObject()] != NULL)
						((*i)->GetAttachObject()->*(BoxCollider::action[(*i)->GetAttachObject()]))();
					(*i)->GetAttachObject()->SetPosition((*i)->GetAttachObject()->GetPosition().x + (*i)->GetAttachObject()->vx * CollisionTime, (*i)->GetAttachObject()->GetPosition().y + (*i)->GetAttachObject()->vy * CollisionTime, 0);
					float remainingTime = 1.0f - CollisionTime;
					float dotprod = ((*i)->GetAttachObject()->vx * normalx + (*i)->GetAttachObject()->vy * normaly) * remainingTime;
					(*i)->GetAttachObject()->vx = dotprod * normaly;
					(*i)->GetAttachObject()->vy = dotprod * normalx;
				}
			}
		}
	}
}

float CollisionWorld::IsColliderDAS(BoxCollider* box, BoxCollider* otherbox, float &normalx, float &normaly)
{

	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (box->GetAttachObject()->vx > 0.0f)
	{
		xInvEntry = otherbox->GetAttachObject()->GetPosition().x - (box->GetAttachObject()->GetPosition().x + box->GetAttachObject()->width);
		xInvExit = (otherbox->GetAttachObject()->GetPosition().x + otherbox->GetAttachObject()->width) - box->GetAttachObject()->GetPosition().x;
	}
	else
	{
		xInvEntry = (otherbox->GetAttachObject()->GetPosition().x + otherbox->GetAttachObject()->width) - box->GetAttachObject()->GetPosition().x;;
		xInvExit = otherbox->GetAttachObject()->GetPosition().x - (box->GetAttachObject()->GetPosition().x + box->GetAttachObject()->width);
	}

	if (box->GetAttachObject()->vy > 0.0f)
	{
		yInvEntry = otherbox->GetAttachObject()->GetPosition().y - (box->GetAttachObject()->GetPosition().y + box->GetAttachObject()->height);
		yInvExit = (otherbox->GetAttachObject()->GetPosition().y + otherbox->GetAttachObject()->height) - box->GetAttachObject()->GetPosition().y;
	}
	else
	{
		yInvEntry = (otherbox->GetAttachObject()->GetPosition().y + otherbox->GetAttachObject()->height) - box->GetAttachObject()->GetPosition().y;
		yInvExit = otherbox->GetAttachObject()->GetPosition().y - (box->GetAttachObject()->GetPosition().y + box->GetAttachObject()->height);
	}

	float xEntry, yEntry;
	float xExit, yExit;
	
	if (box->GetAttachObject()->vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / box->GetAttachObject()->vx;
		xExit = xInvExit / box->GetAttachObject()->vx;
	}

	if (box->GetAttachObject()->vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / box->GetAttachObject()->vy;
		yExit = yInvExit / box->GetAttachObject()->vy;
	}


	float entryTime = max(xEntry, yEntry);
	float exitTime = min(xExit, yExit); 

	//if (box->GetAttachObject()->id == 1)
	//	//debug
	//{
	//	std::wstringstream s;
	//	s << L"Debug " << entryTime;
	//	std::wstring ws = s.str();
	//	std::wcout << ws;
	//	LPCWSTR lc = ws.c_str();
	//	MessageBox(NULL, lc, L"List", MB_OK);
	//}

	if (entryTime > exitTime || (xEntry < 0.0f && yEntry < 0.0f) || (xEntry > 1.0f && yEntry > 1.0f))
	{
		normalx = 1.0f;
		normaly = 1.0f;
		return 1.0;
	}
	else
	{
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		return entryTime;
	}
}

float CollisionWorld::IsColliderDAD(BoxCollider* box, BoxCollider* otherbox, float &normalx, float &normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;
	float vxtrans, vytrans;

	vxtrans = box->GetAttachObject()->vx - otherbox->GetAttachObject()->vx;
	vytrans = box->GetAttachObject()->vy - otherbox->GetAttachObject()->vy;

	if (vxtrans > 0.0f)
	{
		xInvEntry = otherbox->GetAttachObject()->GetPosition().x - (box->GetAttachObject()->GetPosition().x + box->GetAttachObject()->width);
		xInvExit = (otherbox->GetAttachObject()->GetPosition().x + otherbox->GetAttachObject()->width) - box->GetAttachObject()->GetPosition().x;
	}
	else
	{
		xInvEntry = (otherbox->GetAttachObject()->GetPosition().x + otherbox->GetAttachObject()->width) - box->GetAttachObject()->GetPosition().x;;
		xInvExit = otherbox->GetAttachObject()->GetPosition().x - (box->GetAttachObject()->GetPosition().x + box->GetAttachObject()->width);
	}

	if (vytrans > 0.0f)
	{
		yInvEntry = otherbox->GetAttachObject()->GetPosition().y - (box->GetAttachObject()->GetPosition().y + box->GetAttachObject()->height);
		yInvExit = (otherbox->GetAttachObject()->GetPosition().y + otherbox->GetAttachObject()->height) - box->GetAttachObject()->GetPosition().y;
	}
	else
	{
		yInvEntry = (otherbox->GetAttachObject()->GetPosition().y + otherbox->GetAttachObject()->height) - box->GetAttachObject()->GetPosition().y;
		yInvExit = otherbox->GetAttachObject()->GetPosition().y - (box->GetAttachObject()->GetPosition().y + box->GetAttachObject()->height);
	}

	float xEntry, yEntry;
	float xExit, yExit;

	if (vxtrans == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / box->GetAttachObject()->vx;
		xExit = xInvExit / box->GetAttachObject()->vx;
	}

	if (vytrans == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / box->GetAttachObject()->vy;
		yExit = yInvExit / box->GetAttachObject()->vy;
	}

	float entryTime = max(xEntry, yEntry);
	float exitTime = min(xExit, yExit);

	if (entryTime > exitTime || (xEntry < 0.0f && yEntry < 0.0f) || (xEntry > 1.0f && yEntry > 1.0f))
	{
		normalx = 1.0f;
		normaly = 1.0f;
		return 1.0;
	}
	else
	{
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		return entryTime;
	}
}