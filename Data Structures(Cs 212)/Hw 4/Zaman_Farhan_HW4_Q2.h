#ifndef __ZAMAN_FARHAN_HW4_Q2_H__
#define __ZAMAN_FARHAN_HW4_Q2_H__
	
#include <iostream>
#include <cassert>
using namespace std;

template<class Item>
class Queue
{
	private:
		Item* data;
		size_t first;
		size_t last;
		size_t count;
		size_t capacity;
		size_t nextIndex(size_t i) const {return(i+1)%capacity;}
	public:
		Queue(size_t initsize=30);
		~Queue();
		void push(const Item& entry);
		void pop();
		bool empty() const{return(count==0);}
		size_t size() const{return count;}
		Item front()const;
		void print();
		void swap(Queue<Item>& q2);		
};

#include "Zaman_Farhan_HW4_Q2.cpp"
#endif