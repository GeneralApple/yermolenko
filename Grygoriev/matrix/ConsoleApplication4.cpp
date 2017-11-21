// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;
#define N 10000


int main()
{

	int i, j, k;
	double **a, **b, **c;
	a = new double*[N];
	b = new double*[N];
	c = new double*[N];

	for (int r = 0; r<N; r++)
	{
		a[r] = new double[N];
		b[r] = new double[N];
		c[r] = new double[N];
	}

	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++)
			a[i][j] = b[i][j] = i*j;

	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			c[i][j] = 0;
			for (k = 0; k < N; k++) {
				c[i][j] += a[i][k] * b[k][j];
				cout << c[i][j];
			}
		}
	}
	int t = clock();
	cout << t;
	int pause;
	cin >> pause;
    return 0;
}

