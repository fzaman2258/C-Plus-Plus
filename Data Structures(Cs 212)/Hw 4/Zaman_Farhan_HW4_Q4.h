#ifndef __ZAMAN_FARHAN_HW4_Q4_H__
#define __ZAMAN_FARHAN_HW4_Q4_H__

#include "Zaman_Farhan_HW4_Q1.h"

template<class Item> 
class Queue2
{
	private:
		Stack<Item> input;
		Stack<Item> reverse;
		size_t count;
		size_t cap;
	public:
		Queue2(size_t initsize=30);
		~Queue2();
		void push(const Item& entry);
		void pop();
		bool empty() const {return(count==0);}
		size_t size() const {return count;}
		Item front();
		void print();
};

#include "Zaman_Farhan_HW4_Q4.cpp"
#endif