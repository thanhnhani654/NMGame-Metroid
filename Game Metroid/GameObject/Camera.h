#pragma once
#include "GameObject.h"


class Camera : public GameObject
{
private:
	float ViewPortWidth;
	float ViewPortHeight;
	float LimitLeft;
	float LimitRight;
	float LimitAbove;
	float LimitBelow;

	bool Follow;
	bool FollowX;
	bool FollowY;

	bool bGoRight;
	bool bGoRightFinish;

	bool bGoLeft;
	bool bGoLeftFinish;
	float NextPoint;

	GameObject* AttachObject;

public:

	void Initialize();

	float GetWidth();
	float GetHieght();

	//void SetLimitX(float limitleft, float limitright);
	//void SetLimitY(float limitabove, float limitbelow);

	void SetFollowX();
	void SetFollowY();

	void SetAttachObject(GameObject *object);
	GameObject* GetAttachObject();

	void FollowObjectOn();
	void FollowObjectOff();

	void GoRight();
	bool GoRightFinish();
	void GoRightReset();

	void GoLeft();
	bool GoLeftFinish();
	void GoLeftReset();

	bool IsGoingRight();
	bool IsGoingLeft();

	void Update();
};