//#include "QuadTree.h"
//#include <iostream>
//#include <sstream>
//
//QuadTree::QuadTree(int level, RECT* region)
//{
//	m_level = level;
//	m_region = region; 
//	m_nodes = NULL;
//	m_list = new vector <BoxCollider*>();
//}
//
//void QuadTree::Clear()
//{
//	if (m_nodes)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			m_nodes[i]->Clear();
//			m_nodes[i] = NULL;
//			//delete m_nodes[i];
//		}
//		delete[] m_nodes;
//	}
//
//	m_list->clear();
//
//	delete m_list;
//	delete m_region;
//}
//
//bool QuadTree::IsContain(BoxCollider* boxcollider)
//{
//	BoundingBox bound = boxcollider->GetBoundingBox();
//
//	if (bound.right < m_region->left ||
//		bound.bottom < m_region->top ||
//		bound.left > m_region->right ||
//		bound.top > m_region->bottom)
//	{
//		return false;
//	}
//	return true;
//}
//
//void QuadTree::Split()
//{
//	m_nodes = new QuadTree*[4];
//
//	RECT* temp = new RECT();
//	temp->left = m_region->left;
//	temp->top = m_region->top;
//	temp->right = (m_region->right + m_region->left) / 2;
//	temp->bottom = (m_region->bottom + m_region->top) / 2;
//
//	m_nodes[0] = new QuadTree(m_level + 1, temp);
//
//	temp->left = (m_region->right + m_region->left) / 2;
//	temp->right = m_region->right;
//
//	m_nodes[1] = new QuadTree(m_level + 1, temp);
//
//	temp->left = m_region->left;
//	temp->top = (m_region->bottom + m_region->top) / 2;
//	temp->right = (m_region->right + m_region->left) / 2;
//	temp->bottom = m_region->bottom;
//
//	m_nodes[2] = new QuadTree(m_level + 1, temp);
//
//	temp->left = (m_region->right + m_region->left) / 2;
//	temp->right = m_region->right;
//
//	m_nodes[3] = new QuadTree(m_level + 1, temp);
//
//	delete temp;
//}
//
//void QuadTree::Insert(BoxCollider* boxcollider)
//{
//	if (m_nodes)
//	{
//		if (m_nodes[0]->IsContain(boxcollider))
//			m_nodes[0]->Insert(boxcollider);
//		if (m_nodes[1]->IsContain(boxcollider))
//			m_nodes[1]->Insert(boxcollider);
//		if (m_nodes[2]->IsContain(boxcollider))
//			m_nodes[2]->Insert(boxcollider);
//		if (m_nodes[3]->IsContain(boxcollider))
//			m_nodes[3]->Insert(boxcollider);
//
//		return;
//	}
//
//	if (this->IsContain(boxcollider))
//		m_list->push_back(boxcollider);
//
//	if (m_list->size() > MAX_OBJECT_IN_REGION && m_level < MAX_LEVEL)
//	{
//		Split();
//
//		if (m_nodes[0]->IsContain(m_list->back()))
//			m_nodes[0]->Insert(m_list->back());
//		if (m_nodes[1]->IsContain(m_list->back()))
//			m_nodes[1]->Insert(m_list->back());
//		if (m_nodes[2]->IsContain(m_list->back()))
//			m_nodes[2]->Insert(m_list->back());
//		if (m_nodes[3]->IsContain(m_list->back()))
//			m_nodes[3]->Insert(m_list->back());
//
//		m_list->pop_back();	
//	}
//}
//
//void QuadTree::Retrieve(vector <BoxCollider*>* return_object_list, BoxCollider* boxcollider)
//{
//	
//	if (m_nodes)
//	{
//		if (m_nodes[0]->IsContain(boxcollider))
//			m_nodes[0]->Retrieve(return_object_list, boxcollider);
//		if (m_nodes[1]->IsContain(boxcollider))
//			m_nodes[1]->Retrieve(return_object_list, boxcollider);
//		if (m_nodes[2]->IsContain(boxcollider))
//			m_nodes[2]->Retrieve(return_object_list, boxcollider);
//		if (m_nodes[3]->IsContain(boxcollider))
//			m_nodes[3]->Retrieve(return_object_list, boxcollider);
//
//		return;
//	}
//
//	if (this->IsContain(boxcollider))
//	{
//		for (auto i = m_list->begin(); i != m_list->end(); i++)
//		{
//			if (boxcollider != *i)
//			{
//				return_object_list->push_back(*i);
//			}
//		}
//	}
//}
