#include "stdafx.h"
#include <iostream>
#include <ctime>

int partition(int A[], int p, int q){
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j<q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			std::swap(A[i], A[j]);
		}

	}

	std::swap(A[i], A[p]);
	return i;
}

void quickSort(int A[], int p, int q) {
	int r;
	if (p<q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}

int main(){
	const int size = 200000;
	int a[size];
	int start_time;
	int search_time;

	for (int i = 0; i < size; i++)
	{
		a[i] = rand();
	}

	start_time = clock();
	quickSort(a, 0, size - 1);
	search_time = clock() - start_time;

	std::cout << search_time << "\n";

	system("PAUSE");
	
    return 0;
}

