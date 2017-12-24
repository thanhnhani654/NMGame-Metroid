#include "Reo.h"

void Reo::Initialize()
{
	ReoSprite = nullptr;
	ReoSprite = SpriteManager::SpriteList[eReo];
	ReoSprite->SetStatus(reo_greenyellow);


	this->vx = 0;
	this->vy = 0;
	//this->index = 0;

	id = 3;
	this->width = ReoSprite->GetCurrentPosition().width;
	this->height = ReoSprite->GetCurrentPosition().height;

	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Dynamic;

	Box->SetTrigger(true);
}



void Reo::Move(int n)
{
	/*if (position.x != pnt[index].x)
	{
		vy = 0;
		if (position.x < pnt[index].x)
		{
			RipperSprite->Flip();
			vx = 0.5;
		}
		else
		{
			RipperSprite->Reset();
			vx = -0.5;
		}
	}
	else
	{
		index++;
		if (index > n - 1)
			index = 0;
	}*/
}

void Reo::Update()
{
	//position.x += vx;
	Box->Update();
}

void Reo::Draw(int vx, int vy)
{
	if (ReoSprite != NULL)
	{
		ReoSprite->Render(position.x, position.y, vx, vy);
		ReoSprite->Next();
	}
}



