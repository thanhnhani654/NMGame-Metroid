#include "Camera.h"

void Camera::Initialize()
{
	Follow = false;
	FollowX = false;
	FollowY = false;
	position.x = 16 * 32;
	position.y = 16 * 13;

}

float Camera::GetWidth()
{
	return ViewPortWidth;
}

float Camera::GetHieght()
{
	return ViewPortHeight;
}

void Camera::SetFollowX()
{
	FollowX = true;
	FollowY = false;
}

void Camera::SetFollowY()
{
	FollowX = false;
	FollowY = true;
}

void Camera::SetAttachObject(GameObject *object)
{
	AttachObject = object;
}

GameObject* Camera::GetAttachObject()
{
	return AttachObject;
}

void Camera::FollowObjectOn()
{
	Follow = true;
}

void Camera::FollowObjectOff()
{
	Follow = false;
}

void Camera::GoRight()
{
	bGoRight = true;
	NextPoint = position.x + 16 * 12 - 8;
}

bool Camera::IsGoingRight()
{
	return bGoRight;
}

bool Camera::GoRightFinish()
{
	return bGoRightFinish;
}

void Camera::GoRightReset()
{
	bGoRight = false;
	bGoRightFinish = false;
}

void Camera::GoLeft()
{
	bGoLeft = true;
	NextPoint = position.x - 16 * 12 - 8;
}

bool Camera::IsGoingLeft()
{
	return bGoLeft;
}

bool Camera::GoLeftFinish()
{
	return bGoLeftFinish;
}

void Camera::GoLeftReset()
{
	bGoLeft = false;
	bGoLeftFinish = false;
}

void Camera::Update()
{
	position.x += vx;
	position.y += vy;
	if (bGoRight)
	{
		Follow = false;
		vx = 1;

		if (position.x >= NextPoint)
		{
			Follow = true;
			vx = 0;
			bGoRightFinish = true;
			//AttachObject->vx = 0;
		}
	}
	if (bGoLeft)
	{
		Follow = false;
		vx = -1;

		if (position.x <= NextPoint)
		{
			Follow = true;
			vx = 0;
			bGoLeftFinish = true;
			//AttachObject->vx = 0;
		}
	}

	if (Follow)
	{
		if (FollowX)
		{
			position.x = AttachObject->GetPosition().x - 16 * 9;
		}
		if (FollowY)
		{
			position.y = AttachObject->GetPosition().y + 256 / 2;
		}
	}
}