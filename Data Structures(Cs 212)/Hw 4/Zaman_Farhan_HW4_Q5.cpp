#ifndef __ZAMAN_FARHAN_HW4_Q5_CPP__
#define __ZAMAN_FARHAN_HW4_Q5_CPP__

#include "Zaman_Farhan_HW4_Q5.h"

template<class Item> 
Stack2<Item>::Stack2(size_t initSize)
{
	count=0;
	cap=initSize;
}

template<class Item> 
Stack2<Item>::~Stack2()
{
	for(int i=0; i<count; i++)
	{
		input.pop();
	}
}

template<class Item> 
void Stack2<Item>::push(const Item& entry)
{
	input.push(entry);
	count++;
}

template<class Item> 
void Stack2<Item>::pop()
{
	for(int i=0; i<count-1; i++)
	{
		temp.push(input.front());
		input.pop();
	}
	input.pop();
	count--;
	for(int i=0; i<count; i++)
	{
		input.push(temp.front());
		temp.pop();
	}
}

template<class Item> 
Item Stack2<Item>::top()
{
	for(int i=0; i<count-1; i++)
	{
		temp.push(input.front());
		input.pop();
	}
	Item store=input.front();
	input.pop();
	temp.push(store);
	for(int i=0; i<count; i++)
	{
		input.push(temp.front());
		temp.pop();
	}
	return store;
}

template<class Item> 
void Stack2<Item>::print()
{
	input.print();
}

#endif