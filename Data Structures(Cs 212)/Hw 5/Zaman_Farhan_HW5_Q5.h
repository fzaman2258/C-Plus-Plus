#ifndef __ZAMAN_FARHAN_HW5_Q5_H__
#define __ZAMAN_FARHAN_HW5_Q5_H__
#include "Zaman_Farhan_HW5_Q1.h"
#include "Zaman_Farhan_HW5_Q3.h"

template <class Item>
class Heap
{
	private:
		Item* h;
		size_t capacity;
		size_t count;
	public:
	    static const size_t DEFAULTCAPACITY=30;
	    Heap(size_t initCap=DEFAULTCAPACITY);
	    ~Heap( );
	    Item minimum(); 
	    Item maximum();
	    void add(Item& entry);
	    Item remove();
	    void resize(size_t cap);
	    void print();
	
};

template <class Item>
void maxHeapify(Item arr[], size_t arrSize, size_t i);

template <class Item>
void buildMaxHeap(Item arr[], size_t arrSize);

template <class Item>
void heapsort(Item arr[], size_t arrSize);  

template <class Item>
void printArray(Item arr[], size_t arrSize);

#endif