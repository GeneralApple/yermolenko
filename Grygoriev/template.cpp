// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
void sort(T *a, int i) {
	T b[i];
	bool c[i];

	int j, k, l, ind;

	for (j = 0; j<i; j++)  c[j] = 1;

	for (j = 0; j<i; j++) {
		k = 0;

		while (!c[k]) k++;
		ind = k;
		b[j] = a[k];

			for (l = k; l<i; l++) {
				if (a[l]>b[j] && c[l] == 1) {
					b[j] = a[l];
					ind = l;
				}
			}

		c[ind] = 0;
	}

	for (j = 0; j<i; j++) a[j] = b[j];

	for (j = 0; j<i; j++) cout << a[j] << " ";

	cout << endl;
}



int main()
{
	int i[] = { 3,1,7,-10,256 };
	sort(i, 5);

	double d[] = { 3.0, 2057.12537, -5685.5678, 0.0, 297.754 };
	sort(d, 5);

	char t[] = "Grygoriev";
	sort(t, 9);

	

	return 0;
}

