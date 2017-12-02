
#include "stdafx.h"
#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <algorithm>

using namespace std;

int main
{
	srand(time(0));
int rnd0 = 1 + rand() / 100;
int arr[10];

for (int i = 0; i<100; i++)
{
	arr[i] = i;
}

for_each(arr, arr + 100, [](int n) {
	unsigned long int rnd = rnd0* (1664525 << n) + 1013904223UL;
	cout << rnd<<endl;
});

int pause;
cin >> pause;
return 0;
}
