#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;

int main()
{

	srand(time(0));
	unsigned long int rnd = 1 + rand() % 100;
	cout << rnd << endl;

	unsigned long int arr[100000];

		for (int i = 0; i<100000; i++)
		{
			rnd = rnd * 1664525 + 1013904223UL;
			arr[i] = 1 + rnd % 100;
			//cout << 1 + rnd % 100 << endl;
		}
	
	for(int j = 0; j < 100; j++)
	{
	int result = count_if(arr, arr + 100000, [j](int n) {
		return j<=n && n< j+ 1000;
		});
		cout << result;<<endl
	}

		system("pause");

	return 0;
}
