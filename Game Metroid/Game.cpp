#include "Game.h"
#include <sstream>
#include <iostream>


//LPDIRECT3DSURFACE9 back_bufferr = NULL;


bool Game::GameInit(HWND hwnd)
{

	//Initialize Game Device
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddv);

	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back_buffer);

	if (d3ddv == NULL)
	{
		MessageBox(NULL, TEXT("Game Init False!"), TEXT("ERROR!"), MB_OK);
		return false;
	}

	d3ddv->CreateOffscreenPlainSurface(100, 100, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL);
	///////////////////////////////////////////Initialize Sprite Manager

	_SpriteManager = new SpriteManager();
	_SpriteManager->Initialize(d3ddv);
	_SpriteManager->LoadResource();

	///////////////////////////////////////////Initialize Scene

	Screen.Init();
	Screen.LoadScene();
	Screen.ActiveScene(0);

	////////////////////////////////////////////////////////

	
	return true;
}
int y;
bool Game::GameRun(HWND hwnd)
{
	d3ddv->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	UpdateInput(hwnd);
	
	Update();

	CollisionWorld::DetectCollision(hwnd);
	float n, m=0.5f;

	if (d3ddv->BeginScene())
	{
		
		d3ddv->ColorFill(surface, NULL, D3DCOLOR_XRGB(255, 0, 0));

		Draw();

		d3ddv->EndScene();
	}

	d3ddv->Present(NULL, NULL, NULL, NULL);

	return true;
}

bool Game::GameRelease()
{
	if (d3ddv != NULL)
		d3ddv->Release();
	if (d3d != NULL)
		d3d->Release();
	delete _SpriteManager;

	return true;
}

void Game::UpdateInput(HWND hwnd)
{
	Screen.UpdateInput();
}

void Game::Update()
{
	Screen.Update();
}

void Game::Draw()
{
	Screen.Draw();
}

