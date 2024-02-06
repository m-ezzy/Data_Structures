//practical 1
//linear representation of tree using array
//find left right child of entered parent node

#include <stdio.h>
#include <conio.h>

int main()
{
	int tree[50];
	int data;
	int parent,child,side;
	int choice = 1;
	int i;

	// clrscr();

	while(choice == 1){
		printf("\n enter parent index, data in that node, which child left(1) or right(2)");
		scanf("\n %d %d %d",&parent,&data,&side);

		tree[parent*2 + side] = data;
		if(parent == -1){
			choice = 0;
		}
	}

	for(i=0 ; i<20 ; i++)
	{
		printf("\n %d element of tree : %d",i,tree[i]);
	}
	printf("\n enter parent node index");
	scanf("\n %d",&parent);

	printf("\n left child : %d \n right child : %d",tree[parent*2 + 1],tree[parent*2 + 2]);

	getch();

}