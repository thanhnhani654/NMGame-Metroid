#include "CollisionWorld.h"
#include <sstream>
#include <iostream>
#include "GameLog.h"
#include <math.h>
#include "GameObject\character.h"
#include "GameObject\Zoomer.h"

//QuadTree* CollisionWorld::CreateQuadTree()
//{
//	RECT temp;
//	temp.left = 0;
//	temp.top = 0;
//	temp.bottom = 600;
//	temp.right = 800;
//
//	QuadTree* quadtree = new QuadTree(1, new RECT(temp));
//
//	vector <BoxCollider*>* object_list = &BoxCollider::_listBox;
//
//	for (auto i = object_list->begin(); i != object_list->end(); i++)
//	{
//		quadtree->Insert(*i);
//	}
//	
//	return quadtree;
//}

void CollisionWorld::DetectCollision(HWND hwnd)
{
	//QuadTree* quadtree = CreateQuadTree();
	vector <BoxCollider*>* return_object_list = new vector <BoxCollider*>();
	vector <BoxCollider*>* object_list = &BoxCollider::_listBox;

	for (vector <BoxCollider*>::iterator i = object_list->begin(); i != object_list->end(); i++)
	{
		
		//quadtree->Retrieve(return_object_list, *i);

		//for (auto x = return_object_list->begin(); x != return_object_list->end(); x++)
		for (vector <BoxCollider*>::iterator x = object_list->begin(); x != object_list->end(); x++)
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

			bool IsDontEsc = true;

			if (CollisionTime < 1.0f)
			{ 
				if ((*i)->IsTrigger() || (*x)->IsTrigger())
				{
					//Event Trigger OnComponent Begin OverLap, OnComponent Exit Overlap
					IsDontEsc = (*i)->GetAttachObject()->OnCollision((*x)->GetAttachObject());
					if (!IsDontEsc)
						return;
				}
				else
				{
					(*i)->GetAttachObject()->OnCollision((*x)->GetAttachObject());
					if (!IsDontEsc)
						return;

					float remainingtime = 1 - CollisionTime;
					if (normaly > 0)
					{
 						(*i)->GetAttachObject()->SetPosition((*i)->GetAttachObject()->GetPosition().x,//(*i)->GetAttachObject()->GetPosition().x - 1*(remainingtime * (*i)->GetAttachObject()->vx), 
							(*i)->GetAttachObject()->GetPosition().y - 1 * (remainingtime * (*i)->GetAttachObject()->vy ));
						(*i)->Direction = Bottom;
					}
					if (normaly < 0)
					{
						(*i)->GetAttachObject()->SetPosition((*i)->GetAttachObject()->GetPosition().x,//(*i)->GetAttachObject()->GetPosition().x - 1*(remainingtime * (*i)->GetAttachObject()->vx), 
							(*i)->GetAttachObject()->GetPosition().y - 1 * (remainingtime * (*i)->GetAttachObject()->vy));
						(*i)->Direction = Top;
					}
					if (normalx < 0)
					{
						(*i)->GetAttachObject()->SetPosition((*i)->GetAttachObject()->GetPosition().x - (remainingtime * (*i)->GetAttachObject()->vx),//(*i)->GetAttachObject()->GetPosition().x - 1*(remainingtime * (*i)->GetAttachObject()->vx), 
							(*i)->GetAttachObject()->GetPosition().y);
						(*i)->Direction = Right;
					}
					
					if (normalx > 0)
					{
						(*i)->GetAttachObject()->SetPosition((*i)->GetAttachObject()->GetPosition().x - (remainingtime * (*i)->GetAttachObject()->vx),//(*i)->GetAttachObject()->GetPosition().x - 1*(remainingtime * (*i)->GetAttachObject()->vx), 
							(*i)->GetAttachObject()->GetPosition().y);
						(*i)->Direction = Left;
					}

				}
			}
		}
	}
}

