// practical 9
// write a program to input n elements in one dimensional array
// and sort them using bubble sort algorithm
// display sorted array

//optimized bubble sort in C

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

//swapping values of 2 memory locations
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// performs bubble sort
void bubbleSort(int array[], int size) {
	//declaring loop variables
	int i;
	int j;
	int temp;
	bool swapped = true;
	
	//loop to access each array element
	for(i = 0 ; i <= size - 2 ; i++)
	{
		//check if swapping occurs
		swapped = false;
	
		//loop to compare array elements
		for(j = 0 ; j <= size - i - 2 ; j++)
		{
			//compare two consecutive array elements
			//change > to < to sort in descending order
			if(array[j] > array[j + 1])
			{
				//swapping occurs if elements are not in the intended order
				swap(&array[j], &array[j + 1]);
				
				/*
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				*/
				
				swapped = true;
			}
		}
	
		//no swapping means array is already sorted , so no need for further comparison
		if(swapped == false)
		{
			break;
		}
	}
}

//print array
void printArray(int array[], int size)
{
	int i;
	for (i=0 ; i<size ; i++)
	{
		printf("\n %d %d",i,array[i]);
	}
}

// program execution starts from main method
void main() {
	//size of array / number of elements in array
	int size = 0;
	
	int data;
	
	int count = 0;

	//data in 1 dimensional array
	int array[1000];
	//int data[] = {-2, 45, 0, 11, -9};

	//clrscr();
	
	//input data in array
	printf("\n Enter data in array , Enter -1000 to exit");

	//special case if you want to avoid putting if condition inside the loop
	printf("\n index %d : ",count);
	scanf("%d",&data);
	
	do
	{
		array[count] = data;

		count++;

		printf("\n index %d : ",count);
		scanf("%d",&data);
	}
	while(data != -1000);

	//finding the array's length
	size = sizeof(array) / sizeof(array[0]);

	size = count;
	
	//printing unsorted array
	printf("\n unsorted array : ");
	printArray(array, size);

	//performing bubble sort algorithm on array / sorting array using bubble sort algorithm
	bubbleSort(array, size);

	//printing sorted array
	printf("\n sorted array in ascending order : ");
	printArray(array, size);
	
	getch();
}
