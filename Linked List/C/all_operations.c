#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//use file for node data

//print choice list only once

//all in different file

//one operation in one exe file

//number of nodes in linked list
int total_nodes = 0;

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//checks if given node is allocated memory or is NULL
int node_is_empty(struct node *node)
{
    if(node == NULL){
        printf("\n node is empty!");
        return 1;
    }
    return 0;
}

//checks if linked list is empty
int linked_list_is_empty(struct node *start)
{
    if(start == NULL){
        printf("\n linked list is empty!");
        return 1;
    }
    return 0;
}

//creates a new node , enters data in it and returns that node
struct node *create_new_node()
{
    struct node *new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    
    if(new_node == NULL){
        printf("\n memory is insufficient!");
        return NULL;
    }

    new_node->next = NULL;

    printf("\n Enter data in new node : ");
    scanf("%d",&new_node->data);

    return new_node;
}

//display linked list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

/*
//insert a new node after the given previous node
void insert_after_node(struct node* previousNode)
{
    int newData;
    
    //get data for new node
    printf("\n Enter the data for new node : ");
    scanf("%d",&newData);

    //1. check if the given previous node is NULL
    if (previousNode == NULL)
    {
        printf("The given previous node is NULL, but it cannot be");
        return;
    }
        
    // 2. allocate new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // 3. put in the data
    newNode->data = newData;

    // 4. make next of new node as next of previous node
    newNode->next = previousNode->next;

    // 5. move the next of previous node as new node
    previousNode->next = newNode; 
} 

//insert new node after specified nodes in the linked list
void insert_after_node_num()
{
    int count = 1;
    int num;

    struct node *previous = &start;
    struct node *current = start.next;
    struct node *new;
    
    printf("input number of nodes after which you want to insert new node :");
    scanf("%d",&num);
    
    while(current != NULL)
    {
        if(count != num)
        {
            previous = current; //or previous = previous->next;
            current = current->next;
            count++;
        }
        else
        {
            new = (struct node *)malloc(sizeof(struct node));
            
            previous->next = new;
            new->next = current;
            
            printf("\n Enter the new node data : ");
            scanf("%d",&new->data);
            
            return;
        }
    }
}
*/


//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

void sort() {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}

void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
	
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
	
   printf("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   printList();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
	
   printf("\n");
   sort();
	
   printf("List after sorting the data: ");
   printList();
	
   reverse(&head);
   printf("\nList after reversing the data: ");
   printList();
}