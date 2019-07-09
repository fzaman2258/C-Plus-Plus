#ifndef __ZAMAN_FARHAN_HW4_Q2_CPP__
#define __ZAMAN_FARHAN_HW4_Q2_CPP__

#include "Zaman_Farhan_HW4_Q2.h"

template <class Item>
Queue<Item>::Queue(size_t initsize)
{
	data=new Item[initsize];
	first=0;
	last=initsize-1;
	count=0;
	capacity=initsize;
}

template <class Item>
Queue<Item>::~Queue()
{
	for(int i=0; i<count; i++)
	{
		pop();
	}
}

template <class Item>
void Queue<Item>::push(const Item& entry)
{
	assert(size()<capacity);
	last=nextIndex(last);
	data[last]=entry;
	count++;
}

template <class Item>
void Queue<Item>::pop()
{
	assert(!empty());
	first=nextIndex(first);
	count--;
}

template <class Item>
Item Queue<Item>::front()const
{
	assert(!empty());
	return data[first];
}

template <class Item>
void Queue<Item>::print()
{
	assert(!empty());
	for(int i=first; i<last+1; i++)
	{
		cout<<data[i]<<endl;
	}
}

template <class Item>
void Queue<Item>::swap(Queue<Item>& q2)
{
	if(this==&q2)
	{
		return;
	}

	Queue<Item> q3;
	for(int i=q2.first; i<q2.last+1; i++)
	{
		q3.data[i]=q2.data[i];
	}
	q3.count=q2.count;
   	q3.capacity=q2.capacity;
   	q3.first=q2.first;
   	q3.last=q2.last;

	for(int i=first; i<last+1; i++)
	{
		q2.data[i]=data[i];
	}
	q2.count=count;
	q2.capacity=capacity;
	q2.first=first;
	q2.last=last;

	for(int i=q3.first; i<q3.last+1; i++)
	{
		data[i]=q3.data[i];
	}
	count=q3.count;
	capacity=q3.capacity;
	first=q3.first;
	last=q3.last;
}

#endif