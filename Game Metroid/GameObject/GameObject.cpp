#include "GameObject.h"

GameObject::GameObject(float x, float y, float iwidth, float iheight)
{
	position.x = x;
	position.y = y;
	position.z = 0;
	width = iwidth;
	height = iheight;
}

void GameObject::UpdateInput()
{}

void GameObject::Update()
{}

void GameObject::Draw(int vx, int vy)
{}