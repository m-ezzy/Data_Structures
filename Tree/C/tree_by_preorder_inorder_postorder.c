//creating tree with array from given pair of preorder, inorder, postorder

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//#include <malloc.h>
/*
//char tree[100];
int tree[100];
//float tree3[100];

/*
char preO[50] = {'A','B','D','E','H','C','F','I','J','G'};
char inO[50] = {'D','B','H','E','A','I','F','J','C','G'};
char postO[50];
*/
/*
int preO[50] = {65,66,68,69,72,67,70,73,74,71};
int inO[50] = {68,66,72,69,65,73,70,74,67,71};
int postO[50];
*/
/*
int preO[50];
int inO[50];
int postO[50];
*/

int givenPreAndIn(int *tree[],int *preO[],int *inO[],int preS,int preE,int inS,int inE,int index){
	//printf("\n %d %d %d %d %d",preS,preE,inS,inE,index);

	if(preS > preE && inS > inE){
		return 0;
	}
	else if( preS >= preE && inS == inE){
		//printf("\n preO[preS] = %d %c",preO[preS],preO[preS]);
		//puts(tree);
		return preO[preS];
	}

	int root = 0;
	//for(root=0 ; preO[preS] != inO[root] ; root++);
	while(preO[preS] != inO[root]){
		root++;
	}
	//printf("\n root = %d",root);

	int num = preS + root - inS; //number of elements left on left side of root
	//int numRight = inE - root; //number of elements left on right side of root

	tree[index*2 + 1] = givenPreAndIn(&tree,&preO,&inO,preS + 1,num,inS,root - 1,index*2 + 1);
	tree[index*2 + 2] = givenPreAndIn(tree,preO,inO,num + 1,preE,root + 1,inE,index*2 + 2);

	return preO[preS];
}

void displayChar(int *tree[],int *preO[],int *inO[],int numNodes){
	char temp;
	for(int i=0 ; i<numNodes*2 ; i++){
		temp = tree[i];
		printf("\n %d %c",i,temp);
		//puts(tree);
	}
}

void displayInt(int *tree[],int *preO[],int *inO[],int numNodes){
	for(int i=0 ; i<numNodes*2 ; i++){
		printf("\n %d %d",i,tree[i]);
	}
}

void displayFloat(int *tree[],int *preO[],int *inO[],int numNodes){
	for(int i=0 ; i<numNodes*2 ; i++){
		printf("\n %d %f",i,tree[i]);
	}
}

void main(){
	//int i;
	int numNodes = 0;
	int dataType = 0;
	int temp;

	int tree[100];

	/*
	char preO[50] = {'A','B','D','E','H','C','F','I','J','G'};
	char inO[50] = {'D','B','H','E','A','I','F','J','C','G'};
	char postO[50];
	*/
	/*
	int preO[50] = {65,66,68,69,72,67,70,73,74,71};
	int inO[50] = {68,66,72,69,65,73,70,74,67,71};
	int postO[50];
	*/

	int preO[50];
	int inO[50];
	int postO[50];
	
	printf("\n enter the type of data in tree. 0 for char , 1 for int , 2 for float");
	scanf("\n %d",&dataType);

	printf("\n enter data into preOder. enter 0 to exit");
	while(1){
		scanf("\n %d",&temp);
		if(temp == 0){
			break;
		}
		preO[numNodes] = temp;
		numNodes++;
	}

	numNodes = 0;
	printf("\n enter data into inOder. enter 0 to exit");
	while(1){
		scanf("\n %d",&temp);
		if(temp == 0){
			break;
		}
		preO[numNodes] = temp;
		numNodes++;
	}
	numNodes = numNodes - 1;
	

	tree[0] = givenPreAndIn(tree,preO,inO,0,numNodes,0,numNodes,0);

	if(dataType == 0){
		displayChar(&tree,&preO,&inO,numNodes);
	}
	else if(dataType == 1){
		displayInt(tree,preO,inO,numNodes);
	}
	else{
		displayFloat(tree,preO,inO,numNodes);
	}

    getch();
}
