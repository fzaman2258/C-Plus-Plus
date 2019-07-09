#ifndef __ZAMAN_FARHAN_HW4_Q5_H__
#define __ZAMAN_FARHAN_HW4_Q5_H__

#include "Zaman_Farhan_HW4_Q2.h"

template<class Item> 
class Stack2
{
	private:
		Queue<Item> input;
		Queue<Item> temp;
		size_t count;
		size_t cap;
	public:
		Stack2(size_t initSize=30);
		~Stack2();
		void push(const Item& entry);
		void pop();
		bool empty() const {return(count==0);}
		size_t size() const {return count;}
		Item top();
		void print();
};

#include "Zaman_Farhan_HW4_Q5.cpp"
#endif