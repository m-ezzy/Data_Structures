//creating tree through linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct node *left;
    struct node *right
};
typedef struct node NODE;

//struct node *ptr;

//int count = 0;

void createNode(NODE *p){
	int data;

	//if(p == NULL){
		printf("\n enter the data : ");
		scanf("%d",&data);

		if(data == 0){
			return;
		}

		printf("123");
		NODE *temp;
		temp = (NODE *)malloc(sizeof(NODE));
		p = temp;

		p->data = data;
		p->left = NULL;
		p->right = NULL;
		//return;
	//}
	
	createNode(p->left);
    createNode(p->right);
	
	/*
	else if(p->left == NULL){
		createNode(p->left);
	}
	else if(p->left != NULL && p->right == NULL){
		createNode(p->right);
	}
	else if(p->left != NULL && p->right != NULL){
		createNode(p->left);
	}
	*/
}

void preOrder(NODE *ptr){
	if(ptr != NULL){
        printf("\n %d ",ptr->data);
        //count++;
		preOrder(ptr->left);
        preOrder(ptr->right);
    }
    printf("\n display was done!");
}

void main(){
	int option = 1;

	struct node *root; //head //first //top //start
	root = NULL;
	root->left = NULL;
	root->right = NULL;
	
    /*
	root = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    */

    //while(option == 1){
        createNode(root);

        //printf("\n enter 0 to exit : ");
        //scanf("%d",&option);
    //}

    //count = 0;
	preOrder(root);

    getch();
}
