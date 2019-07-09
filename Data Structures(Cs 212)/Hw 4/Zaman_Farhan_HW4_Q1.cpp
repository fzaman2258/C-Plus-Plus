#ifndef __ZAMAN_FARHAN_HW4_Q1_CPP__
#define __ZAMAN_FARHAN_HW4_Q1_CPP__

#include "Zaman_Farhan_HW4_Q1.h"

template <class Item>
Stack<Item>::Stack(size_t initSize)
{
	data=new Item[initSize];
	capacity=initSize;
	used=0;
}

template <class Item>
Stack<Item>::~Stack()
{
	for(int i=0; i<used; i++)
	{
		pop();
	}
}

template <class Item>
void Stack<Item>::push(const Item& entry)
{
	assert(size()<capacity);
	data[used]=entry;
	used++;
}

template <class Item>
void Stack<Item>::pop()
{
	assert(!empty());
	used--;
	
}

template <class Item>
Item Stack<Item>::top() const
{
	assert(!empty());
	return data[used-1];
}

template <class Item>
void Stack<Item>::print()
{
	assert(!empty());
	for(int i=0; i<used; i++)
	{
		cout<<data[i]<<endl;
	}
}

template <class Item>
void Stack<Item>::swap(Stack<Item>& s2)
{
	if(this==&s2)
	{
		return;
	}

	Stack<Item> s3;
	for(int i=0; i<s2.size(); i++)
	{
		s3.data[i]=s2.data[i];
	}
	s3.used=s2.used;
   	s3.capacity=s2.capacity;

	for(int i=0; i<used; i++)
	{
		s2.data[i]=data[i];
	}
	s2.used=used;
	s2.capacity=capacity;
	for(int i=0; i<s3.used; i++)
	{
		data[i]=s3.data[i];
	}
	used=s3.used;
	capacity=s3.capacity;
}

#endif