#include "Character.h"
#include "../GameLog.h"

void Character::Initialize()
{
	id = 0;

	invulnerable = false;
	invulnerabletimes = 15;

	CharacterSprite = nullptr;
	CharacterSprite = SpriteManager::SpriteList[eSprite::eCharacter];
	this->width = CharacterSprite->GetCurrentPosition().width;
	this->height = CharacterSprite->GetCurrentPosition().height;
	this->vx = 0;
	this->vy = 0;

	CharacterSprite->SetStatus(char_appear);
	//CharacterSprite->SetFrameRate(10);

	CharacterSprite->SetStatus(char_stand);

	//Component Initialize

	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Dynamic;
	Gravity = 0.2f;
	GiaTocX = 0.3f;
	Masat = 0.15f;
	MaxSpeed = 1.5f;
	IsGround = false;
	JumpVelocity = 5;
	HealthPoint = 30;
	MaxHealthPoint = 100;

	MorphBall = false;
	UnControlable = false;
	IsFiring = false;
	IsFaceUp = false;
	IsStartJump = false;
	IsLimitJump = false;
	IsMoving = false;
	HaveMorphBall = false;

	delay = 3;
}

void Character::GetCamera(Camera* icamera)
{
	_Camera = icamera;
}

int Character::GetHealthPoint()
{
	return HealthPoint;
}

//Include GAMELOG va su dung GAMELOG de debug HealthPoint. Cach su dung: GAMELOG("HP: %d", GetHealthPoint());
void Character::DoHealthPoint(int delta)
{
	HealthPoint += delta;
	if (HealthPoint > 100)
		HealthPoint = 100;
	if (HealthPoint < 0)
		HealthPoint = 0;
}

void Character::SetPosition(float x, float y, float z)
{
	GameObject::SetPosition(x, y, z);
	Box->SetPosition(position.x - (width / 2), position.y - (height / 2));
}

void Character::Moving()
{
	if (IsKeyDown(DIK_D))
	{
		CharacterSprite->Reset();
		//if (!MorphBall && IsGround)
		//CharacterSprite->SetStatus(char_run);
		IsFaceRight = true;
		IsFaceLeft = false;
		if (vx <= MaxSpeed)
		{
			vx += GiaTocX;
		}
	}
	else if (IsKeyDown(DIK_A))
	{
		CharacterSprite->Flip();
		IsFaceRight = false;
		IsFaceLeft = true;
		//if (!MorphBall && IsGround)
		//CharacterSprite->SetStatus(char_run);
		if (vx >= -MaxSpeed)
		{
			vx += -GiaTocX;
		}
	}
	else
	{
		//vx = 0;
	}

	if (IsKeyDown(DIK_W))
	{
		IsFaceUp = true;
		if (vx == 0)
		{
			// Thieu Animation nhin len troi;
			//CharacterSprite->SetStatus(char_stand_up);
		}
		else 
		{
			// Thieu Animation chay nhin len troi;
		}
	}
	else
	{
		IsFaceUp = false;
	}

	if (IsKeyDown(DIK_J))
	{
		if (!MorphBall)
		{
			IsFiring = true;
			if (delay < 0)
			{
				delay = 3;
				if (Bullet::GetList().size() <= 10)
				{
					//bullet->SetPosition(position.x+width / 2, position.y + height / 4 - 1, 0);
					//bullet->Initialize();
					//bullet->SetVelocity(4.0f, 0);
					if (!IsFaceUp)
					{
						/*if (IsGround)
						{
							if (vx == 0)
							{
								CharacterSprite->SetStatus(char_stand_shoot);
							}
							else
							{
								CharacterSprite->SetStatus(char_run_shoot);
							}
						}
						else
						{
							CharacterSprite->SetStatus(char_jump_shoot_up);
						}*/

						if (IsFaceRight)
						{
							Bullet* bullet = new Bullet();
							bullet->SetPosition(position.x + width / 2, position.y + height / 4 - 1, 0);
							bullet->Initialize();
							bullet->SetVelocity(4.0f, 0);
						}
						else
						{
							Bullet* bullet = new Bullet();
							bullet->SetPosition(position.x - width / 2, position.y + height / 4 - 1, 0);
							bullet->Initialize();
							bullet->SetVelocity(-4.0f, 0);
						}
					}
					else
					{
						//if (IsGround)
						//{
						//	if (vx == 0)
						//	{
						//		// Thieu Animation char stand shot up
						//	}
						//	else
						//	{
						//		CharacterSprite->SetStatus(char_run_shoot_up);
						//	}
						//}
						//else
						//{
						//	CharacterSprite->SetStatus(char_jump_shoot_up);
						//}

						if (IsFaceRight)
						{
							Bullet* bullet = new Bullet();
							bullet->SetPosition(position.x + width / 4 - 2, position.y + height / 2, 0);
							bullet->Initialize();
							bullet->SetVelocity(0, 4.0f);
						}
						else
						{
							Bullet* bullet = new Bullet();
							bullet->SetPosition(position.x - width / 4 + 2, position.y + height / 2, 0);
							bullet->Initialize();
							bullet->SetVelocity(0, 4.0f);
						}
					}
				}
			}
			else
			{
				delay--;
			}
		}
		else
		{
			IsFiring = false;
		}
	}

	if (IsKeyDown(DIK_SPACE))
	{
		if (!IsGround)
		{
			if (!IsLimitJump)
			{
				if (position.y < LimitJump)
				{
					CharacterSprite->SetFrameRate(0.5f);
					//if (!IsFlip)
					//{
					//	//CharacterSprite->SetStatus(char_jump);
					//}
					//else
					//	CharacterSprite->SetStatus(char_flip);
					//CharacterSprite->Next();
					vy = 3.5;
				}
				else
				{
					IsLimitJump = true;
				}
			}
		}
		
	}
}

