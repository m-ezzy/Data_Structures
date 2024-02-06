// singly linked list
// date 06 - 05 - 2022

#include <stdio.h>
#include <stdlib.h>

// number of nodes in linked list
int n;

struct node {
	int data;
	struct node *next;
};

// declaring first node of linked list
struct node *start = NULL;

int is_empty() {
	if(start == NULL) {
		printf("\n linked list is empty!");
		return 1;
	} else {
		return 0;
	}
}
int is_not_empty() {
	if(start == NULL) {
		printf("\n linked list is empty!");
		return 0;
	} else {
		return 1;
	}
}
//prints the linked list
void print() {
	int count = 1;
	struct node *p = start;
	
	if(is_empty()) {
		return;
	}
	
	//starts from the beginning, goes through all nodes, ends at last node
	while(p != NULL) {
		printf("\n %d %d", count, p->data);
		p = p->next;
		count++;
	}
}
struct node* create_new_node() {
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->next = NULL;

	printf("\n input new node data : ");
	scanf("%d", &new_node->data);

	return new_node;
}
int input_data() {
	int data;

	printf("\n Input new node data : ");
	scanf("%d", &data);

	return data;
}
//inserts a new node at the start location
void insert_before_start() {
	int data;

	//create a new node
	//struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *new_node = create_new_node();

	//new_node->data = input_data();

	//point it to old start node
	new_node->next = start;

	//point start to new start node
	start = new_node;
}
//inserts a new node at the end
void insert_after_end() {
	struct node *new_node = create_new_node();
	new_node->next = NULL;
	new_node->data = input_data();

	//special case if start is NULL
	if(start == NULL) {
		start = new_node;
		return;
	}

	//create ptr node for going through the list to find last node
	struct node *p = start;

	//getting last node in linked list
	while(p->next != NULL) {
	   p = p->next;
	}

	//linking new node to last node
	p->next = new_node;
}
//insert new node after specified nodes in the linked list
void insert_at_number() {
	int count = 1;
	int number;

	struct node *previous = NULL;
	struct node *current = start;
	struct node *new_node;
	
	printf("\n input number at which you want to insert a new node : ");
	scanf("%d", &number);

	if(number <= 0) {
		printf("\n invalid number!");
		return;
	}

	if(start == NULL && number != 1)
	{
		printf("\n linked list is empty! enter number 1");
		return;
	}
	
	while(count != number)
	{
		if(current == NULL)
		{
			//count holds next empty node number, therefore number of nodes in linked list is equal to count-1
			//you could still enter new node at count, the position after the last node
			printf("\n Entered number %d is greater than number of nodes %d + 1 in the linked list!",number,count-1);
			return;
		}
		
		previous = current;
		current = current->next;
		count++;
	}   
	//after count is equal to number, previous holds the position of node after which new node is to be inserted
	//and current holds the next node of new node
	
	new_node = (struct node*)malloc(sizeof(struct node));

	printf("\n Enter data in new node : ");
	scanf("%d",&new_node->data);
	
	//special case if start is NULL or linked list is empty
	if(start == NULL && number == 1)
	{
		//new node becomes the first node
		start = new_node;
		
		new_node->next = NULL;

		return;
	}
	
	//special case if you want new node to be the new first node
	if(start != NULL && number == 1)
	{
		//start node becomes second node
		new_node->next = start;
		
		//new node becomes start node
		start = new_node;
		
		return;
	}
	
	//new node is linked to previous node
	previous->next = new_node;
	
	//node at current number position is moved 1 step ahead
	new_node->next = current;
}
/*
void insert_with_data() {

}
*/
//inserts new node after given data in the linked list
void insert_after_data() {
	/*if(start == NULL) {
		printf("\n linked list is empty!");
		return;
	}*/

	int data;

	struct node *new_node = create_new_node();
	struct node *p = start;

	printf("\n input data of node after which to insert new node : ");
	scanf("%d", &data);

	while(p->data != data) {
		p = p->next;

		if(p == NULL) {
			printf("\n data is not in linked list ! ");
			return;
		}
	}
	new_node->next = p->next;
	p->next = new_node;
}
// insert data in ascending order
void insert_in_order() {
	struct node *new_node = create_new_node();
	struct node *p = start;

	while(p->data <= new_node->data) {
		p = p->next;

		if(p == NULL) {
			printf("\n data is not in linked list ! ");
			return;
		}
	}
	new_node->next = p->next;
	p->next = new_node;
}
// deletes a node from start position
void delete_start() {
	/*//checking if linked list is empty
	if(start == NULL){
		printf("\n linked list is empty!");
		return;
	}*/

	//keep second node location in temp pointer
	struct node *temp = start->next;

	//deallocate the allocated memory
	free(start);
	
	//assign location of second node to start node
	start = temp;
}
//deletes a node from end position
void delete_end() {
	/*//checking if linked list is empty
	if(start == NULL) {
		printf("\n linked list is empty!");
		return;
	}
	
	//special case checking if only 1 node in linked list
	if(start->next == NULL) {
		free(start);
		start = NULL;
		return;
	}*/

	struct node *previous = NULL;
	struct node *current = start;
	
	//getting last node in linked list
	while(current->next != NULL) {
		previous = current;
		current = current->next;
	}
	
	//previous node unlinks from last node, it is new last node
	previous->next = NULL;

	//deallocate the memory allocated to current node
	free(current);
}
//delete a node at specified number in the linked list
void delete_at_number() {
	int count = 1;
	int number;

	struct node *previous = NULL;
	struct node *current = start;
	struct node *temp;

	/*if(start == NULL) {
		printf("\n linked list is empty!");
		return;
	}*/
	
	printf("\n input number at which you want to delete a node : ");
	scanf("%d", &number);

	/*if(number <= 0) {
		printf("\n invalid number!");
		return;
	}*/
	
	if(number == 1) {
		//temp holds the new start node memory location
		temp = start->next;

		//deallocate the memory allocated to start node
		free(start);

		//second node becomes first node
		start = temp;
		
		return;
	}
	
	while(count != number) {
		previous = current;
		current = current->next;
		count++;
		
		if(current == NULL) {
			//count holds next empty node number, therefore number of nodes in linked list is equal to count-1
			printf("\n Entered number %d is greater than number of nodes %d in the linked list!",number,count-1);
			return;
		}
	}
	//after count is equal to number, previous holds the position of node after which a node is to be deleted
	//and current holds the node to be deleted
	
	previous->next = current->next;
	
	//deallocate the memory allocated to current node
	free(current);
}
//deletes a node with given data in the linked list
void delete_with_data() {
	int data;

	struct node *previous = NULL;
	struct node *current = start;
	struct node *temp;
	
	/*//checking if linked list is empty
	if(start == NULL)
	{
		printf("\n linked list is empty!");
		return;
	}*/
	
	printf("\n input data of node which you want to delete : ");
	scanf("%d", &data);
	
	//special case if data is in start node
	if(start->data == data) {
		//keep new start location in temp pointer
		temp = start->next;

		//deallocate the allocated memory
		free(start);
	
		//make second node as first
		start = temp;
		
		return;
	}

	while(current->data != data) {
		previous = current;
		current = current->next;
		
		if(current == NULL) {
			printf("\n entered data %d is not in linked list ! ", data);
			return;
		}
	}

	//if(previous == NULL) {}

	//linking previous node and next node
	previous->next = current->next;
	
	//deallocate the memory allocated to current node
	free(current);
}
/*
void delete_after_data() {

}*/

