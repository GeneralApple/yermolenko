// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;
#define N 100


int main()
{

	int i, j, k;
	int **a, **b, **c;
	a = new int*[N];
	b = new int*[N];
	c = new int*[N];

	for (int r = 0; r<N; r++)
	{
		a[r] = new int[N];
		b[r] = new int[N];
		c[r] = new int[N];
	}

	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++)
			a[i][j] = b[i][j] = i*j;

	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			c[i][j] = 0;
			for (k = 0; k<N; k++) c[i][j] += a[i][k] * b[k][j];
		}
	}
	int t = clock();
	cout << t;
	int pause;
	cin >> pause;
    return 0;
}

