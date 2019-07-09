#ifndef __ZAMAN_FARHAN_HW5_Q4_H__
#define __ZAMAN_FARHAN_HW5_Q4_H__
#include "Zaman_Farhan_HW5_Q2.h"

template <class Item>
class binarySearchTree
{
	private:
		btNode<Item>* bstRoot;
	public:
	    binarySearchTree( );
	    ~binarySearchTree( );
	    btNode<Item>* minimum(btNode<Item>* x); 
	    btNode<Item>* maximum(btNode<Item>* x);
	    btNode<Item>* search(btNode<Item>* x, Item& k);
	    btNode<Item>* get_root();
	    void set_root(btNode<Item>* x);
	
};

template <class Item>
void add(binarySearchTree<Item>& T, btNode<Item>* z);

template <class Item>
void remove(binarySearchTree<Item>& T, btNode<Item>* z);

template <class Item>
void transplant(binarySearchTree<Item>& T, btNode<Item>* u, btNode<Item>* v);

#include "Zaman_Farhan_HW5_Q4.cpp" 
#endif