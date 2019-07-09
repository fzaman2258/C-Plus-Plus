#ifndef __ZAMAN_FARHAN_HW5_Q2_CPP__
#define __ZAMAN_FARHAN_HW5_Q2_CPP__
#include "Zaman_Farhan_HW5_Q2.h"

template <class Item>
binaryTree<Item>::binaryTree()
{
	current_ptr=new btNode<Item>;
    root_ptr=new btNode<Item>;
    count=0;
}

template <class Item>
binaryTree<Item>::binaryTree(const binaryTree& source)
{
    root_ptr=tree_copy(source.root_ptr);
    current_ptr=root_ptr;
    current_ptr->set_parent(NULL);
    count=source.count;
}

template <class Item>
binaryTree<Item>::~binaryTree()
{
	tree_clear(root_ptr);
}
 
template <class Item>
void binaryTree<Item>::createFirstNode(const Item& entry)
{
	assert(size()==0);
	root_ptr= new btNode<Item>(entry);
	current_ptr=root_ptr;
	current_ptr->set_parent(NULL);
	count=1;
}

template <class Item>
void binaryTree<Item>::shiftToRoot()
{
	assert(size()>0);
	current_ptr=root_ptr;
}

template <class Item>
void binaryTree<Item>::shiftUp()
{
	assert(hasParent());
	current_ptr=current_ptr->parent();
}

template <class Item>
void binaryTree<Item>::shiftLeft()
{
	assert(hasLeft());
	current_ptr=current_ptr->left();
}

template <class Item>
void binaryTree<Item>::shiftRight()
{
	assert(hasRight());
	current_ptr=current_ptr->right();
}

template <class Item>
void binaryTree<Item>::change(const Item& new_entry)
{
	assert(size()>0);
	current_ptr->set_data(new_entry);
}

template <class Item>
void binaryTree<Item>::addLeft(const Item& entry)
{
	assert(size()>0);
	assert(!hasLeft());
	btNode<Item>* new_left_ptr;
	new_left_ptr=new btNode<Item>(entry,NULL, NULL, current_ptr);
	current_ptr->set_left(new_left_ptr);
	count++;
}


template <class Item>
void binaryTree<Item>::addRight(const Item& entry)
{
	assert(size()>0);
	assert(!hasRight());
	btNode<Item>* new_right_ptr;
	new_right_ptr=new btNode<Item>(entry,NULL, NULL, current_ptr);
	current_ptr->set_right(new_right_ptr);
	count++;
}


template <class Item>
void binaryTree<Item>::tree_clear(btNode<Item>*& root_ptr)
{
	btNode<Item>* child;
	if (root_ptr!= NULL)
	{
		child = root_ptr->left( );
		tree_clear(child);
		child = root_ptr->right( );
		tree_clear(child);
		delete root_ptr;
		root_ptr = NULL;
	}
}


template <class Item>
size_t binaryTree<Item>::size() const
{
	return count;
}

template <class Item>
Item binaryTree<Item>::retrieve() const
{
	return current_ptr->data();
}

template <class Item>
bool binaryTree<Item>::hasParent() const
{
	if(current_ptr!=root_ptr && size()>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class Item>
bool binaryTree<Item>::hasLeft() const
{
	assert(size()>0);
	if(current_ptr->left()!=NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class Item>
bool binaryTree<Item>::hasRight() const
{
	assert(size()>0);
	if(current_ptr->right()!=NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}   


template <class Item>
btNode<Item>* binaryTree<Item>::getRoot()
{
	assert(size()>0);
	return root_ptr;
}   

#endif