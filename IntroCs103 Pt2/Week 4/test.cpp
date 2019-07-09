#include <iostream>
#include "singly_linked_list.h"

using namespace std;

int main() {
	// Create the head of the linked list
	Node *head;
	head = NULL;
	
	// Print out the length and the list
	// Prototype for length - unsigned int length(struct Node *head);
	// Prototype for printList - void printList(struct Node *head);
	cout << length(head) << endl;
	printList(head);



	// Create a node called temp1
	Node *temp1;
	temp1 = new Node;
	temp1->data = 1;
	temp1->next = NULL;

	// Insert it at the end
	// Prototype for insertEnd - void insertEnd(struct Node **head, struct Node *newNode);
	insertEnd(&head, temp1);

	// Print out the length and the list
	cout << length(head) << endl;
	printList(head);



	// Create a node called temp2 using function
	// Prototype for create - struct Node* create(int data);
	Node *temp2 = create(2);

	// Insert it at the end
	// Prototype for insertEnd - void insertEnd(struct Node **head, struct Node *newNode);
	insertEnd(&head, temp2);



	// Create a node called temp3 using function
	// Node *temp3 = create(-1);

	// Insert it in the front
	// insertFront(&head, temp3);

	// Print out the length and the list
	cout << length(head) << endl;
	printList(head);



	// Insert a new Node with value at the end
	// insertEnd(&head, 3);
	// cout << length(head) << endl;
	// printList(head);

	// Insert a new Node with value in the front
	// insertFront(&head, -2);
	// cout << length(head) << endl;
	// printList(head);



	// Delete the last element
	// Prototype for deleteEnd - void deleteEnd(struct Node **head);
	deleteEnd(&head);

	// Print out the length and the list
	cout << length(head) << endl;
	printList(head);



	// Clear the whole list
	// Prototype for clear - void clear(struct Node **head);
	clear(&head);

	// Print out the length and the list
	cout << length(head) << endl;
	printList(head);


	return 0;
}