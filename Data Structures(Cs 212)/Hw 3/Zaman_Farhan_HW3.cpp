#ifndef __ZAMAN_FARHAN_HW3_CPP__
#define __ZAMAN_FARHAN_HW3_CPP__
#include "Zaman_Farhan_HW3.h"


node::node(const nodeDatatype& init_data, node* init_next)
{
	data=init_data;
	next=init_next;
}

void node::setdata(const nodeDatatype& init_data)
{ 
	data=init_data;
}

void node::setnext(node* init_next)
{
	next=init_next;
}

nodeDatatype node::getdata() const
{
	return data;
}
const node* node::getnext() const
{
	return next;
}

node* node::getnext()
{
	return next;
}

void insertfront(node* &head, node* place)
{
	insertfront(head, place->getdata());
}

void insertfront(node* &head, nodeDatatype data)
{
	head=new node(data,head);
}

void deletefront(node* &head)
{
	node* curr;
	curr=head;
	head=head->getnext();
	delete curr;
}

void insertend(node* &head, node* place)
{
	insertend(head, place->getdata());
}

void insertend(node*& head, nodeDatatype data)
{
	if(head==NULL)
	{
		insertfront(head,data);
		return;
	}
	node* place=new node(data);
	node*curr;
	curr=head;
	while(curr->getnext()!=NULL)
	{
		curr=curr->getnext();
	}
	curr->setnext(place);
}

void deleteend(node* &head)
{
	node* curr, *prev;
	curr=head;
	if(head==NULL)
	{
		cout<<"Empty list"<<endl;
	}
	else if(head->getnext()==NULL)
	{
		delete head;
	}
	else
	{
		while(curr->getnext()!=NULL)
		{
			prev=curr;
			curr=curr->getnext();
		}
		prev->setnext(NULL);
		delete curr;
	}
}

int length(const node* head)
{
	int count=0;
	const node* curr;
	curr=head;
	while(curr!=NULL)
	{
		curr=curr->getnext();
		count++;
		
	}
	return count;
}

void deleteall(node* &head)
{
	while(head!=NULL)
	{
		deletefront(head);
	}
}

void print(node* &head)
{
	node* curr;
	curr=head;
	while(curr!=NULL)
	{
		cout<<curr->getdata()<<endl;
		curr=curr->getnext();
	}
}

void insertpos(node* &head, node* place, int position)
{
	insertpos(head,place->getdata(),position);
}

void insertpos(node* &head, nodeDatatype data, int position)
{
	assert(head!=NULL && position>0);
	if(position==1)
	{
		insertfront(head,data);
		return;
	}

	node* curr=head;
	node* prev=head;
	int count=0;
	prev=head;
	while(count!=position-1)
	{
		prev=curr;
		curr=curr->getnext();
		count++;
	}
	node* place=new node(data);
	prev->setnext(place);
	prev=prev->getnext();
	prev->setnext(curr);
}

void deletepos(node* &head, int position)
{
	assert(head!=NULL && position>0);
	if(position==1)
	{
		deletefront(head);
		return;
	}

	node* curr, *prev;
	curr=head;
	int count=0;
	while(count!=position-1)
	{
		prev=curr;
		curr=curr->getnext();
		count++;
	}
	prev->setnext(curr->getnext());
	delete curr;

}

node* locate(node* head, int position)
{
	assert(position<=length(head));
	node* curr;
	curr=head;
	int count=0;
	while(count!=position-1)
	{
		curr=curr->getnext();
		count++;
	}

	return curr;
}

const node* locate(const node* head, const int position)
{
	assert(position<=length(head));
 	const node* curr;
	curr=head;
	int count=0;
	while(count!=position-1)
	{
		curr=curr->getnext();
		count++;
	}

	return curr;

}

node* search(node* head, nodeDatatype data)
{
	assert(head!=NULL);
	node* curr;
	curr=head;
	while(curr->getnext()!=NULL)
	{
		if(curr->getdata()==data)
		{
			return curr;
		}
		else
		{
			curr=curr->getnext();
		}
	}
	return NULL;
}

const node* search(const node* head, const nodeDatatype data)
{
	assert(head!=NULL);
	const node* curr;
	curr=head;
	while(curr->getnext()!=NULL)
	{
		if(curr->getdata()==data)
		{
			return curr;
		}
		else
		{
			curr=curr->getnext();
		}
	}
	return NULL;
}

bool cycle(node* &head)
{
	if(head==NULL || head->getnext()==NULL || head->getnext()->getnext()==NULL)
	{
		return false;
	}
	node* prev=head;
	node* curr=head->getnext();
	curr=curr->getnext();
	while(curr!=NULL && prev!=NULL)
	{
		if(curr==prev)
		{
			return true;
		}
		curr=curr->getnext();
		if(curr==NULL)
		{
			return false;
		}
		curr=curr->getnext();
		prev=prev->getnext();
	}
	return false;
}

void swapadj(node* &head, int position)
{
	int len=length(head);
	assert(position+1<len && len>2);
	assert(head!=NULL && head->getnext()!=NULL);

	if(position=1)
	{
		node* curr=head->getnext();
		head->setnext(curr->getnext());
		insertfront(head,curr->getdata());
		delete curr;
		return;
	}
	node* prev=locate(head,position);
	node* place=prev->getnext();
	if(prev->getnext()==NULL || place->getnext()==NULL)
	{
		return;
	}

	node* after=place->getnext();
	node* temp=place;
	prev->setnext(after);
	place->setnext(after->getnext());
	after->setnext(temp);
}

void swap(node* &head, int position1, int position2)
{
	if(position1==position2)
	{
		return;
	}
	if(position1=position2+1)
	{
		swapadj(head, position2);
		return;
	}
	if(position2=position1+1)
	{
		swapadj(head,position1);
		return;
	}
	assert(position1<length(head) && position2<length(head));

	node* prev1, *curr1, *prev2, *curr2,*after2;
	int count1=0,count2=0;
	curr1=head;
	curr2=head;
	while(prev1->getnext()!=NULL && count1!=position1)
	{
		prev1=curr1;
		curr1=curr1->getnext();
		count1++;
	}

	while(prev2->getnext()!=NULL && count2!=position2)
	{
		prev2=curr2;
		curr2=curr2->getnext();
		count2++;
	}
	after2=curr2->getnext();
	prev1->setnext(curr2);
	curr2->setnext(curr1->getnext());
	curr1->setnext(after2);
	prev2->setnext(curr1);

	node* temp=curr2->getnext();
	curr2->setnext(curr1->getnext());
	curr1->setnext(temp);

}

void reverse(node*& head)
{
	node* reverse=NULL;
	node* curr;
	curr=head;
	while(curr!=NULL)
	{
		insertfront(reverse,curr->getdata());
		curr=curr->getnext();
	}
	head=reverse;
}

#endif