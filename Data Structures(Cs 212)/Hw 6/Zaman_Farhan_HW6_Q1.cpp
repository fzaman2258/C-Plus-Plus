#ifndef __ZAMAN_FARHAN_HW6_Q1_CPP__
#define __ZAMAN_FARHAN_HW6_Q1_CPP__
#include "Zaman_Farhan_HW6_Q1.h"

template <class Item>
GraphMatrix<Item>::GraphMatrix(size_t initsize)
{
	label=new Item[initsize];
	used=0;
	capacity=initsize;
	weightededges=new unsigned int[initsize][initsize];
	vertices=0;
}

template <class Item>
GraphMatrix<Item>::~GraphMatrix()
{

}

template <class Item>
GraphMatrix<Item>::GraphMatrix(const GraphMatrix& source)
{
	used=source.used;
	capacity=source.capacity;
	vertices=source.vertices;
	for(int i=0; i<used; i++)
	{
		label[i]=source.label[i];
	}
	for(int i=0; i<used; i++)
	{
		for(int j=0; j<used; j++)
		{
			weightededges[i][j]=source.weightededges[i][j];
		}
	}
}

template <class Item>
void GraphMatrix<Item>::addvertex(const Item& label)
{
	assert(used<capacity);
	label[vertices]=label;
	used++;
}

template <class Item>
void GraphMatrix<Item>::addedge(const Item source,const Item target,size_t weight)
{
	assert(source<used && target<used);
	int findsource=0;
	int findtarget=0;
	for(int i=0; i<used; i++)
	{
		if(label[i]==source)
		{
			findsource=i;
		}
		if(label[i]==target)
		{
			findtarget=i;
		}
	}
	weightededges[findsource][findtarget]=weight;
}

template <class Item>
void GraphMatrix<Item>::removeedge(const Item source,const Item target)
{
	assert(source<used && target<used);
	int findsource=0;
	int findtarget=0;
	for(int i=0; i<used; i++)
	{
		if(label[i]==source)
		{
			findsource=i;
		}
		if(label[i]==target)
		{
			findtarget=i;
		}
	}
	weightededges[findsource][findtarget]=0;
}

template <class Item>
void GraphMatrix<Item>::print()
{
	for(int i=0; i<used; i++)
	{
		cout<<label[i]<<endl;
	}
	for(int i=0; i<used; i++)
	{
		for(int j=0; j<used; j++)
		{
			cout<<weightededges[i][j];
		}
		cout<<endl;
	}
}

template <class Item>
size_t GraphMatrix<Item>::size() const
{
	return vertices;
}

template <class Item>
size_t GraphMatrix<Item>::num_edges()
{
	size_t edges;
	for(int i=0; i<used; i++)
	{
		for(int j=0; j<used; j++)
		{
			if(weightededges[i][j]>0)
			{
				edges++;
			}
		}
	}
	return edges;
}

template <class Item>
bool GraphMatrix<Item>::is_edge(const Item source,const Item target) const
{
	assert(source<used && target<used);
	int findsource=0;
	int findtarget=0;
	for(int i=0; i<used; i++)
	{
		if(label[i]==source)
		{
			findsource=i;
		}
		if(label[i]==target)
		{
			findtarget=i;
		}
	}
	return weightededges[findsource][findtarget]>0;
}

template <class Item>
Item* GraphMatrix<Item>::neighbor(const Item source)
{
	Item* neighbors;
	neighbors=new Item[used];
	int findsource=0;
	int adj=0;
	for(int i=0; i<used; i++)
	{
		if(label[i]==source)
		{
			findsource=i;
		}
	}
	for(int j=0; j<used; j++)
	{
		if(weightededges[findsource][j]>0)
		{
			neighbors[adj]=label[j];
		}
	}
}

#endif