void Character::OnKeyDown(int Keycode)
{
	switch (Keycode)
	{
	case DIK_SPACE:
		//Jump();
		if (!MorphBall)
		{
			if (IsGround)
			{
				CharacterSprite->SetFrameRate(0.5f);
				//CharacterSprite->SetStatus(char_jump);
				vy = 3.5;
				LimitJump = this->position.y + 16 * 4.1;
				if (IsMoving)
					IsFlip = true;
				else
				{
					IsFlip = false;
				}
			}
		}
		else
		{
			MorphBall = false;
			CharacterSprite->SetStatus(Animation::char_stand_shoot);
			position.y += 16;
			width = CharacterSprite->GetCurrentPosition().width;
			height = CharacterSprite->GetCurrentPosition().height;
			Box->SetSize(width, height);
		}
		break;
	case DIK_S:
		if (HaveMorphBall)
		{
			MorphBall = true;
			CharacterSprite->SetStatus(char_roll);

			width = CharacterSprite->GetCurrentPosition().width;
			height = CharacterSprite->GetCurrentPosition().height;
			Box->SetSize(width, height);
		}
		break;
	case DIK_W:
		if (MorphBall)
		{
			MorphBall = false;
			CharacterSprite->SetStatus(Animation::char_stand_shoot);
			position.y += 16;
			width = CharacterSprite->GetCurrentPosition().width;
			height = CharacterSprite->GetCurrentPosition().height;
			Box->SetSize(width, height);
		}
		break;
	}
}

void Character::Jump()
{
	/*if (IsGround)
	{
		CharacterSprite->SetStatus(char_jump);
		IsStartJump = true;
		static int index = 0;
		vy = 3;
		if (index > 60)
		{
			index = 0;
		}

		IsGround = false;
	}*/
}

void Character::UpdateInput()
{
	if (!UnControlable)
	{
		_ProcessKeyBoard();
		Moving();
		IsGround = false;
		if (vy > -3)
			vy -= Gravity;
	}
}

void Character::Update()
{
	position.x += vx;
	position.y += vy;

	//GAMELOG("x = %f", position.x);

	if (vx < 0.1f && vx > -0.1f)
		vx = 0;

	if (IsGround)
	{
		if (vx > 0)
		{
			vx -= Masat;
		}
		else if (vx < 0)
		{
			vx += Masat;
		}
	}

	if (vx != 0)
	{
		IsMoving = true;
		//CharacterSprite->Next();
	}
	else
		IsMoving = false;

	Box->Update();


	if (!MorphBall)
	{
		if (IsGround && !IsFiring && !IsFaceUp && !IsMoving)			//Dung yen
		{
			//xai tam
			CharacterSprite->SetStatus(Animation::char_stand_shoot);
		}
		else if (IsGround && !IsFiring && IsFaceUp && !IsMoving)		//Dung yen nhin len troi
		{
			CharacterSprite->SetStatus(Animation::char_stand_up);
		}
		else if (IsGround && IsFiring && !IsFaceUp && !IsMoving)		//Dung ban tai cho
		{
			CharacterSprite->SetStatus(Animation::char_stand_shoot);
		}
		else if (IsGround && IsFiring && IsFaceUp && !IsMoving)			//Dung yen nhin len troi ban
		{
			CharacterSprite->SetStatus(Animation::char_stand_up);
		}
		else if (IsGround && !IsFiring && !IsFaceUp && IsMoving)		//Di binh thuong
		{
			CharacterSprite->SetStatus(char_run);
		}
		else if (IsGround && IsFiring && !IsFaceUp && IsMoving)			//Vua di vua ban
		{
			CharacterSprite->SetStatus(char_run);
		}
		else if (IsGround && IsFiring && IsFaceUp && IsMoving)			//Vua di vua ban len troi
		{
			CharacterSprite->SetStatus(Animation::char_run_shoot_up);
		}
		else if (IsGround && !IsFiring && IsFaceUp && IsMoving)			//Vua di Vua nhin len troi
		{
			//xai tam
			CharacterSprite->SetStatus(Animation::char_run_shoot_up);
		}
		else if (!IsGround)												// Dang feel
		{
			if (!IsFiring)
			{
				if (IsFlip)
				{
					CharacterSprite->SetStatus(char_flip);
				}
			}
			else
			{
				if (!IsFaceUp)
				{
					//xai tam
					CharacterSprite->SetStatus(char_jump);
				}
				else
				{
					CharacterSprite->SetStatus(char_jump_shoot_up);
				}
			}
			if (position.y < LimitJump - 16 * 3.1 )//&& vy < 0)
			{
				CharacterSprite->SetStatus(char_jump);
				//vx = 0;
			}
		}
	}


	if (!Bullet::IsEmpty())
	{
		for (std::vector<Bullet*>::iterator it = Bullet::GetList().begin(); it != Bullet::GetList().end(); ++it)
		{
			(*it)->Update();
			if ((*it)->GetPosition().x <= (*it)->limitXleft || 
				(*it)->GetPosition().x >= (*it)->limitXright || 
				(*it)->GetPosition().y >= (*it)->limitY ||
				(*it)->lifespan < 0)
			{
				//GameObject::DestroyObject((*it));
				(*it)->Destroy();
				break;
			}
		}
	}
}

