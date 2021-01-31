#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Item;
#define exchange(p, q) {Item t; t=p; p=q; q=t;}


void sort(Item a[], int N)
{
	int i, j;
	bool flag = false;

	for (i = 0; i < N - 1; ++i)
	{
		flag = false;

		if (!flag) 
		{
			for (j = 0; j < N - i - 1; ++j)
				if (a[j] > a[j + 1])
				{
					flag = true;
					exchange(a[j], a[j + 1]);
				}
		}
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

	for (i = 0; i < N; ++i)
		printf("%d\n", a[i]);

	printf("\n\n\n");

	sort(a, N);

	for (i = 0; i < N; ++i)
		printf("%d\n", a[i]);

	return 0;
}