#include "Zoomer.h"

void Zoomer::Initialize()
{
	id = 2;
	temp = *SpriteManager::SpriteList[eZoomer];
	ZoomerSprite = nullptr;
	ZoomerSprite = &temp;
	//ZoomerSprite = SpriteManager::SpriteList[eZoomer];
	//ZoomerSprite->SetStatus(Animation::zoomer_orange_on);

	this->vx = 0;
	this->vy = 0;
	this->index = 0;

	this->width = ZoomerSprite->GetCurrentPosition().width;
	this->height = ZoomerSprite->GetCurrentPosition().height;

	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Dynamic;

	Box->SetTrigger(true);
}



void Zoomer::Move()
{
	if (position.x != pnt[index].x)
	{
		vy = 0;
		if (position.x < pnt[index].x)
		{
			vx = 0.5;
		}
		else
		{
			vx = -0.5;
		}
	}
	else if (position.y != pnt[index].y)
	{
		vx = 0;
		if (position.y < pnt[index].y)
		{
			vy = 0.5;
		}
		else
		{
			vy = -0.5;
		}
	}
	else
	{
		index++;
		if (index > GetMaxPoint() - 1)
			index = 0;
	}
}

void Zoomer::Update()
{
	position.x += vx;
	position.y += vy;
	Box->Update();

	switch (Type)
	{
	case a:
		if (pnt[index].beforeState == eOn)
			ZoomerSprite->SetStatus(zoomer_orange_on);
		if (pnt[index].beforeState == eRight)
			ZoomerSprite->SetStatus(zoomer_orange_right);
		if (pnt[index].beforeState == eUnder)
			ZoomerSprite->SetStatus(zoomer_orange_under);
		if (pnt[index].beforeState == eLeft)
			ZoomerSprite->SetStatus(zoomer_orange_left);
		break;
	case b:
		if (pnt[index].beforeState == eOn)
			ZoomerSprite->SetStatus(zoomer_pink_on);
		if (pnt[index].beforeState == eRight)
			ZoomerSprite->SetStatus(zoomer_pink_right);
		if (pnt[index].beforeState == eUnder)
			ZoomerSprite->SetStatus(zoomer_pink_under);
		if (pnt[index].beforeState == eLeft)
			ZoomerSprite->SetStatus(zoomer_pink_left);
		break;
	case c:
		if (pnt[index].beforeState == eOn)
			ZoomerSprite->SetStatus(zoomer_red_on);
		if (pnt[index].beforeState == eRight)
			ZoomerSprite->SetStatus(zoomer_red_right);
		if (pnt[index].beforeState == eUnder)
			ZoomerSprite->SetStatus(zoomer_red_under);
		if (pnt[index].beforeState == eLeft)
			ZoomerSprite->SetStatus(zoomer_red_left);
		break;
	case d:
		break;
	default:
		break;
	}
}

void Zoomer::Draw(int vx, int vy)
{
	if (ZoomerSprite != NULL)
	{
		ZoomerSprite->Render(position.x, position.y, vx, vy);
		ZoomerSprite->Next();
	}
}



