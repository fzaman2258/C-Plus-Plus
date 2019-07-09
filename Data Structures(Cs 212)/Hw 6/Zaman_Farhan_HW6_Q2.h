#ifndef __ZAMAN_FARHAN_HW6_Q2_H__
#define __ZAMAN_FARHAN_HW6_Q2_H__
#include "Zaman_Farhan_HW3.h" //LINKED LIST CLASS
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <set>
using namespace std;

template <class Item>
class GraphList
{
	private:
		Item* label;
		size_t used;
		size_t capacity;
		node<Item>** weightededges;
		size_t vertices;
	public:
		GraphList(size_t initSize=30);
		~GraphList();
		GraphList(const GraphList& source);
		void addvertex(const Item& label);
		void addedge(const Item source,const Item target,size_t weight);
		void removeedge(const Item source,const Item target);
		void print();
		size_t size() const;
		size_t num_edges();
		bool is_edge(const Item source,const Item sources) const;
		Item* neighbor(const Item source);
};

#include "Zaman_Farhan_HW6_Q2.cpp"
#endif