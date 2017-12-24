#include "Ripper.h"

void Ripper::Initialize()
{
	temp = *SpriteManager::SpriteList[eRipper];
	RipperSprite = nullptr;
	//RipperSprite = SpriteManager::SpriteList[eRipper];
	RipperSprite = &temp;
	RipperSprite->SetStatus(ripper_orangeblue);


	this->vx = 0;
	this->vy = 0;
	this->index = 0;

	id = 4;
	this->width = RipperSprite->GetCurrentPosition().width;
	this->height = RipperSprite->GetCurrentPosition().height;
	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Dynamic;
	Box->SetTrigger(true);
}

void Ripper::SetNextPosition(float x, float y)
{
	pnt = new PointOfRipper[2];

	pnt[0].x = this->position.x;
	pnt[0].y = this->position.y;
	pnt[1].x = x;
	pnt[1].y = y;

}

void Ripper::Move()
{
	if (position.x != pnt[index].x)
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
		if (index > 1)
			index = 0;
	}
}

void Ripper::Update()
{
	position.x += vx;
	Box->Update();
}

void Ripper::Draw(int vx, int vy)
{
	if (RipperSprite != NULL)
	{
		RipperSprite->Render(position.x, position.y, vx, vy);
		RipperSprite->Next();
	}
}



