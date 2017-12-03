#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>


using namespace std;

int main()
{

	srand(time(0));
	unsigned long int rnd = 1 + rand() % 100;
	cout << rnd << endl;

	unsigned long int arr[1000];

	for (int i = 0; i<1000; i++)
	{
		rnd = rnd * 1664525 + 1013904223UL;
		arr[i] = 1 + rnd % 100;
		//cout << 1 + rnd % 100 << endl;
	}

	for (int j = 0; j < 10; j++)
	{
		int result = count_if(arr, arr + 1000, [j](int n) {
			return 10*j < n && n <= 10*(j+1);
		});
		cout << result << "     ";
	}

	system("pause");

	return 0;
}
