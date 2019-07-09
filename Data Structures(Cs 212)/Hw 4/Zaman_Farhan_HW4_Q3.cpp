#ifndef __ZAMAN_FARHAN_HW4_Q3_CPP__
#define __ZAMAN_FARHAN_HW4_Q3_CPP__

#include "Zaman_Farhan_HW4_Q3.h"

template<class Item>
void PriorityQueue<Item>::sort()
{
	for(int i=last; i>0; i--)
	{
		if(priority[i]>priority[i-1])
		{
			int temp=priority[i-1];
			priority[i-1]=priority[i];
			priority[i]=temp;	
			Item temp2=data[i-1];
			data[i-1]=data[i];
			data[i]=temp2;
		}
	}
}

template<class Item>
PriorityQueue<Item>::PriorityQueue(size_t initsize)
{
	data=new Item[initsize];
	first=0;
	last=initsize-1;
	count=0;
	capacity=initsize;
	priority=new int[initsize];
}

template<class Item>
PriorityQueue<Item>::~PriorityQueue()
{
	for(int i=0; i<count; i++)
	{
		pop();
	}
}

template<class Item>
void PriorityQueue<Item>::push(const Item& entry, int pr)
{
	assert(size()<capacity);
	last=nextIndex(last);
	data[last]=entry;
	priority[last]=pr;
	count++;
	if(pr>0)
	{
		sort();
	}
}

template<class Item>
void PriorityQueue<Item>::pop()
{
	assert(!empty());
	first=nextIndex(first);
	count--;
}

template<class Item>
Item PriorityQueue<Item>::top() const
{
	assert(!empty());
	return data[first];
}

template<class Item>
void PriorityQueue<Item>::print()
{
	assert(!empty());
	for(int i=first; i<last+1; i++)
	{
		cout<<data[i]<<endl;
	}
}

#endif