#ifndef __ZAMAN_FARHAN_HW5_Q1_H__
#define __ZAMAN_FARHAN_HW5_Q1_H__
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdlib>    
#include <stack>
using namespace std;

template <class Item>
class btNode
{
	private:
	    Item data_field;
	    btNode* left_field;
	    btNode* right_field;
	    btNode* parent_field;
	public:
		btNode(const Item & init_data=Item(), btNode* init_left=NULL, btNode* init_right=NULL, btNode* init_parent=NULL)
		{
			data_field=init_data;
			left_field=init_left;
			right_field=init_right;
	        parent_field=init_parent;
		}
		btNode(const btNode& source)
		{
			data_field=source.data_field;
			left_field=source.left_field;
			right_field=source.right_field;
	        parent_field=source.parent_field;
		}
	    Item& data(){return data_field;}
	    btNode*& left(){return left_field;}
	    btNode*& right(){return right_field;}
	    btNode*& parent(){return parent_field;}
	    void set_data(const Item& new_data){data_field=new_data;}
	    void set_left(btNode* new_left){left_field=new_left;}
	    void set_right(btNode* new_right){right_field=new_right;}
	    void set_parent(btNode* new_parent){parent_field=new_parent;}
	    const Item& data() const{return data_field;}
	    const btNode* left() const {return left_field;}
	    const btNode* right() const {return right_field;} 
	    const btNode*& parent() const {return parent_field;}
	    bool is_leaf() const
	    {
	    	return (left_field==NULL) && (right_field==NULL);
	    }
};

template <class Item>
void print(const btNode<Item>* node_ptr, size_t depth);

template <class Item>
btNode<Item>* tree_copy(const btNode<Item>* root_ptr);

template <class Item>
size_t depth(const btNode<Item>* node_ptr);

template <class Item>
size_t numOfNodes(const btNode<Item>* node_ptr);

template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr);


#endif