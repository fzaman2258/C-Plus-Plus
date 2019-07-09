#ifndef __ZAMAN_FARHAN_HW5_Q4_CPP__
#define __ZAMAN_FARHAN_HW5_Q4_CPP__
#include "Zaman_Farhan_HW5_Q4.h"

template <class Item>
binarySearchTree<Item>::binarySearchTree( )
{
	bstRoot=NULL;
}

template <class Item>
binarySearchTree<Item>::~binarySearchTree()
{
	delete bstRoot;
}
 
template <class Item>
btNode<Item>* binarySearchTree<Item>::minimum(btNode<Item>* x)
{
	while(x->left()!=NULL)
	{
		x=x->left();
	}
	return x;
}


template <class Item>
btNode<Item>* binarySearchTree<Item>::get_root()
{
	return bstRoot;
}

template <class Item>
void binarySearchTree<Item>::set_root(btNode<Item>* x)
{
	bstRoot=x;
}


template <class Item>
btNode<Item>* binarySearchTree<Item>::maximum(btNode<Item>* x)
{
	while(x->right()!=NULL){
		x=x->right();
	}
	return x;
}

template <class Item>
btNode<Item>* binarySearchTree<Item>::search(btNode<Item>* x, Item& k)
{
	if(x==NULL || k==x->data())
	{
		return x;
	}
	if (k<x->data())
	{
		return search(x->left(),k);
	}
	else 
	{
		return search(x->right(),k);
	}

}

template <class Item>
void add(binarySearchTree<Item>& T, btNode<Item>* z)
{
	btNode<Item>* y=NULL;
	btNode<Item>* x=T.get_root();
	while(x!=NULL)
	{
		y=x;
		if ((z->data()) < (x->data()))
		{
			x=x->left();
		}
		else 
		{
			x=x->right();
		}
	}
	z->set_parent(y);
	if(y==NULL)
	{
		T.set_root(z);
	}
	else if (z->data() < y->data())
	{
		y->set_left(z);
	}
	else
	{
		y->set_right(z);
	}

}


template <class Item>
void transplant(binarySearchTree<Item>& T, btNode<Item>* u, btNode<Item>* v)
{
	if(u->parent()==NULL)
	{
		T.set_root(v);
	}
	else if (u==u->parent()->left())
	{
		u->parent()->set_left(v);
	}
	else 
	{
		u->parent()->set_right(v);
	}
	if(v!=NULL)
	{
		v->set_parent(u->parent());
	}
}

template <class Item>
void remove(binarySearchTree<Item>& T, btNode<Item>* z)
{
	if(z->left()==NULL)
	{
		transplant(T,z,z->right());
	}
	else if (z->right()==NULL)
	{
		transplant(T,z,z->left());
	}
	else
	{
		btNode<Item>* y=T.minimum(z->right());
		if (y->parent()!=z)
		{
			transplant(T,y,y->right());
			y->set_right(z->right());
			y->right()->set_parent(y);
		}

		transplant(T,z,y);
		y->set_left(z->left());
		y->left()->set_parent(y);
	}
}

#endif