//starts the execution of program
void main() {
	int choice = 1;

	printf("\n 0 exit ");
	printf("\n 1 print ");

	printf("\n 2 insert before start ");
	printf("\n 3 insert after end ");
	printf("\n 4 insert at number ");
	//printf("\n 5 insert with data ");
	printf("\n 6 insert after data ");
	printf("\n 7 insert in order ");

	printf("\n 8 delete start ");
	printf("\n 9 delete end ");
	printf("\n 10 delete at number ");
	printf("\n 11 delete with data ");
	//printf("\n 12 delete after data ");

	while(choice != 0) {
		printf("\n __________________________________________________"); //50 dashes
		printf("\n Enter your choice : ");
		scanf("%d", &choice);

		switch (choice) {
			case 0 : {
				break;
			}
			case 1 : {
				print();
				break;
			}
			case 2 : {
				insert_before_start();
				break;
			}
			case 3 : {
				insert_after_end();
				break;
			}
			case 4 : {
				insert_at_number();
				break;
			}/*
			case 5 : {
				insert_with_data();
			}*/
			case 6 : {
				insert_after_data();
				break;
			}
			case 7 : {
				insert_in_order();
				break;
			}
			case 8 : {
				delete_start();
				break;
			}
			case 9 : {
				delete_end();
				break;
			}
			case 10 : {
				delete_at_number();
				break;
			}
			case 11 : {
				delete_with_data();
				break;
			}
			default : {
				printf("\n invalid choice number ! ");
				break;
			}
		}
	}
	//getch();
}
