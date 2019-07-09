#ifndef __ZAMAN_FARHAN_HW4_Q3_H__
#define __ZAMAN_FARHAN_HW4_Q3_H__

#include <iostream>
#include <cassert>
using namespace std;

template <class Item>
class PriorityQueue
{
	private:
		Item* data;
		int* priority;
		size_t first;
		size_t last;
		size_t count;
		size_t capacity;
		size_t nextIndex(size_t i) const {return(i+1)%capacity;}
	public:
		void sort();
		PriorityQueue(size_t initsize=30);
		~PriorityQueue();
		void push(const Item& entry,int pr=0);
		void pop();
		bool empty() const{return(count==0);}
		size_t size() const{return count;}
		Item top() const;
		void print();

};

#include "Zaman_Farhan_HW4_Q3.cpp"
#endif