#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Item;
#define key(p) (p)
#define exchange(p, q) {Item t; t=p; p=q; q=t;}
#define less(p, q) (key(p) < key(q))
#define compexch(p, q) if(less(q, p)) exchange(p, q)
// using macros instead of functions so that these can be reused for different data types


void bubble_sort(Item a[], int l, int r)
{
	// TO-DO: OPTIMISE LIKE ADAPTIVE INSERTION SORT!!!

	// a simple bubble sort implementation
	// kinda optimised

	int i, j;
	bool flag = false;

	for (i = l; i < r - 1; ++i)
	{
		flag = false;

		if (!flag) 
		{
			for (j = l; j < r - i - 1; ++j)
				if (a[j] > a[j + 1])
				{
					flag = true;
					exchange(a[j], a[j + 1]);
				}
		}
	}
}

void selection_sort(Item a[], int l, int r)
{
	// SELECTION SORT

	/*
		- selection sort compares the rest of the elements w the first element and exchanges the first element w the smallest available one.
		- and then the second one with the smallest in the rest of the array.
		- and so on.
	*/

	/*
		Selection sort is so called because in each iteration of the outer loop, the smallest element from the remaining unsorted array is SELECTED
		to be exchanged with the first element of the unsorted section.
	*/

	// N-1 exchanges because the last element doesnt need to be exchanged.
	// Runtime proportional to N^2.

	int i, j, minIndex; // minIndex to hold the index of the smallest item.

	for (i = l; i < r; ++i)
	{
		minIndex = i;

		for (j = i + 1; j < r; ++j)
			if (a[j] < a[minIndex]) 
				minIndex = j;
	
		exchange(a[i], a[minIndex]);
	}

	// CONS:
	/*
		* When making a pass through the array, we still dont know where the next min element might be.
		* It takes almost the same time to sort an array that is already sorted
		* or an array which has equal elements
		* as an unsorted array.	
	*/
	// PROS:
	/*
		* Works better than most algorithms
		* when the items are large and the keys are small
		* In such cases the cost of making comparisons is lesser than the
		* cost of moving data
	*/

}


void insertion_sort(Item a[], int l, int r)
{
	// insertion sort algo comes here

	int i, j;

	// this is the basic non-adaptive insertion sort
	/*
	for (i = l + 1; i < r; ++i)
		for (j = i; j > l; --j)
			compexch(a[j - 1], a[j]);     
	*/

	// better, and nearly two times faster, adaptive insertion sort

	for (i = l + 1; i < r; ++i) compexch(a[l], a[i]);

	for (i = l + 2; i < r; ++i) // i=l+2 since a[l] is sentinel
	{
		j = i;
		Item current = a[i];

		while (less(current, a[j]))
		{
			a[j] = a[j - 1]; // instead of exchanging, we simply shift the larger element rightwards
			--j;
		}
		a[i] = current;
	}

}

int main(int argc, char* argv[])
{
	int i, N = atoi(argv[1]), method = atoi(argv[2]);
	int* a = (int*)malloc(sizeof(int) * N);

	if (method) // randomly fill array
		for (i = 0; i < N; ++i)
			a[i] = 1000 * (1.0 * rand() / RAND_MAX);  // greater chance of repetition
	else // user i/p via stdin
		while (scanf("%d", &a[N]) == 1) ++N;

	// TO-DO: REFINE USER ENTERED INPUT.

	for (i = 0; i < N; ++i)
		printf("%d\n", a[i]);

	printf("\n\n\n");

	insertion_sort(a, 0, N);

	for (i = 0; i < N; ++i)
		printf("%d\n", a[i]);

	return 0;
}