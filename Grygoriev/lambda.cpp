#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(0)); // автоматическая рандомизация
	int rnd0 = 1 + rand() % 100;

	cout << rnd0;
	int arr[10];

	for (int i = 0; i<10; i++)
	{
		arr[i] = i;
	}

	for_each(arr, arr + 10, [rnd0](int n) {
		unsigned long int rnd = rnd0 * 1664525*(n+1) + 1013904223UL*(n+1);
		cout << 1+rnd%100 << endl;
	});

	system("pause");
	return 0;
}
