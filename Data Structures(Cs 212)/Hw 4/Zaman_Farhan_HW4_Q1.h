#ifndef __ZAMAN_FARHAN_HW4_Q1_H__
#define __ZAMAN_FARHAN_HW4_Q1_H__

#include <iostream>
#include <cassert>
using namespace std;

template <class Item>
class Stack
{
	private:
		Item* data;
		size_t used;
		size_t capacity;
	public:
		Stack(size_t initSize=30);
		~Stack();
		void push(const Item& entry);
		void pop();
		bool empty() const {return(used==0);}
		size_t size() const {return used;}
		Item top() const;
		void print();
		void swap(Stack<Item>& s2);
};

#include "Zaman_Farhan_HW4_Q1.cpp"
#endif
