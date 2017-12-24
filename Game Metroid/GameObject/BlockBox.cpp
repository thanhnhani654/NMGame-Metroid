#include "BlockBox.h"

void BlockBox::Initialize(int ix, int iy, int iwidth, int iheight)
{
	id = 1;
	position.x = ix;
	position.y = iy;
	width = iwidth;
	height = iheight;

	Box = new BoxCollider();
	Box->SetBox(position.x, position.y, width, height);
	Box->AttachObject(this);
	Box->Type = eType::Static;
}

void BlockBox::Update()
{
	Box->Update();
}