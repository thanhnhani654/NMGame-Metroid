#include "HUD.h"

void HUD::Initialize()
{
	energy = nullptr;
	energy = SpriteManager::SpriteList[eSprite::eEnergy];
	energy->SetStatus(Animation::eEN);

	num1 = nullptr;
	num1 = SpriteManager::SpriteList[eSprite::eNum1];
	num1->SetStatus(Animation::e3);

	num2 = nullptr;
	num2 = SpriteManager::SpriteList[eSprite::eNum2];
	num2->SetStatus(Animation::e0);
}

void HUD::Update()
{
	
	/*if (isEn == false)
	{
	switch (number)
	{
	case 0:
	energy->SetStatus(Animation::e0);
	break;
	case 1:
	energy->SetStatus(Animation::e1);
	break;
	case 2:
	energy->SetStatus(Animation::e2);
	break;
	case 3:
	energy->SetStatus(Animation::e3);
	break;
	case 4:
	energy->SetStatus(Animation::e4);
	break;
	case 5:
	energy->SetStatus(Animation::e5);
	break;
	case 6:
	energy->SetStatus(Animation::e6);
	break;
	case 7:
	energy->SetStatus(Animation::e7);
	break;
	case 8:
	energy->SetStatus(Animation::e8);
	break;
	case 9:
	energy->SetStatus(Animation::e9);
	break;
	}
	}*/

}
void HUD::Draw(int vx, int vy)
{
	if (energy != NULL)
	{
		energy->Render(position.x, position.y, vx, vy);
		num1->Render(position.x + 16*3, position.y, vx, vy);
		num2->Render(position.x + 16*4.5, position.y, vx, vy);
	}
}