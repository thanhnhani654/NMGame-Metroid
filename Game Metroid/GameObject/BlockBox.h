#pragma once
#include "GameObject.h"
#include "..\Component\BoxCollider.h"

class BlockBox : public GameObject
{
public:
	BoxCollider* Box;

	void Initialize(int ix, int iy, int iwidth, int iheight);

	void Update();
	
};