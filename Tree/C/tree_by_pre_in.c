//creating tree with array from given pair of preorder, inorder, postorder
//all data should be of unique value

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char tree[100];

char preO[50] = {'A','B','D','E','H','C','F','I','J','G'};
char inO[50] = {'D','B','H','E','A','I','F','J','C','G'};
char postO[50];
int numNodes = 10; //number of nodes entered in pre order and in oreder arrays


/*
/ = z
+ = y
- = m
*/
/*
char preO[50] = {'z','y','m','a','b','t','c','d','e'};
char inO[50] = {'a','m','b','y','c','t','d','z','e'};
char postO[50];
int numNodes = 9;
*/
/*
int preO[50] = {65,66,68,69,72,67,70,73,74,71};
int inO[50] = {68,66,72,69,65,73,70,74,67,71};
int postO[50];
*/

int givenPreAndIn(int preS,int preE,int inS,int inE,int index){
	//printf("\n %d %d %d %d %d",preS,preE,inS,inE,index);

	if(preS > preE && inS > inE){
		return NULL;
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

	tree[index*2 + 1] = givenPreAndIn(preS + 1,num,inS,root - 1,index*2 + 1);
	tree[index*2 + 2] = givenPreAndIn(num + 1,preE,root + 1,inE,index*2 + 2);

	return preO[preS];
}

void main(){
	tree[0] = givenPreAndIn(0,numNodes - 1,0,numNodes - 1,0);

	for(int i=0 ; i<numNodes*2 ; i++){
		printf("\n %d %c",i,tree[i]);
		//puts(tree);
	}

    getch();
}
