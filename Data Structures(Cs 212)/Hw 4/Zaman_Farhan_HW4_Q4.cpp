#ifndef __ZAMAN_FARHAN_HW4_Q4_CPP__
#define __ZAMAN_FARHAN_HW4_Q4_CPP__

#include "Zaman_Farhan_HW4_Q4.h"

template<class Item> 
Queue2<Item>::Queue2(size_t initsize)
{
	cap=initsize;
	count=0;
}

template<class Item> 
Queue2<Item>::~Queue2()
{
	for(int i=0; i<count; i++)
	{
		input.pop();
	}
}

template<class Item> 
void Queue2<Item>::push(const Item& entry)
{
	input.push(entry);
	count++;
}

template<class Item> 
void Queue2<Item>::pop()
{
	while(reverse.empty()==false)
	{
		reverse.pop();
	}
	for(int i=count; i>0; i--)
	{
		reverse.push(input.top());
		input.pop();
	}
	reverse.pop();
	count--;
	for(int i=count; i>0; i--)
	{
		input.push(reverse.top());
		reverse.pop();
	}
}

template<class Item> 
Item Queue2<Item>::front()
{
	while(reverse.empty()==false)
	{
		reverse.pop();
	}
	for(int i=count; i>0; i--)
	{
		reverse.push(input.top());
		input.pop();
	}
	Item temp=reverse.top();
	for(int i=count; i>0; i--)
	{
		input.push(reverse.top());
		reverse.pop();
	}
	return temp;
}

template<class Item> 
void Queue2<Item>::print()
{
	input.print();
}

#endif