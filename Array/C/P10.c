//practical 10
//write a program to input n elements in one dimensional array
//and sort them using quick sort algorithm
//display sorted array

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

// finding the partition position
int partition(int array[], int lower, int upper)
{
	// select the rightmost element as pivot
	int pivot = array[upper];

	// pointer for greater element
	int i = lower;
	
	int j;

	// traverse each element of the array and compare them with the pivot
	for(j = lower ; j < upper ; j++)
	{
		if(array[j] <= pivot)
		{
			// if element smaller than pivot is found
			// swap it with the greater element pointed by i
			
			// swap element at i with element at j
			swap(&array[i], &array[j]);
			
			i++;
		}
	}

	// swap the pivot element with the greater element at i
	swap(&array[i], &array[upper]);

	// return the partition point
	return i;
}

//quick sort algorithm
void quickSort(int array[], int lower, int upper)
{
	int pivot;
	
	if(lower < upper)
	{
		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on right of pivot
		pivot = partition(array, lower, upper);
    
		// recursive call on the left of pivot
		quickSort(array, lower, pivot - 1);

		// recursive call on the right of pivot
		quickSort(array, pivot + 1, upper);
	}
}

//print array elements
void printArray(int array[], int size)
{
	int i;
	for(i = 0 ; i < size ; i++)
	{
		printf("\n %d %d",i,array[i]);
	}
}

//main function
void main()
{
	int data[] = {8, 17, 21, 1, 0, 9, 6, 20, 15, 13, 12, 2, 10, 8, 16, 4, 5, 3, 11, 14, 7, 18, 19};

	int size = sizeof(data) / sizeof(data[0]);

	//clrscr();
	
	printf("\n unsorted array : ");
	printArray(data, size);

	//perform quicksort on data
	quickSort(data, 0, size - 1);

	printf("\n sorted array in ascending order : ");
	printArray(data, size);
	
	getch();
}
