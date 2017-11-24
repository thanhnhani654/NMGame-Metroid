#include "Character.h"

void Character::Initialize()
{
	CharacterSprite = nullptr;
	CharacterSprite = SpriteManager::SpriteList[eSprite::eCharacter];
	CharacterSprite->SetStatus(stand);

}



void Character::Update()
{
	position.x += vx;
	if (vx > 0)
	{
		CharacterSprite->SetStatus(walk);
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