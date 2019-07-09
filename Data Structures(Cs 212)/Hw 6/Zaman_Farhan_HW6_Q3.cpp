#ifndef __ZAMAN_FARHAN_HW6_Q3_CPP__
#define __ZAMAN_FARHAN_HW6_Q3_CPP__
#include "Zaman_Farhan_HW6_Q1.h"
#include <iostream>
#include <set>
#include <cstdlib>   
#include <queue>
#include <cassert>
using namespace std;

template <class Process,class Item, class Item2>
void dfs(Process f, GraphMatrix<Item>& g,Item2 a,bool marked[])
{
	set<size_t>::iterator it;
	set<size_t> adj= g.neighbor(a);
	marked[a]=true; 
	f(g[a]);
	for (it=adj.begin(); it!=adj.end(); it++)
	{
		if (!marked[*it])
		{
			dfs(f,g,*it,marked);
		}
	}
}

template <class Process,class Item,class Item2>
void depthfirst(Process f,GraphMatrix<Item>& g,Item2 start)
{
	bool marked[g.size()-1];
	assert(start<g.size());
	fill_n(marked,g.size(), false);
	dfs(f,g,start,marked);
}

template <class Process,class Item,class Item2>
void breadthfirst(Process f,GraphMatrix<Item>& g,Item2 start)
{
	bool marked[g.size()-1];
	set<size_t> adj;
	set<size_t>::iterator it;
	queue<size_t> vertex;
	assert(start<g.size());
	fill_n(marked,g.size(),false);
	marked[start] = true;
	f(g[start]);
	vertex.push(start);
	do{
		adj=g.neighbor(vertex.front());
		vertex.pop();
		for (it=adj.begin(); it!=adj.end(); it++)
		{
			if (!marked[*it])
			{
				marked[*it]=true;
				f(g[*it]);
				vertex.push(*it);
			}
		}
	}while (!vertex.empty());
}

#endif
