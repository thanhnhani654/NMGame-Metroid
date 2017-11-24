#include "Character.h"

void Character::Initialize()
{
	CharacterSprite = nullptr;
	CharacterSprite = SpriteManager::SpriteList[eSprite::eCharacter];
}

void Character::Update()
{
	if (CharacterSprite != NULL)
	{
		CharacterSprite->Render(position.x, position.y, NULL);
		//CharacterSprite->Next();
	}
}