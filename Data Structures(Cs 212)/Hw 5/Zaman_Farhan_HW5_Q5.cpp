#ifndef __ZAMAN_FARHAN_HW5_Q5_CPP__
#define __ZAMAN_FARHAN_HW5_Q5_CPP__
#include "Zaman_Farhan_HW5_Q5.h"
 
template <class Item>
Heap<Item>::Heap(size_t initCap)
{
	capacity=initCap;
	count=0;
    h=new Item[initCap];
}

template <class Item>
Heap<Item>::~Heap()
{

}
 
template <class Item>
Item Heap<Item>::minimum()
{
	Item x;
	for(int i=0; i<count; i++)
	{
		if(x>h[i])
		{
			x=h[i];
		}
	}
	return x;
}

template <class Item>
Item Heap<Item>::maximum()
{
	return h[0];
}

template <class Item>
void Heap<Item>::add(Item& entry)
{
	int i;
	if(capacity<count+1)
	{
		capacity++;
		resize(capacity);
	}
	h[count]=entry;
	i=count;
	count++;
	while (h[(i-1)/2]<h[i])
	{
		Item temp=h[i];
		h[i]=h[(i-1)/2];
		h[(i-1)/2]=temp;
		i=(i-1)/2;
	}
}


template <class Item>
Item Heap<Item>::remove()
{
	int i=0;
	Item copyRoot=h[0];
	h[0]=h[count-1];
	count--;
	while(h[i]<h[2*i+1]||h[i]<h[2*i+2])
	{
		Item temp=h[i];
		if(h[2*i+1]>h[2*i+2])
		{
			h[i]=h[2*i+1];
			h[2*i+1]=temp;
			i=2*i+1;
		}

		else
		{
			h[i]=h[2*i+2];
			h[2*i+2]=temp;
			i=2*i+2;
		}
	}
	return copyRoot;
}


template <class Item>
void Heap<Item>::resize(size_t cap)
{
	Item* largerArr=new Item[cap];
	for (int i = 0; i < count; i++)
	{
		largerArr[i]=h[i];
	}
	delete []h;
	h=largerArr;
	capacity=cap;
}

template <class Item>
void Heap<Item>::print()
{
	for (int i = 0; i < count; i++)
	{
		cout<<h[i]<<",";
	}

}

template <class Item>
void maxHeapify(Item arr[], size_t arrSize,size_t i){
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	if(l<arrSize && arr[l]>arr[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<arrSize && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		maxHeapify(arr, arrSize, largest);
	}

}

template <class Item>
void buildMaxHeap(Item arr[], size_t arrSize){
	for(int i=(arrSize/2)-1; i>=0; i--)
	{
		maxHeapify(arr, arrSize, i);
	}
}

template <class Item>
void heapsort(Item arr[], size_t arrSize)
{
	buildMaxHeap(arr, arrSize);
	for(int i=arrSize-1; i>=0; i--)
	{
		swap(arr[0],arr[i]);
		maxHeapify(arr, i, 0);
	}
}



template <class Item>
void printArray(Item arr[], size_t arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout<<arr[i]<<",";
	}
}


#endif