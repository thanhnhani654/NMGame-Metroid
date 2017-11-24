#ifndef  _QUADTREE_H__
#define _QUADTREE_H__
#include <d3d9.h>
#include <d3dx9.h>
#include "Component\BoxCollider.h"
#include <vector>
#include <list>

using namespace std;

#define MAX_LEVEL 5
#define MAX_OBJECT_IN_REGION 5

class QuadTree
{
private:
	int						m_level;
	RECT*					m_region;
	vector <BoxCollider*>*	m_list;
	QuadTree**				m_nodes;
	bool IsContain(BoxCollider* boxcollider);
	void Split();
public:
	QuadTree();
	QuadTree(int level, RECT* region);
	~QuadTree();

	void Clear();
	void Insert(BoxCollider* boxcollider);
	void	Retrieve(vector <BoxCollider*>* return_object_list, BoxCollider* boxcollider);

};





#endif // ! _QUADTREE_H__
