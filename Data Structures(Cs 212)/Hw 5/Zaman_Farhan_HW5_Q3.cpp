#ifndef __ZAMAN_FARHAN_HW5_Q3_CPP__
#define __ZAMAN_FARHAN_HW5_Q3_CPP__
#include "Zaman_Farhan_HW5_Q3.h"


template <class Item>
binaryTree<Item>::binaryTree(size_t initCap)
{
    capacity=initCap;
    tree=new Item[initCap];
}

template <class Item>
binaryTree<Item>::binaryTree(const binaryTree& source)
{
	current=source.current;
    root=source.root;
    count=source.count;
    capacity=source.capacity;
    tree=new Item[capacity];
    for(int i=0; i<capacity; i++)
    {
    	tree[i]=source.tree[i];
    }
}

template <class Item>
binaryTree<Item>::~binaryTree()
{

}
 
template <class Item>
void binaryTree<Item>::createFirstNode(const Item& entry)
{
	assert(size()==0);
	current=0;
    root=0;
    count=1;
    tree[current]=entry;
}

template <class Item>
void binaryTree<Item>::shiftToRoot()
{
	assert(size()>0);
	current=0;
}

template <class Item>
void binaryTree<Item>::shiftUp()
{
	assert(hasParent());
	current=(current-1)/2;
}

template <class Item>
void binaryTree<Item>::shiftLeft()
{
	assert(hasLeft());
	current=2*current+1;
}

template <class Item>
void binaryTree<Item>::shiftRight()
{
	assert(hasLeft());
	current=2*current+2;
}

template <class Item>
void binaryTree<Item>::change(const Item& new_entry)
{
	assert(size()>0);
	tree[current]=new_entry;
}

template <class Item>
void binaryTree<Item>::addLeft(const Item& entry)
{
	assert(size()>0);
	assert(!hasLeft());
	assert(2*current<count);
	if(capacity<count+1)
	{
		capacity++;
		resize(capacity);
	}

	tree[2*current+1]=entry;
	count++;
}

template <class Item>
void binaryTree<Item>::addRight(const Item& entry)
{
	assert(size()>0);
	assert(!hasRight());
	assert(hasLeft());
	if(capacity<count+1)
	{
		capacity++;
		resize(capacity);
	}

	tree[2*current+2]=entry;
	count++;
}

template <class Item>
size_t binaryTree<Item>::size() const
{
	return count;
}

template <class Item>
Item binaryTree<Item>::retrieve() const
{
	return tree[current];
}

template <class Item>
bool binaryTree<Item>::hasParent() const
{
	if(current!=root && size()>0)
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
	if(2*current+1<count)
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
	if(2*current+2<count)
	{
		return true;
	}
	else
	{
		return false;
	}
}   

template <class Item>
void binaryTree<Item>::resize(size_t cap)
{
	Item* largerArr=new Item[cap];
	for (int i = 0; i < count; i++)
	{
		largerArr[i]=tree[i];
	}
	delete []tree;
	tree=largerArr;
	capacity=cap;
}

#endif