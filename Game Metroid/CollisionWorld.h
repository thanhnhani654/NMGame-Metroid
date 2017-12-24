#pragma once
#include "Component\BoxCollider.h"
#include "GameObject\GameObject.h"
#include "QuadTree.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

#ifndef _COLLISiONWORLD__H_
#define _COLLISIONWORLD__H_

#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))

using namespace std;

class  CollisionWorld
{
private:
//	static QuadTree* CreateQuadTree();

	
	
public:
	static void DetectCollision(HWND hwnd);
	static float IsColliderDAS(BoxCollider *box, BoxCollider *otherbox, float &normalx, float &normaly);

	static float IsColliderDAD(BoxCollider *box, BoxCollider *otherbox, float &normalx, float &normaly);
};
#endif // !_COLLISiONWORLD__H_