float CollisionWorld::IsColliderDAS(BoxCollider* box, BoxCollider* otherbox, float &normalx, float &normaly)
{

	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (box->GetBoundingBox().left == 79 + 3)
	{
		int k = 10;
	}

	if (box->GetAttachObject()->vx > 0.0f)
	{
		xInvEntry = otherbox->GetBoundingBox().left - box->GetBoundingBox().right;//(box->GetBoundingBox().left + box->GetAttachObject()->width);
		xInvExit = otherbox->GetBoundingBox().right - box->GetBoundingBox().left;// (otherbox->GetBoundingBox().left + otherbox->GetAttachObject()->width) - box->GetBoundingBox().left;
	}
	else
	{
		xInvEntry = otherbox->GetBoundingBox().right - box->GetBoundingBox().left; //(otherbox->GetBoundingBox().left + otherbox->GetAttachObject()->width) - box->GetBoundingBox().left;
		xInvExit = otherbox->GetBoundingBox().left - box->GetBoundingBox().right; // (box->GetBoundingBox().left + box->GetAttachObject()->width);
	}

	if (box->GetAttachObject()->vy > 0.0f)
	{
		yInvEntry = otherbox->GetBoundingBox().bottom - box->GetBoundingBox().top; // (box->GetBoundingBox().bottom + box->GetAttachObject()->height);
		yInvExit = otherbox->GetBoundingBox().top - box->GetBoundingBox().bottom;// (otherbox->GetBoundingBox().bottom + otherbox->GetAttachObject()->height) - box->GetBoundingBox().bottom;
	}
	else
	{
		yInvEntry = otherbox->GetBoundingBox().top - box->GetBoundingBox().bottom; // (otherbox->GetBoundingBox().bottom + otherbox->GetAttachObject()->height) - box->GetBoundingBox().bottom;
		yInvExit = otherbox->GetBoundingBox().bottom - box->GetBoundingBox().top; //otherbox->GetBoundingBox().bottom - (box->GetBoundingBox().bottom + box->GetAttachObject()->height);
	}

	//Xet khoang cach thuc te cua 2 object khong phu thuoc vao van toc

	int xdistance = 0;
	int ydistance = 0;

	if (otherbox->GetBoundingBox().left - (box->GetBoundingBox().left + box->GetAttachObject()->width) > 0)
	{
		xdistance = otherbox->GetBoundingBox().left - (box->GetBoundingBox().left + box->GetAttachObject()->width);
	}
	else
	{
		xdistance = box->GetBoundingBox().left - (otherbox->GetBoundingBox().left + otherbox->GetAttachObject()->width);
	}

	if (otherbox->GetBoundingBox().bottom - (box->GetBoundingBox().bottom + box->GetAttachObject()->height) > 0)
	{
		ydistance = otherbox->GetBoundingBox().bottom - (box->GetBoundingBox().bottom + box->GetAttachObject()->height);
	}
	else
	{
		ydistance = box->GetBoundingBox().bottom - (otherbox->GetBoundingBox().bottom + otherbox->GetAttachObject()->height);
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

	if (otherbox->GetAttachObject()->DebugName == 13 && box->GetBoundingBox().left == 624)
		int t = 0;
	int debug1 = otherbox->GetBoundingBox().right - otherbox->GetBoundingBox().left;
	int debug2 = box->GetBoundingBox().right - box->GetBoundingBox().left;
	
	if (entryTime > exitTime || 
		(xEntry < 0.0f && yEntry < 0.0f) || 
		(xEntry > 1.0f || yEntry > 1.0f) ||
		(((xInvEntry < 0) || (xInvEntry > (debug1 + debug2))) && box->GetAttachObject()->vx == 0) ||
		(((yInvEntry < 0) || (yInvEntry > (otherbox->GetBoundingBox().top - otherbox->GetBoundingBox().bottom + box->GetBoundingBox().top - box->GetBoundingBox().bottom))) && box->GetAttachObject()->vy == 0))
		{
			normalx = 0.0f;
			normaly = 0.0f;
			return 1.0;
		}
	else
	{
		if (otherbox->GetAttachObject()->DebugName == 13 && box->GetBoundingBox().left == 624)
			int t = 0;
		if (xEntry > yEntry)
		{
			
			if (xInvEntry < 0.0f)
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = 1.0f;
				normaly = 0.0f;

			}
		}
		else
		{
			static int t = 0;
			if (yInvEntry <= 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}
		float i = box->GetBoundingBox().bottom;
		float t = otherbox->GetBoundingBox().bottom;
		int a = normaly;
		yInvEntry = yInvEntry;
		return entryTime;
	}
}

float CollisionWorld::IsColliderDAD(BoxCollider* box, BoxCollider* otherbox, float &normalx, float &normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;
	float vxtrans, vytrans;

	if ((box->GetAttachObject()->vx == 0 && box->GetAttachObject()->vy == 0) &&
		(otherbox->GetAttachObject()->vx != 0 || otherbox->GetAttachObject()->vy != 0))
	{
		return IsColliderDAS(otherbox, box, normalx, normaly);
	}
	else if ((box->GetAttachObject()->vx == 0 || box->GetAttachObject()->vy == 0) &&
		(otherbox->GetAttachObject()->vx == 0 && otherbox->GetAttachObject()->vy == 0))
	{
		return IsColliderDAS(box, otherbox, normalx, normaly);
	}

	vxtrans = box->GetAttachObject()->vx - otherbox->GetAttachObject()->vx;
	vytrans = box->GetAttachObject()->vy - otherbox->GetAttachObject()->vy;

	if (vxtrans > 0.0f)
	{
		xInvEntry = otherbox->GetBoundingBox().left - box->GetBoundingBox().right;//(box->GetBoundingBox().left + box->GetAttachObject()->width);
		xInvExit = otherbox->GetBoundingBox().right - box->GetBoundingBox().left;// (otherbox->GetBoundingBox().left + otherbox->GetAttachObject()->width) - box->GetBoundingBox().left;
	}
	else
	{
		xInvEntry = otherbox->GetBoundingBox().right - box->GetBoundingBox().left; //(otherbox->GetBoundingBox().left + otherbox->GetAttachObject()->width) - box->GetBoundingBox().left;
		xInvExit = otherbox->GetBoundingBox().left - box->GetBoundingBox().right; // (box->GetBoundingBox().left + box->GetAttachObject()->width);
	}

	if (vytrans > 0.0f)
	{
		yInvEntry = otherbox->GetBoundingBox().bottom - box->GetBoundingBox().top; // (box->GetBoundingBox().bottom + box->GetAttachObject()->height);
		yInvExit = otherbox->GetBoundingBox().top - box->GetBoundingBox().bottom;// (otherbox->GetBoundingBox().bottom + otherbox->GetAttachObject()->height) - box->GetBoundingBox().bottom;
	}
	else
	{
		yInvEntry = otherbox->GetBoundingBox().top - box->GetBoundingBox().bottom; // (otherbox->GetBoundingBox().bottom + otherbox->GetAttachObject()->height) - box->GetBoundingBox().bottom;
		yInvExit = otherbox->GetBoundingBox().bottom - box->GetBoundingBox().top; //otherbox->GetBoundingBox().bottom - (box->GetBoundingBox().bottom + box->GetAttachObject()->height);
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

	if (otherbox->GetAttachObject()->DebugName == 13 && box->GetBoundingBox().left == 624)
		int t = 0;
	int debug1 = otherbox->GetBoundingBox().right - otherbox->GetBoundingBox().left;
	int debug2 = box->GetBoundingBox().right - box->GetBoundingBox().left;

	if (entryTime > exitTime ||
		(xEntry < 0.0f && yEntry < 0.0f) ||
		(xEntry > 1.0f || yEntry > 1.0f) ||
		(((xInvEntry < 0) || (xInvEntry >(debug1 + debug2))) && vxtrans == 0) ||
		(((yInvEntry < 0) || (yInvEntry >(otherbox->GetBoundingBox().top - otherbox->GetBoundingBox().bottom + box->GetBoundingBox().top - box->GetBoundingBox().bottom))) && vytrans))
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0;
	}
	else
	{
		if (xEntry > yEntry)
		{

			if (xInvEntry < 0.0f)
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = 1.0f;
				normaly = 0.0f;

			}
		}
		else
		{
			if (yInvEntry <= 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}
		return entryTime;
	}
}