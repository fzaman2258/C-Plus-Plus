#include "Zaman_Farhan_HW3.h"


int main()
{
	
	node* head=NULL;
	node* place=new node(20);
	insertfront(head,place);
	insertfront(head, 2);
	print(head);

	node* place1=new node(5);
	insertend(head,place1);
	insertend(head,5);
	cout<<"this is list"<<endl;
	print(head);

	int size=length(head);
	cout<<"This is size of list= "<<size<<endl;

	deletefront(head);
	cout<<"this is delete front"<<endl;
	print(head);

	deleteend(head);
	cout<<"this is delete end"<<endl;
	print(head);



	insertpos(head,3,1);
	insertpos(head,4,1);
	cout<<"this is list"<<endl;
	print(head);

	deletepos(head,2);
	cout<<"this is delete pos"<<endl;
	print(head);

	insertfront(head,place);
	insertfront(head, 2);
	insertend(head,place);
	insertend(head,5);
	cout<<"current list"<<endl;
	print(head);

	int locatedd;
	cout<<"what positon u want"<<endl;
	cin>>locatedd;
	node* located=locate(head,locatedd);
	cout<<"this was lcoated "<<located->getdata()<<endl;

	int searched;
	cout<<"what date u searching for"<<endl;
	cin>>searched;
	node* found=search(head,searched);
	cout<<"this was found"<<found->getdata()<<endl;
	bool truth=cycle(head);
	cout<<"this is true for cycle=1 or false for no cycle=0 =="<<truth<<endl;
	int space;
	cout<<"which positon to swap"<<endl;
	cin>>space;
	swapadj(head,space);
	print(head);
	int num1,num2;
	cout<<"both palces to swap"<<endl;
	cin>>num1>>num2;
	swap(head,num1,num2);
	print(head);






	/*
	cout<<"t
	his is get data= "<<head->getdata()<<endl;
	cout<<"this is get link= "<<head->getnext()<<endl;
	cout<<"this is inital list"<<endl;
	print(head);

	int x;
	cout<<"input data into first node"<<endl;
	cin>>x;
	node* list1=new node(x);
	list1->setdata(5);
	head->setnext(list1);
	cout<<"this a list of 1 item"<<endl;
	print(head);

	node*list2=new node(3);
	insertfront(head,list2);
	cout<<"this list has 2 things (insert front)"<<endl;
	print(head);

	deletefront(head);
	cout<<"list of 1 thing left(delete front)"<<endl;
	print(head);

	node* list3=new node(0);
	insertend(head,list3);
	cout<<"list of 2 things(insert end)"<<endl;
	print(head);

	deleteend(head);
	cout<<"list of 1 things(delete end)"<<endl;
	print(head);

	node* list4=new node(1);
	insertend(head,list4);
	cout<<"list of 2 things to check size fucntion"<<endl;
	print(head);
	int size=length(head);
	cout<<"this is the size of the list= "<<size<<endl;

	int position, entry;
	cout<<"entry data"<<endl;
	cin>>entry;
	cout<<"position starts at 1"<<endl;
	cin>>position;
	node *list5=new node(entry);
	insertpos(head,list5,position);
	cout<<"this is insert position "<<endl;
	print(head);

	int pos;
	cout<<"which node u wanan delete"<<endl;
	cin>>pos;
	deletepos(head,pos);
	cout<<"this is delete position "<<endl;
	print(head);


	deleteall(head);
	cout<<"this is delete all "<<endl;
	print(head);

	int data,data1,data2,pos1;
	cout<<"enter data for insert front funciton"<<endl;
	cin>>data;
	insertfront(head,data);
	cout<<"this is the list "<<endl;
	print(head);

	cout<<"enter data for insert end function"<<endl;
	cin>>data1;
	insertend(head,data1);
	cout<<"this is the list "<<endl;
	print(head);

	cout<<"enter data for insert positon"<<endl;
	cin>>data2;
	cout<<"enter pos"<<endl;
	cin>>pos1;
	insertpos(head,data2,pos1);
	cout<<"this is list"<<endl;
	print(head);

	/*cout<<"what position do you want to locate"<<endl;
	int loc;
	cin>>loc;
	node* located=locate(head,loc);
	cout<<"this is the located node and its data"<<endl;
	cout<<located->getdata()<<endl;

	cout<<"what data do you want to find "<<endl;
	int find;
	cin>>find;
	node *found=search(head,find);
	cout<<"here is the node and its dtata"<<endl;
	cout<<found->getdata()<<endl;
	
	
	
	//reverse(head);
	
	insertfront(head,5);
	insertend(head,10);
	insertfront(head,7);
	insertend(head,2);
	print(head);

	cout<<"this si reversed list"<<endl;
	reverse(head);
	print(head);
	/*int adj;
	cout<<"What position do you want to swap "<<endl;
	cin>>adj;
	swapadj(head,adj);
	print(head);
	int pos5, pos6;
	cout<<"What 2 positions do you want to swap"<<endl;
	cin>>pos5;
	cin>>pos6;
	swap(head,pos5,pos6);
	cout<<" this is swapping 1 positons"<<endl;
	print(head);

*/


	return 0;

}