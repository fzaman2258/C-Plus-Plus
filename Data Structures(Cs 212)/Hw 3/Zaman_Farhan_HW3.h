#ifndef __ZAMAN_FARHAN_HW3__H__
#define __ZAMAN_FARHAN_HW3__H__
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;
typedef int nodeDatatype;

class node
{
	public:

		node(const nodeDatatype& init_data=nodeDatatype(), node* init_next=NULL);
		void setdata(const nodeDatatype& init_data);
		void setnext(node* init_next);
		nodeDatatype getdata() const;
		const node* getnext() const;
		node* getnext();
		
	private:
		
		node* next;
		nodeDatatype data;
};

void insertfront(node* &head, node* place);
void insertfront(node* &head, nodeDatatype data);
void deletefront(node* &head);
void insertend(node* &head, node* place);
void insertend(node* &head, nodeDatatype data);
void deleteend(node* &head);
int length(const node* head);
void deleteall(node* &head);
void print(node* &head);
void insertpos(node* &head, node* place, int position);
void insertpos(node* &head, nodeDatatype data, int position);
void deletepos(node* &head, int position);
node* locate(node* head, int position);
const node* locate(const node* head, const int position);
node* search(node* head, nodeDatatype data);
const node* search(const node* head, const nodeDatatype data);
bool cycle(node* &head);
void swapadj(node* &head, int position);
void swap(node* &head, int position1, int position2);
void reverse(node* &head);



#endif


