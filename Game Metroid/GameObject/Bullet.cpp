#include "Bullet.h"
#include "../GameLog.h"

vector <Bullet*> Bullet::_listBullet;

void Bullet::Initialize()
{
	BulletSprite = NULL;
	BulletSprite = SpriteManager::SpriteList[eBullet];
	BulletSprite->SetStatus(bullet);

	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Dynamic;

	vx = 0;
	vy = 0;

	lifespan = 30;

	limitXright = position.x + 16 * 3;
	limitXleft = position.x - 16 * 3;
	limitY = position.y + 16 * 3;
}

bool Bullet::IsEmpty()
{
	return _listBullet.empty();
}

vector <Bullet*> &Bullet::GetList()
{
	return _listBullet;
}

void Bullet::SetVelocity(float ivx, float ivy)
{
	vx = ivx;
	vy = ivy;
}

void Bullet::Update()
{
	Box->Update();

	
	GAMELOG("vx = %f", vx);
	position.x += vx;
	position.y += vy;

	lifespan -= 1;
	/*if (lifespan < 0)
	Destroy();*/
}

void Bullet::Draw(int vpx, int vpy)
{
	if (BulletSprite != NULL)
	{
		BulletSprite->Render(position.x, position.y, vpx, vpy);
		BulletSprite->Next();
	}
}

Bullet::~Bullet()
{

}

void Bullet::Destroy()
{
	for (std::vector<BoxCollider*>::iterator it = BoxCollider::_listBox.begin(); it != BoxCollider::_listBox.end(); ++it)
	{
		if ((*it) == Box)
		{
			BoxCollider::_listBox.erase(it);
			break;
		}
	}

	for (std::vector<Bullet*>::iterator it = Bullet::GetList().begin(); it != Bullet::GetList().end(); ++it)
	{
		if ((*it) == this)
		{
			_listBullet.erase(it);
			break;
		}
	}
}