#ifndef __ZAMAN_FARHAN_HW6_Q1_H__
#define __ZAMAN_FARHAN_HW6_Q1_H__
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template <class Item>
class GraphMatrix
{
	private:
		Item* label;
		size_t used;
		size_t capacity;
		unsigned int** weightededges;
		size_t vertices;
	public:
		GraphMatrix(size_t initsize=30);
		~GraphMatrix();
		GraphMatrix(const GraphMatrix& source);
		void addvertex(const Item& label);
		void addedge(const Item source,const Item target,size_t weight);
		void removeedge(const Item source,const Item target);
		void print();
		size_t size() const;
		size_t num_edges();
		bool is_edge(const Item source,const Item sources) const;
		Item* neighbor(const Item source);
};

#include "Zaman_Farhan_HW6_Q1.cpp"
#endif