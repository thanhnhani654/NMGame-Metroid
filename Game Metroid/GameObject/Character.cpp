#include "Character.h"

void Character::Initialize()
{
	CharacterSprite = nullptr;
	CharacterSprite = SpriteManager::SpriteList[eSprite::eCharacter];
<<<<<<< HEAD
	CharacterSprite->SetStatus(char_appear);
	//CharacterSprite->SetFrameRate(10);

	Controller = new Controllable();
=======
	CharacterSprite->SetStatus(stand);
>>>>>>> 4f38962650d4e51b9698402c2c0529730fa14e47

}

void Character::Moving()
{
	if (Controller->IsKeyDown(DIK_RIGHT))
	{
		CharacterSprite->Reset();
		vx = 1;
	}
	else if (Controller->IsKeyDown(DIK_LEFT))
	{
		CharacterSprite->Flip();
		vx = -1;
	}
	else
	{
		CharacterSprite->Reset();
		vx = 0;
	}
}

void Character::UpdateInput()
{
	Controller->_ProcessKeyBoard();
	Moving();
}

void Character::Update()
{
	position.x += vx;
	if (vx != 0)
	{
		CharacterSprite->SetStatus(Animation::char_run);
	}
	else
	{
		CharacterSprite->SetStatus(Animation::char_stand);
	}
}

void Character::Draw(int vx, int vy)
{
	if (CharacterSprite != NULL)
	{
		CharacterSprite->Render(position.x, position.y, vx, vy);
		CharacterSprite->Next();
	}
}
