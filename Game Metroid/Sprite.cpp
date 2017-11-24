#include "Sprite.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include <dinput.h>

Sprite::Sprite(LPDIRECT3DDEVICE9 d3ddv,LPCWSTR Path, int Width, int Height)
{
	D3DXIMAGE_INFO info;
	HRESULT result;
	_SpriteHandler = NULL;
	_Image = NULL;
	
	result = D3DXCreateSprite(d3ddv, &_SpriteHandler);
	
	if (result != DI_OK)
		return;

	_Width = Width;
	_Height = Height;
	_Index = 0;
	
	result = D3DXGetImageInfoFromFile(Path, &info);

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		Path,
		info.Width, 
		info.Height,
		1,				
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),		
		&info,				
		NULL,
		&_Image);
	SetStatus(Animation::stand);
}

void Sprite::SetStatus(Animation t)
{
	if (CurrentAnim == t)
		return;
	
	CurrentAnim = t;
	_Begin = AnimMap[t]._Begin;
	_End = AnimMap[t]._End;
	_Index = _Begin;
}

void Sprite::Next()
{
	_Index +=1 ;

	if (_Index < _Begin || _Index > _End)
		_Index = _Begin;
}

void Sprite::Render(int X, int Y, int vx, int vy)
{
	HRESULT hr;

	RECT srect;
	int i = 0;
	srect.left = Pos[_Index].x;
	srect.top = Pos[_Index].y;
	srect.right = Pos[_Index].x + Pos[_Index].width;
	srect.bottom = Pos[_Index].y + Pos[_Index].height;

	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 position((float)X, (float)Y, 0);

	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = -vx;
	mt._42 = vy;
	D3DXVECTOR4 vp_pos;
	D3DXVec3Transform(&vp_pos, &position, &mt);

	D3DXVECTOR3 p(vp_pos.x, vp_pos.y, 0);
	D3DXVECTOR3 center((float)_Width / 2, (float)_Height / 2, 0);


	hr = _SpriteHandler->Draw(
		_Image,
		&srect, 
		NULL,
		&p,
		D3DCOLOR_XRGB(255, 255, 255)
	);

	if (hr != DI_OK)
		return;

	_SpriteHandler->End();

}

Sprite::~Sprite()
{
	delete[] Pos;
	_SpriteHandler->Release();
	_Image->Release();
}

Position* Sprite::GetPosition()
{
	return Pos;
}

void Sprite::AddAnimation(Animation eAnim, int Begin, int End)
{
	BeginEnd temp;
	temp._Begin = Begin;
	temp._End = End;
	AnimMap.insert(std::pair<Animation, BeginEnd>(eAnim, temp));
}
