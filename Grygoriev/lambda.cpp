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
	int arr[1000];

	

	for_each(arr, arr + 1000, [rnd0,&arr](int n) {
		unsigned long int rnd = rnd0 * 1664525*n + 1013904223UL*n+1;
		arr[n-1] = 1+rnd%100
		//cout << 1+rnd%100 << endl;
	});
	
		for (int j = 0; j < 10; j++)
	{
		int result = count_if(arr, arr + 1000, [j,arr](int n) {
			return 10*j <= arr[n] && arr[n] < 10*(j+1);
		});
		cout << result << "     ";
	}

	system("pause");
	return 0;
}
