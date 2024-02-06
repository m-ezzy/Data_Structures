//bubble sort in C

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

//input data in array
void input_data(int array[], int size){
	int i;
	
	for(i=0 ; i<size ; i++){
		printf("\n Enter element at %d : ",i);
		scanf("%d",&array[i]);
	}
}

//print array
void print_array(int array[], int size){
	int i;
	
	for(i=0 ; i<size ; i++){
		printf("\n %d %d",i,array[i]);
	}
}

// perform the bubble sort
void bubble_sort(int array[], int size){
	int i,j;
	int temp;
	bool swapped;
	
	//loop to access each array element
	for(i=0; i<size-1 ; i++){
		
		//loop to compare array elements
		for(j=0 ; j<(size-1)-i ; j++){
			printf("\n items compared : [ %d , %d ] ",array[j],array[j + 1]);
			
			//compare two adjacent elements
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				
				swapped = true;
				printf(" => swapped [%d, %d]\n",array[j],array[j+1]);
			} 
			else{
				printf(" => not swapped\n");
			}
		}
	}
}

int main() {
	int array[100];
	int size;
	
	//clrscr();

	printf("\n Enter the number of elements you want to enter in array : ");
	scanf("%d",&size);

	//input data in array
	input_data(array, size);

	//sort the array
	bubble_sort(array, size);

	printf("sorted array in ascending order:\n");
	print_array(array, size);

	getch();
	return 1;
}
