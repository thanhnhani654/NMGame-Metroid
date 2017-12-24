#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Component/Controllable.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"
#include "Bullet.h"
#include "Camera.h"



class Character : public GameObject, public Controllable
{

private:
	Sprite* CharacterSprite;

	float Gravity;

	float GiaTocX;

	float Masat;

	float MaxSpeed;

	int JumpVelocity;

	bool IsGround;

	int HealthPoint;

	int MaxHealthPoint;

	bool invulnerable;

	int invulnerabletimes;

	bool MorphBall;
	
	int delay;

	Camera* _Camera;

	bool UnControlable;

	bool IsFiring;

	bool IsFaceUp;

	bool IsFaceRight;

	bool IsFaceLeft;

	bool IsStartJump;

	float LimitJump;
	//float LimitFall;

	bool IsLimitJump;

	bool IsMoving;

	bool IsFlip;

	bool HaveMorphBall;

	//Dung de di qua cong
	float NextPointX;

public:

	void GetCamera(Camera* icamera);

	void beInvulnerable();

	int GetHealthPoint();

	//Ham nay dung de tang giam HP
	void DoHealthPoint(int delta);

	void SetGround();

	void Jump();

	Character() { CharacterSprite = NULL; }

	void Initialize();

	void SetPosition(float x, float y, float z);

	void Update() override;

	void UpdateInput() override;

	void Draw(int vx, int vy) override;

	void Moving();

	bool OnCollision(GameObject* object);

	void OnKeyDown(int Keycode);
	//Component
	BoxCollider* Box;

	~Character()
	{
		delete CharacterSprite;
	}

	void ToogleControlAble();
};
