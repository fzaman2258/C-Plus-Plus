#ifndef __ZAMAN_FARHAN_HW6_Q4_CPP__
#define __ZAMAN_FARHAN_HW6_Q4_CPP__
#include "Zaman_Farhan_HW6_Q1.h"
#include <iostream>
#include <cassert>
#include <cstdlib>   
#include <set>
#include <queue>
#include <functional>
using namespace std;

template <class Item>
void dijkstra(GraphMatrix<Item>& g, size_t x)
{
	int distance[g.size()];
	int pre[g.size()];
	int u=0;
	size_t v=0;
	for (int i=0; i<g.size(); i++)
	{
		pre[i]=0;
		distance[i]=2000000;
	}
	distance[x]=0;
	set<size_t> adj;
	set<int> vertex;
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=0; i<g.size();i++)
	{
		q.push(distance[i]);
	}
	while(!q.empty())
	{
		u=q.top();
		q.pop();
		vertex.insert(u);
		adj=g.neighbor(v);
		set<size_t>::iterator it;
		for (it=adj.begin(); it!=adj.end(); it++)
		{
			v=*it;
			if(distance[v]>distance[u]+g.getEdge(u,v))
			{
				pre[v]=u;
				distance[v]=distance[u]+g.getEdge(u,v);	
			}
		}
	}
}

#endif