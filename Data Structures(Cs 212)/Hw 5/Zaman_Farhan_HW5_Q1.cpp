#ifndef __ZAMAN_FARHAN_HW5_Q1_CPP__
#define __ZAMAN_FARHAN_HW5_Q1_CPP__
#include "Zaman_Farhan_HW5_Q1.h"

template <class Item>
size_t numOfNodes(const btNode<Item>* node_ptr)
{
    if(node_ptr==NULL)
    {
        return 0;
    }
    else
    {
       return 1 + numOfNodes(node_ptr->left()) + numOfNodes(node_ptr->right()); 
    }
}

template <class Item>
size_t depth(const btNode<Item>* node_ptr)
{
    if(node_ptr==NULL)
    {
        return 0;
    }
    else
    {
       int leftDepth=1;
       int rigthDepth=1;
       leftDepth+=depth(node_ptr->left);
       rigthDepth+=depth(node_ptr->right);

       if(leftDepth>rigthDepth)
       {
        return leftDepth;
       }
       else
       {
        return rigthDepth;
       }

    }
}

template <class Item>
void print(const btNode<Item>* node_ptr, size_t depth)
{
    cout<<setw(4*depth)<<"";
    if(node_ptr==NULL)
    {
        cout<<"[Empty]"<<endl;
    }
    else if(node_ptr->is_leaf())
    {
        cout<<node_ptr->data();
        cout<<"[Leaf]"<<endl;
    }
    else
    {
        cout<<node_ptr->data()<<endl;
        print(node_ptr->left(),depth+1);
        print(node_ptr->right(),depth+1);
    }
}

template <class Item>
btNode<Item>* tree_copy(const btNode<Item>* root_ptr)
{
    btNode<Item>* l_ptr;
    btNode<Item>* r_ptr;
    if (root_ptr == NULL)
    {
        return NULL;
    }
    else
    {
        l_ptr = tree_copy(root_ptr->left());
        r_ptr = tree_copy(root_ptr->right());
        return new btNode<Item>(root_ptr->data(),l_ptr,r_ptr);
    }
}


template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr)
{
    if (node_ptr != NULL)
    {
        inorder(f,node_ptr->left());
        f(node_ptr->data());
        inorder(f,node_ptr->right());
    }
}

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr)
{
    if (node_ptr != NULL)
    {
        postorder(f,node_ptr->left());
        postorder(f,node_ptr->right());
        f(node_ptr->data());
    }
}

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr)
{
    if (node_ptr != NULL)
    {
        f(node_ptr->data());
        preorder(f,node_ptr->left());
        preorder(f,node_ptr->right());
    }
}

#endif