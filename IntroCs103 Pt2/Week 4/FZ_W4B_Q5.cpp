#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

struct node* makenode(int value)
{
	struct node *temp1;
	temp1= new node;
	temp1->data=value;
	temp1->next=NULL;
	return  temp1;
}

void insertEnd(struct node **head, struct node *newnode )
{
	struct node *current;
	current=*head;
	if(*head==NULL)
	{
		*head=newnode;
	}
	
	else
	{
		while(current->next!=NULL)
		{
			current=current->next;
		}
			current->next=newnode;	
	}

}


void printList(struct node *head)
{
	struct node *current;
	current=head;
	if(current==NULL)
	{
		cout<<"EMPTY LIST"<<endl;
	}
	
	
	else
	{
		cout<<"H";
		while(current!=NULL)
	
		{
			cout<<"--> "<<current->data;
			current=current->next;
		
		}

			cout<<endl;
	}
	
	

}
void deleteEnd(struct node** head)
{
	struct node *current=*head;
	struct node*prev=current;
	
	if(*head==NULL)
	{
		return ;
	}

	else
	{
		while(current->next!=NULL)
		{
			prev=current;
			current=current->next;
		}
		if(current==*head)
		{
			*head=NULL;
		}
		else
			prev->next=NULL;
	}
}

void clear(struct node **head)
{
	
	while(*head!=NULL)
	{	
		deleteEnd(head);
	}	

}


unsigned int length(struct node *head)
{
	struct node* current;
	current=head;
	unsigned int count=0;

	while(current!=NULL)
	{
		current=current->next;
		count++;
	}
	return count;
}


int main()
{
	node *head;
	head=NULL;
	
	cout<<length(head)<<endl;
	printList(head);

	node *store;
	store=makenode(1);


	insertEnd(&head,store);
	cout<<length(head)<<endl;
	printList(head);

	node*store2;
	store2=makenode(2);
	insertEnd(&head, store2);
	cout<<length(head)<<endl;
	printList(head);

	deleteEnd(&head);
	cout<<length(head)<<endl;
	printList(head);



	clear(&head);
	cout<<length(head)<<endl;
	printList(head);

	return 0;
}