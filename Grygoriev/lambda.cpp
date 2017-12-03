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

	//cout << rnd0;
	int arr[1000];

	for(int i=0;i<1000;i++) arr[i]=i;
	
	int rnd[1000]
	
	

	for_each(arr, arr + 1000, [rnd0,&rnd](int n) {
		unsigned long int tmp = rnd0 * (1+1664524*n) + 1013904223UL*n;
		rnd[n] = 1+tmp%100;
		//cout << 1+tmp%100 << endl;
	});
	
		for (int j = 0; j < 10; j++)
	{
		int result = count_if(rnd, rnd + 1000, [j](int n) {
			return 10*j <= n && n < 10*(j+1);
		});
		cout << result << "     ";
	}

	system("pause");
	return 0;
}