void Character::Draw(int vpx, int vpy)
{
	if (CharacterSprite != NULL)
	{
		if (!invulnerable)
		{
			CharacterSprite->Render(position.x, position.y, vpx, vpy);
			CharacterSprite->Next();
			
		}
		else
		{
			static int times = 0;
			if (times == 2)
			{
				CharacterSprite->Render(position.x, position.y, vpx, vpy);
				//CharacterSprite->Next();
				invulnerabletimes--;
				times = 0;
			}
			else
			{
				times++;
			}
			if (invulnerabletimes <= 0)
			{
				invulnerable = false;
				invulnerabletimes = 25;
			}
		}
	}

	if (!Bullet::IsEmpty())
	{
		for (std::vector<Bullet*>::iterator it = Bullet::GetList().begin(); it != Bullet::GetList().end(); ++it)
		{
			(*it)->Draw(vpx, vpy);
		}
	}

	if (_Camera->IsGoingRight())
	{
		UnControlable = true;
		if (_Camera->GoRightFinish())
		{
			vx = 1;
		}
		if (position.x >= NextPointX)
		{
			vx = 0;
			_Camera->GoRightReset();
		}
	}
	else
	{
		UnControlable = false;
	}
	if (_Camera->IsGoingLeft())
	{
		UnControlable = true;
		if (_Camera->GoLeftFinish())
		{
			vx = -1;
		}
		if (position.x >= NextPointX)
		{
			vx = 0;
			_Camera->GoLeftReset();
		}
	}
	else
	{
		UnControlable = false;
	}
}

void Character::beInvulnerable()
{
	invulnerable = true;
}

void Character::SetGround()
{
	if (!IsGround)
	IsGround = true;
	IsLimitJump = false;
	CharacterSprite->SetFrameRate(1.0f);
	//CharacterSprite->SetStatus(char_run);
}

bool Character::OnCollision(GameObject* object)
{
	int t = 0;
	switch (object->id)
	{
		case 1:
		{
			if (Box->Direction == Bottom)
				SetGround();
			if (Box->Direction == Top)
			{
				IsLimitJump = true;
				vy = 0;
			}
			break;
		}
		case 2:
		{
			if (Box->Direction)
			{
				DoHealthPoint(-8);
				/*if (GetHealthPoint()==0)
				MessageBox(NULL, TEXT("aaa"), TEXT("aaa"), MB_OK);*/
				beInvulnerable();

			}

			break;
		}
		case 4:
		{
			if (Box->Direction)
			{
				DoHealthPoint(-8);
				if (IsFaceRight)
				{
					vx = -20;
				}
				else
				{
					vx = +20;
				}
				/*if (GetHealthPoint()==0)
				MessageBox(NULL, TEXT("aaa"), TEXT("aaa"), MB_OK);*/
				beInvulnerable();

			}

			break;
		}
		case 5:
			if (IsCollision)
			{
				HaveMorphBall = true;
				for (int i = 0; i < 300000000; i++)
				{
					t++;
				}
				object->Destroy();
				return false;
			}
			break;
		case 10:
			if (!_Camera->IsGoingRight())
			{
				_Camera->GoRight();
				NextPointX = position.x + 16 * 5;
				vy = -1;
			}
			break;
		case 11:
			if (!_Camera->IsGoingLeft())
			{
				_Camera->GoLeft();
				NextPointX = position.x - 16 * 5;
				vy = -1;
			}
			break;

			
	}

	return true;
}

void Character::ToogleControlAble()
{
	UnControlable = !UnControlable;
}