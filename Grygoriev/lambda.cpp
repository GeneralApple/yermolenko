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

	for (int i = 0; i<100; i++)
	{
		arr[i] = i;
	}

	for_each(arr, arr + 100, [rnd0](int n) {
		unsigned long int rnd = 1+ (rnd0* (1664525 << n) + 1013904223UL)%100;
		cout << rnd << endl;
	});

	system("pause");
	return 0;
}
